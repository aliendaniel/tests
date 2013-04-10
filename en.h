//------------------------------
//create time:2012-12-26
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:�������Լ���
//------------------------------
#ifndef _EN_H
#define _EN_H
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include "../cmdif/basecmd.h"
typedef std::vector<int> tp_vi;
/*
using namespace std;
//typedef list<top_score> tp_lt;
typedef set<int> tp_si;

//class c_global_sql;
//class c_mysql;
class c_gas; //����
class c_bc; //�䶯�㲥
class c_conf; //����
class c_gfun; //ͨ�ú�����
class c_cinfo; //����Ϣ
*/
class c_level;
class c_userlist; //����
class c_broadcastlist;
class c_cmdif; //ָ��ӿ�
class c_en :public c_basecmd //: public c_observer
{
public:
	static c_en* instance(void); //ȡΩһʵ��(ȡ������)
	void release(void); //ȡ����������
	int cmd(int room,int cli,int cmd,const char *arg); //ָ��	

	void tests(void);
protected:
	c_en(void);
	~c_en(void);
private:
	static  c_en* _instance;
	int ref_count; //�����ü���
	int roomen; //�����
	std::stringstream ss;  //��ʱ�ַ�����ʽ��
	bool blnrun; //�Ƿ�����
	int pool; //�ʳ�
	int nowno; //��ǰ��Ŀ�ʺ�
	tp_vi vi_opt; //ѡ��
	struct tp_sit{
		int u; //�û�ID
		int money; //����
	}; //��λ
	const static int NUM_SIT = 5; //��λ��
	typedef std::vector<tp_sit> tp_vs;
	tp_vs vs_sits; //��λ��
	/*
	int max_userlv; //�û��ȼ�����
	tp_si si_att; //���������Դ���
	c_gas *p_gas; //����
	c_bc *p_bc; //�䶯�㲥����
	c_conf *p_conf; //����
	c_gfun *p_gfun; //ͨ�ú���
	c_cinfo *p_cinfo; //����Ϣ
	*/
	c_level *p_level; //��Ϣ��ȡ
	c_userlist *p_ul; //�����û��б�
	c_broadcastlist *p_bl; //�㲥
	c_cmdif *p_if; //ָ��ӿ�

	void inroom(int cli); //����
	void outroom(int cli); //����
	void bc_init(int cli); //�㲥��ʼ������Ϣ
	void req_down(int cli,const char *); //����
	void rsp_down(int cli,int no); //������Ӧ
	void bc_sitinfo(int no); //��λ��Ϣ
	void req_up(int cli,const char *arg); //վ��
	void clear_sit(int no); //����
	void click(); //ѡ��

	//�̰߳�ȫ����,2013-4-9,��δ���
	int tsf_set_sit(int no,int tp,int v){if(1==tp){vs_sits[no].u=v;}else{vs_sits[no].money=v;}}
	int tsf_sit_uid(int no){return vs_sits[no].u;}
	int tsf_sitbyuid(int u); //����uid����λ��
	int tsf_enough(int u); //�û�Ǯ�Ƿ�
	int tsf_user2sit(int u,int no); //�û�Ǯ������
	int tsf_sit2user(int no,int u); //����Ǯ���û�
	void tsf_down(int no,int u){vs_sits[no].u=u;} //����

	inline int get_ref(void) const { return ref_count;}
	inline void add_ref(void){ ++ ref_count;}
	inline void sub_ref(void){ -- ref_count;}

};
#endif
