//------------------------------
//create time:2011-6-8
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:�㲥վ��֪ͨ����
//------------------------------
#ifndef _CMDIF_H
#define _CMDIF_H
#include <map>
//#include <set>
#include "basecmd.h"
//using namespace std;
typedef std::map<int,c_basecmd *> tp_ic;

class c_cmdif
{
	//��̨
public:
	static c_cmdif* instance(void); //ȡΩһʵ��(ȡ������)
	void release(void); //ȡ����������
	void attach(int,c_basecmd *); //����
	void detach(int); //�˶�
	int notify(int,int,int,const char *); //֪ͨ�ӿ�:����,ֵ(-1Ĭ��)
protected:
	c_cmdif();
	~c_cmdif();
private:
	static c_cmdif* _instance;
	int ref_count; //�����ü���
	tp_ic mp; //�����б�

	inline int get_ref(void) const { return ref_count;}
	inline void add_ref(void){ ++ ref_count;}
	inline void sub_ref(void){ -- ref_count;}
};


#endif


