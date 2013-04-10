//------------------------------
//create time:2012-8-21
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:ͨ������
//------------------------------
#include <iostream>
#include <cassert>
#include "en.h"
//#include "../include/class_mysql.h"
//#include "../global_sql/global_sql.h"
#include "log_writer.h"
#include "../level/level.h"
#include "../gas/gas.h"
#include "../bc/bc.h"
#include "../class_userlist.h"
#include "../conf/conf.h"
#include "gfun.h"
#include "../map/cinfo.h"
#include "../class_broadcastlist.h"
#include "../cmdif/cmdif.h"
#include "tm.h"
#include <algorithm>
using namespace std;
const int NUM_OPT = 4; //ѡ����
//const int NUM_SIT = 5; //��λ��
const int MIN_SITMONEY = 20; //��С����Ǯ
const int MAX_SITMONEY = 100; //�������Ǯ
const int SIG_MONEY = 1; //��ע
const int CLICK_MONEY = 10; //ѡ������
const int NUM_CARD = 80; //����
//const int TM_TOP = 3600; //ÿСʱ��������
//const int NUM_TOP = 10; //ǰn���н�
//bool is_eque(top_score a,int u){return (a.u==u);}
//bool is_lit(top_score a,top_score b){return (a.v<b.v && a.u!=b.u);}
void _tm_en(void* ptr)
{
	AF *pa = static_cast<AF *>(ptr); // ǿ��ת�� p Ϊ A* 
	c_en *ph = pa->p; // ��A����ȡHack�����ַ
	void (c_en::*pmf)(void)=pa->pmf; //��ȡ ptr ����Ա����
	(ph->*pmf)(); // ���ó�Ա����
}

c_en* c_en::_instance = NULL;
c_en* c_en::instance(void)
{
	if(NULL == _instance){_instance = new c_en;}
	_instance->add_ref();
	return _instance;
}
void c_en::release(void)
{
	sub_ref();
	if(get_ref() > 0){return;}
	delete _instance;
	_instance = NULL;
}
c_en::c_en(void):ref_count(0),roomen(534),pool(0),nowno(0),blnrun(false)
{
	vi_opt.reserve(NUM_OPT);
	vi_opt.resize(NUM_OPT,-1);
	vs_sits.reserve(NUM_SIT);
	vs_sits.resize(NUM_SIT);
	vi_ls.reserve(NUM_CARD);
	/*
//	p_gsql = c_global_sql::instance();
//	p_sql = p_gsql->get_sql();
	p_gas = c_gas::instance();
	p_bc = c_bc::instance();
	p_conf = c_conf::instance();
	p_gfun = c_gfun::instance();
	p_cinfo = c_cinfo::instance();
	*/
	p_level = c_level::instance();
	p_ul = c_userlist::instance();
	p_bl = c_broadcastlist::instance();
	p_if = c_cmdif::instance();
	p_if->attach(2063,this); //����
	p_if->attach(2065,this); //�˷�
	p_if->attach(2067,this); //����
	p_if->attach(2071,this); //վ��
	p_if->attach(2079,this); //����
	p_tm = c_tm::instance();
	a1.p = this;
	a1.pmf = &c_en::ques;
	no_tm = p_tm->reg_cb(&_tm_en,&a1);
	
	//tests();
}
c_en::~c_en(void)
{
	assert(-1!=no_tm);
	p_tm->cancel_cb(no_tm);
	no_tm = -1;
	p_tm->release();
	p_if->detach(2079);
	p_if->detach(2071);
	p_if->detach(2067);
	p_if->detach(2065);
	p_if->detach(2063);
	p_if->release();
	p_bl->release();
	p_ul->release();
	p_level->release();
	/*
	p_cinfo->release();
	p_gfun->release();
	p_conf->release();
	p_bc->release();
	p_gas->release();
//	p_sql = NULL;
//	p_gsql->release();
	*/
}
void c_en::tests(void)
{
	//����
	//����:��
	//���:��
	cerr << "Ӣ����˷�����" << endl;
	req_down(123,"0");
	rash();
	print(vi_ls);
	ques();
}
int c_en::tsf_sitbyuid(int u)
{
	//����uid����λ��
	//����:u�û�
	//����:��λ��,-1����λ
	if(u<1){return -1;}
	for(int i =0;i<NUM_SIT;++i){
		if(u==vs_sits[i].u){return i;}
	}
	return -1;
}
int c_en::tsf_enough(int u)
{
	//�û�Ǯ�Ƿ�
	//����:u�û�
	//����:0Ǯ����,>0����Ǯ��
	int v = p_level->get_vals(15,u);
	if(v<MIN_SITMONEY){return 0;}
	return (v>=MAX_SITMONEY)?MAX_SITMONEY:MIN_SITMONEY;
}
int c_en::tsf_sit2user(int no,int u)
{
	//����Ǯ���û�
	//����:no����,u�û�
	//����:0�ɹ�,-1ʧ��
	if(vs_sits[no].money<1){return -1;}
	int v = p_level->get_vals(15,u);
	v += vs_sits[no].money;
	p_level->set_vals(15,u,v);
	vs_sits[no].money = 0;
	return 0;
}
int c_en::tsf_user2sit(int u,int no)
{
	//�û�Ǯ������
	//����:u�û�,no����
	//����:0�ɹ�,-1ʧ��
	p_level->set_vals(15,u,MAX_SITMONEY*100);
	int v = p_level->get_vals(15,u);
	if(v<MIN_SITMONEY){return -1;}
	int sub = (v>=MAX_SITMONEY)?MAX_SITMONEY:MIN_SITMONEY;
	p_level->set_vals(15,u,(v-sub));
	vs_sits[no].money = sub;
	return 0;
}
void c_en::req_up(int cli,const char *arg)
{
	//վ��
	//����:cli�ͻ�,arg��λ��
	//����:��
	//cout << "c_en::req_up,cli=" << cli << ",arg=" << arg << endl;
	int ruid = p_ul->uidbycid(cli);
	if(ruid<1){return;}
	//cout << "req_up,111" << endl;
	int no = atoi(arg);
	//λ���Ƿ����
	if(no<0 || no>=NUM_SIT){return;}
	//cout << "req_up,222" << endl;
	//��λ�Ƿ�����
	//�������Ƿ���Щ��λ
	if(tsf_sit_uid(no)!=ruid){return;}
	//cout << "req_up,333" << endl;
	//����
	clear_sit(no);
}
void c_en::clear_sit(int no)
{
	//����
	//����:no����
	//����:��
	//ǰ�ñ�֤no��Ч
	int u = tsf_sit_uid(no);
	//cout << "req_up,clear_sit,no=" << no << ",u=" << u << endl;
	//תǮ������
	if(0!=tsf_sit2user(no,u)){return;}
	//cout << "req_up,444" << endl;
	//��λ���
	tsf_set_sit(no,1,0);
	tsf_set_sit(no,2,0);
	//cout << "req_up,555" << endl;
	//״̬�ź�
	tsf_up_state();
	//�㲥���ŵ�����
	int cli = p_ul->cidbyuid(u);
	//cout << "req_up,666" << endl;
	//rsp_down(cli,no);
	rsp_down(cli,-1);
	//�㲥��λ��Ϣ������
	bc_sitinfo(no);
}
void c_en::req_down(int cli,const char *arg)
{
	//����
	//����:cli�ͻ�,arg��λ��:0-4
	//����:��
	//cout << "req_down,cli=" << cli << endl;
	int ruid = p_ul->uidbycid(cli);
	if(ruid<1){return;}
	//cout << "req_down,111" << endl;
	int no = atoi(arg);
	//λ���Ƿ����
	if(no<0 || no>=NUM_SIT){return;}
	//cout << "req_down,222" << endl;
	//λ���Ѿ�����
	if(tsf_sit_uid(no)>0){return;}
	//cout << "req_down,333" << endl;
	//�������Ƿ��ڷ���,��
	//�������Ƿ�������
	if(-1!=tsf_sitbyuid(ruid)){return;}
	//cout << "req_down,444" << endl;
	//�������Ƿ��ж���//�ƶ���
	if(0!=tsf_user2sit(ruid,no)){return;}
	//cout << "req_down,555" << endl;
	//����
	tsf_down(no,ruid);
	//״̬�ź�
	tsf_up_state();
	//�㲥�����Ϣ��������
	rsp_down(cli,no);
	//�㲥��λ��Ϣ������
	bc_sitinfo(no);
}
void c_en::inroom(int cli)
{
	//����
	//����:cli�ͻ�
	//���:��
	p_ul->set_room(cli,roomen);
	int ruid = p_ul->uidbycid(cli);
	int mysit = tsf_sitbyuid(ruid);
	rsp_down(cli,mysit);
	bc_init(cli);
}
void c_en::outroom(int cli)
{
	//����
	//����:cli�ͻ�
	//���:��
	p_ul->set_room(cli,0);
	//cout << "c_en::outroom,cli=" << cli << endl;
}
void c_en::bc_sitinfo(int no)
{
	//��λ��Ϣ
	//����:no����
	//����:��
	std::stringstream stmp;  //��ʱ�ַ�����ʽ��
	stmp.str("");
	stmp.clear();
	string tmp;
	p_level->get_name(vs_sits[no].u,tmp);
	stmp << no << "," << vs_sits[no].money << "," << tmp;
	p_bl->add_bc(4,roomen,2070,stmp.str().c_str(),roomen); //����	
}
void c_en::bc_pool(void)
{
	//�ʳ���Ϣ�㲥
	//����:��
	//����:��
	std::stringstream stmp;  //��ʱ�ַ�����ʽ��
	stmp.str("");
	stmp.clear();
	stmp << pool;
	p_bl->add_bc(4,roomen,2074,stmp.str().c_str(),roomen); //����	
}
void c_en::bc_sitmoney(int no)
{
	//��λǮ�㲥
	//����:no��λ�±�
	//����:��
	assert((no>=0 && no<vs_sits.size()));
	std::stringstream stmp;  //��ʱ�ַ�����ʽ��
	stmp.str("");
	stmp.clear();
	stmp << no << "_" << vs_sits[no].money;
	p_bl->add_bc(4,roomen,2078,stmp.str().c_str(),roomen); //����	
}
void c_en::bc_sitmoney(void)
{
	//��λǮ�㲥
	//����:��
	//����:��
	std::stringstream stmp;  //��ʱ�ַ�����ʽ��
	stmp.str("");
	stmp.clear();
	for(int i = 0;i<vs_sits.size();++i){
		if(vs_sits[i].u<1){continue;}
		if(!stmp.str().empty()){stmp << ",";}
		stmp << i << "_" << vs_sits[i].money;
	}
	p_bl->add_bc(4,roomen,2078,stmp.str().c_str(),roomen); //����	
}
void c_en::bc_ques(void)
{
	//��Ŀ�㲥
	//����:��
	//����:��
	std::stringstream stmp;  //��ʱ�ַ�����ʽ��
	stmp.str("");
	stmp.clear();
	stmp << nowno;
	for(int i = 0;i<vi_opt.size();++i){
		stmp << "," << vi_opt[i];
	}
	p_bl->add_bc(4,roomen,2076,stmp.str().c_str(),roomen); //����	
}

void c_en::rsp_down(int cli,int no)
{
	//������Ӧ
	//����:cli�ͻ�,no����
	//����:��
	std::stringstream stmp;  //��ʱ�ַ�����ʽ��
	stmp.str("");
	stmp.clear();
	stmp << no;
	p_bl->add_bc(1,cli,2068,stmp.str().c_str(),0); //˽��
}
void c_en::bc_init(int cli)
{
	//�㲥��ʼ������Ϣ
	//����:cli�ͻ�
	//���:��
	ss.str("");
	ss.clear();
	//�ʳ�
	ss << pool << "`|" << nowno;
	//��Ŀ
	for(int i=0;i<NUM_OPT;++i){
		ss << "," << vi_opt[i];
	}
	//��λ��
	ss << "`|";
	string tmp;
	for(int i=0;i<NUM_SIT;++i){
		if(0!=i){ss << ";";}
		tmp = string();
		p_level->get_name(vs_sits[i].u,tmp);
		ss << i << "," << vs_sits[i].money << "," << tmp;
	}
	//ss << u << "," << k << "," << next;
	p_bl->add_bc(1,cli,2064,ss.str().c_str(),0); //˽��

}
void c_en::ques(void)
{
	//����//��ʱ������
	//����:��
	//����:��
	//cout << "c_en::ques" << endl;
	//����������
	if(!blnrun){return;}
	//��������λ��ע
	//��עʧ�ܣ��߳�
	int count = 0;
	for(int i=0;i<NUM_SIT;++i){
		if(vs_sits[i].u<1){continue;}
		if(vs_sits[i].money<SIG_MONEY){
			clear_sit(i);
			continue;
		}
		vs_sits[i].money-=SIG_MONEY;		
		count += SIG_MONEY;
	}
	//cout << "count=" << count << endl;
	//ע���ϼ��Ƿ�Ϊ0
	if(count<1){return;}
	//��ע���ʳ�
	pool += count;
	//ȡ��Ŀ��ѡ��
	if(vi_ls.size()<NUM_OPT){rash();}
	vi_opt.clear();
	for(int i=0;i<NUM_OPT;++i){
		vi_opt.push_back(vi_ls.back());
		vi_ls.pop_back();
	}
	//����Ŀ
	srand((unsigned int)time(NULL));
	nowno = vi_opt[rand()%NUM_OPT];
	//��մ����ʶ
	si_ed.clear();
	//�㲥�ʳص�����
	bc_pool();
	//�㲥��Ŀ����
	bc_ques();
	//�㲥��λǮ����
	bc_sitmoney();
	//cout << "end,nowno=" << nowno << endl;
}
void c_en::rash(void)
{
	//ϴ��һ����
	//����:��
	//����:��
	srand((unsigned int)time(NULL));
	for(int i =0;i<NUM_CARD;++i){
		vi_ls.push_back(i);
	}

	//����
	int key,val;
	for(int i =0;i<vi_ls.size();++i){
		key = rand()%NUM_CARD;
		val = vi_ls[key];
		vi_ls[key] = vi_ls[i];
		vi_ls[i] = val;
	}
}
void c_en::print(tp_vi &tmp)
{
	for(int i=0;i<tmp.size();++i){
		cout << tmp[i] << ",";
	}
	cout << endl;
}
void c_en::tsf_up_state(void)
{
	//ˢ������״̬
	//����:��
	//����:��
	for(int i=0;i<NUM_SIT;++i){
		if(vs_sits[i].u>0){
			blnrun = true;
			return;
		}
	}
	blnrun = false;
}
void c_en::click(int cli,int no)
{
	//����
	//����:cli�ͻ�,noѡ���±�(0-3)
	//����:��
	if(no<0 || no>=NUM_OPT){return;}
	//����������
	if(!blnrun){return;}
	//�Ѵ��
	if(-1==nowno){return;}
	//�û���Ч
	int ruid = p_ul->uidbycid(cli);
	if(ruid<1){return;}
	//������λ�û�
	int mysit = tsf_sitbyuid(ruid);
	if(-1==mysit){return;}
	//�����Ѵ�
	if(si_ed.end()!=si_ed.find(ruid)){return;}
	//������ʶ
	si_ed.insert(ruid);
	//�ʳر䶯����
	bool blnpool = false;
	//�Ƿ�ѡ��
	int need = pool>CLICK_MONEY?CLICK_MONEY:pool;
	int v = vs_sits[mysit].money; //p_level->get_vals(15,ruid);
	//��Ǯ
	if(v>=need){
		blnpool = true;
		pool += need;
		v -= need;
		vs_sits[mysit].money = v; //p_level->set_vals(15,ruid,v);
	}
//	//��ȷ�ʺ�
//	int word = vi_opt[no];
	//�Ƿ���ȷ
	//��ȷ����Ǯ,����-1
	bool blnok = false; //�Ƿ���
	if(blnpool && nowno==vi_opt[no]){
		blnok = true;
		vs_sits[mysit].money += pool;
		pool = 0;
		nowno = -1;
	}
	if(blnpool){
		//�㲥�ʳص���
		bc_pool();
		//��λǮ����
		bc_sitmoney(mysit);
	}
	//ѡ��ͽ������
	bc_click(blnok,mysit,no);
}
void c_en::bc_click(bool bln,int sit,int no)
{
	//�㲥���
	//����:bln���,sit��λ��0-4,noѡ��0-3
	std::stringstream stmp;  //��ʱ�ַ�����ʽ��
	stmp.str("");
	stmp.clear();
	stmp << (bln?"Y":"N") << "," << sit << "," << no;
	p_bl->add_bc(4,roomen,2080,stmp.str().c_str(),roomen); //����	
}
int c_en::cmd(int room,int cli,int cmd,const char *arg)
{
	//ָ��
	//����:room����,cli�ͻ�,cmdָ��,arg����
	//���:0�ɹ�/-1ʧ��
	//cout << "c_reg::cmd,room=" << room << ",cli=" << cli << ",cmd=" << cmd << ",arg=" << arg << endl;
	switch(cmd){
	case 2063: //����
		inroom(cli);
		break;
	case 2065: //����
		outroom(cli);
		break;
	case 2067: //����
		req_down(cli,arg);
		break;
	case 2071: //վ��
		req_up(cli,arg);
		break;
	case 2079: //����
		click(cli,atoi(arg));
		break;
	default:
		break;
	}
	return 0;
}





