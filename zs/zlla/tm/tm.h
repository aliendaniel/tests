//------------------------------
//create time:2012-7-23
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:��ʱ��
//------------------------------
#ifndef _TM_H
#define _TM_H
//#include "../netdef.h"
//#include <string>
//#include <sstream>
#include <vector>
//�������
//֪ͨ
class c_mutex;
typedef void (*pf)(void *); //����ָ��
struct tm_task_t{
	pf p; //����ָ��
	void *arg; //����
};
//typedef std::vector<tm_task_t> tp_vt; 
class c_tm
{
public:
	static c_tm* instance(void); //ȡΩһʵ��(ȡ������)
	void release(void); //ȡ����������
	void run(int); //����ʱ��
	inline c_mutex *get_mt_tm(void){return mt_tm;} //��ʱ��
	int reg_cb(void (*func)(void *),void* ptr); //ע��ص�������ע��������
	void cancel_cb(int no); //ȡ������
	
	void tests(void);
protected:
	c_tm(void);
	~c_tm(void);
private:
	static c_tm* _instance;
	int ref_count; //�����ü���
	int tm_ct;
	int _fd; //�հ��׽���
	c_mutex *mt_tm;
	bool blnrun;
	pf pmf;
	void *pf_arg;
	typedef std::vector<tm_task_t> tp_vt; 
	tp_vt vc_task; //�����

	int empty_sock(void); //����sock����
	int no_empty(void); //�������±�
	void run_task(void); //���������

	inline int get_ref(void) const { return ref_count;}
	inline void add_ref(void){ ++ ref_count;}
	inline void sub_ref(void){ -- ref_count;}

};
#endif
