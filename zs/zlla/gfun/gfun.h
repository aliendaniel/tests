//------------------------------
//create time:2012-1-20
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:���ú�����
//------------------------------
#ifndef _GFUN_H
#define _GFUN_H
#include <sstream>
#include <map>
#include <vector>
#include <set>
//#include "../include/frand.h"
typedef std::vector<std::string> tp_vs;
typedef std::set<int> tp_si;
typedef std::map<int,int> tp_ii;
typedef std::vector<int> tp_vi;
class c_gfun
{
public:
	static c_gfun* instance(void); //ȡΩһʵ��(ȡ������)
	void release(void); //ȡ����������

	int split_str(const char * const,char); //����ַ���
	int get_val(void); //ȡ�б�ֵ
	const char * get_str(void); //ȡ�б�ֵ�ַ���
	const char * join(tp_si &,char); //��������б�
	const char * join(tp_vi &,char); //��������б�
	//inline int get_rand(void){return ra.rand();} //�����
	void split_str(const char *,std::string &,tp_vs &); //����ַ���

	void tests(void);
protected:
	c_gfun(void);
	~c_gfun(void);
private:
	static c_gfun* _instance;
	int ref_count; //�����ü���
	std::stringstream ss;  //��ʱ�ַ�����ʽ��
	tp_vs lsre; //�ַ����б�
	int nore; //�б�ĵ�ǰ�±�
	//�������������ͬ�෽ʽ����������Ĭ�ϲ���Ϊ��16807������
	//randomizer ra; 

	inline int get_ref(void) const { return ref_count;}
	inline void add_ref(void){ ++ ref_count;}
	inline void sub_ref(void){ -- ref_count;}

};
#endif
