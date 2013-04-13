//------------------------------
//create time:2011-6-8
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:�㲥վ��֪ͨ����
//------------------------------
#include "station.h"
#include <iostream>
#include <ctime>
#include "../log_writer/log_writer.h"
//#include <fstream>
//using namespace std;
//-------------------c_station------------
c_station* c_station::_instance = NULL;
c_station* c_station::instance(void)
{
	//ȡΩһʵ��(ȡ������)
	//cerr << "c_station::instance" << endl;
	if(NULL == _instance)
		_instance = new c_station();
	_instance->add_ref();
	return _instance;
}
void c_station::release(void)
{
	//ȡ����������
	//cerr << "c_station::release,ref_count=" << ref_count << endl;
	sub_ref();
	//cerr << "sub_ref=" << ref_count << endl;
	if(get_ref() > 0)
		return;
	//cerr << "delete _instance" << endl;
	delete _instance;
	_instance = NULL;
}
c_station::c_station()
{
	//cerr << "c_station" << endl;
	ref_count = 0;
	ls.clear();
}
c_station::~c_station()
{
	//cerr << "~c_station" << endl;
}
void c_station::attach(int t,c_observer *p)
{
	//����
	if(ls.end()==ls.find(t)){
		tp_obs tmp;
		ls.insert(tp_io::value_type(t,tmp));
	}
	if(ls[t].end()==ls[t].find(p))
		ls[t].insert(p);
}
void c_station::detach(int t,c_observer *p)
{
	//�˶�
	assert(ls.end()!=ls.find(t));
	assert(ls[t].end()!=ls[t].find(p));
	ls[t].erase(p);
}
void c_station::notify(int t,int val)
{
	//֪ͨ
	if(ls.end()==ls.find(t))
		return;
	if(ls[t].empty())
		return;	
//	time_t ts = time(NULL);
	//cerr << "--------------notify start,t=" << t << ",val=" << val << endl;
	tp_obs::iterator it;
	for(it = ls[t].begin();it != ls[t].end();++it)
		(*it)->update(t,val);
//	int tc = (int)difftime(time(NULL),ts);
//	if(tc>2)
//		FLOG << "station��ʱ,t=" << t << ",val=" << val << ",tc="<< tc << endl;
	//cerr << "--------------notify end,t=" << t << ",val=" << val << endl;
}

