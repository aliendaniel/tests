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
#include <algorithm>
using namespace std;
const int NUM_OPT = 4; //ѡ����
//const int NUM_SIT = 5; //��λ��
const int MIN_SITMONEY = 20; //��С����Ǯ
const int MAX_SITMONEY = 100; //�������Ǯ
//const int TM_TOP = 3600; //ÿСʱ��������
//const int NUM_TOP = 10; //ǰn���н�
//bool is_eque(top_score a,int u){return (a.u==u);}
//bool is_lit(top_score a,top_score b){return (a.v<b.v && a.u!=b.u);}
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
	vi_opt.resize(NUM_OPT,-1);
	vs_sits.resize(NUM_SIT);
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
	//tests();
}
c_en::~c_en(void)
{
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
}
int c_en::tsf_sitbyuid(int u)
{
	//����uid����λ��
	//����:u�û�
	//����:��λ��,-1����λ
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
	//p_level->set_vals(15,u,MAX_SITMONEY);
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
	//״̬�ź�,��
	//�㲥���ŵ�����
	int cli = p_ul->cidbyuid(u);
	//cout << "req_up,666" << endl;
	rsp_down(cli,no);
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
	//״̬�ź�,��
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
	default:
		break;
	}
	return 0;
}





