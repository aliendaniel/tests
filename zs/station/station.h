//------------------------------
//create time:2011-6-8
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:�㲥վ��֪ͨ����
//------------------------------
#ifndef C_STATION_H
#define C_STATION_H
#include <map>
#include <set>
#include "observer.h"
using namespace std;
typedef set<c_observer *> tp_obs;
typedef map<int,tp_obs> tp_io;

class c_station
{
	//��̨
public:
	static c_station* instance(void); //ȡΩһʵ��(ȡ������)
	void release(void); //ȡ����������
	void attach(int,c_observer *); //����
	void detach(int,c_observer *); //�˶�
	void notify(int,int); //֪ͨ�ӿ�:����,ֵ(-1Ĭ��)
protected:
	c_station();
	~c_station();
private:
	static c_station* _instance;
	int ref_count; //�����ü���
	tp_io ls; //�����б�

	inline int get_ref(void) const { return ref_count;}
	inline void add_ref(void){ ++ ref_count;}
	inline void sub_ref(void){ -- ref_count;}
};


#endif


