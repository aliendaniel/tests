//------------------------------
//create time:2011-6-8
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:�۲���,������
//����һ���۲���7��---------------��סҪ�ھ���۲��߶�����ʵ��update�ӿ�
//1.��.h�ļ�������������class c_ref; //������1
//2.��.h�ļ���̬���캯��������c_observer(c_ref * const);
//3.��.h�ļ�����������c_ref *p_ref;
//4.��.h�ļ�������ʼΪNULLֵ��init(void)
//5.��.cpp�ļ�����ͷ�ļ���#include "../class_gameserver.h";
//6.��.cpp�ļ���̬����ʵ����c_observer(c_ref * const p){init();p_ref=p;}
//7.��.cpp�ļ��ӿڹ�����update(int t,int val)
//------------------------------
#ifndef C_OBSERVER_H
#define C_OBSERVER_H
//#include <stdio.h>

//class c_ref; //������1
//class c_res; //������2
//class c_gameserver; //��Ϸ������
//class c_small_world; //Сǧ����
//class c_res_mg; //��Դ����
//class c_fight; //ս�����
//class c_uinfo; //�û���Ϣ����
//class c_make; //���ƶ���
//class c_skill; //���ܶ���
class c_observer
{
	//�۲��ߣ�������
	//�¼����Ͷ���:
	//1�����Сǧ�����б���ɾ������ʽɾ��ǰ֪ͨ/2��������֪ͨ/3����֪ͨ60�����/
	//4���뷿��ǰ���󷿼�����7001ָ��,ֵΪ�û�ID/
	//5һ��������/6��Сʱ����/7Сʱ����/8������/
	//9�ƶ�����/
	//10�½������/
	//11���������ڴ����/
	//12�ƶ���ʼǰ/
	//13������Ʒǰ/
	//14��ʰ��Ʒ��/
	//15��������ʼ���/
	//16����ֵ�䶯/
	//17�ȼ��䶯/
	//18ս������ǰ��������Ҽ���/
	//19�ɽٳɹ�/
	//20����ǰ/
	//21�����/
	//22Ѫ���ޱ䶯/
	//23�����ޱ䶯/
	//24�����ޱ䶯/
	//25���ٱ䶯/
	//26�����䶯/
	//27�����䶯/
	//28�û����뷿���/
	//29��С���Ƭ������/
	//30�ɽ�ʧ��/
	//31��ʼ�ɽ�/
	//32ʹ����Ʒ����ǰ/
	//33����Ʒ��Դ��/
	//34����Ʒ��Դ��/
	//35���ɱ�������/
	//36��ҽ�˰��/
	//37���ɱ�������/
	//38�������/
	//39��Ҵ���/
	//40����������/
	//41���ȫ����������/
	//42���˳ɹ�,uid/
	//43��ǳɹ�,uid/
	//44��¼�ɹ�,uid/
	//45�˳���Ϸ,uid/
	//46��������,uid/

	//����֪ͨ
	//101��ɹؿ�,uid/
	//102���ӿ���,uid/
	//103��սʤ��,uid/
	//104��ս֪ͨ,room/
	//105��ӳ�ս��¼,city/
	//106��ȡ����,uid/
	//107��սʤ,uid/
	//108���Ʊ䶯,uid/
	//109�״δ��,Ӣ��,uid------------/
	//110���10��,uid/

public:
//	c_observer(c_ref * const);
//	c_observer(c_res * const);
//	c_observer(c_gameserver * const);
//	c_observer(c_small_world * const);
//	c_observer(c_res_mg * const);
//	c_observer(c_fight * const);
//	c_observer(c_uinfo * const);
//	c_observer(c_make * const);
//	c_observer(c_skill * const);
	virtual ~c_observer(){};
	virtual void update(int,int)=0; //֪ͨ�ӿ�:����,ֵ(-1Ĭ��)
//	void update(int,int); //֪ͨ�ӿ�:����,ֵ(-1Ĭ��)

//	void tests(void);
protected:
	c_observer(){};
private:
//	c_ref *p_ref;
//	c_res *p_res;
//	c_gameserver *p_gms;
//	c_small_world *p_small;
//	c_res_mg *p_res_mg;
//	c_fight *p_fight;
//	c_uinfo *p_uinfo;
//	c_make *p_make;
//	c_skill *p_skill;

//	inline void init(void){p_ref=NULL;p_res=NULL;p_gms=NULL;p_small=NULL;p_res_mg=NULL;p_fight=NULL;p_uinfo=NULL;p_make=NULL;p_skill=NULL;}
};

#endif


