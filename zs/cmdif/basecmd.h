//------------------------------
//create time:2013-3-25
//creater:zll,liang_0735@21cn.com,www.mwjx.com
//purpose:�����������
//------------------------------
#ifndef C_BASECMD_H
#define C_BASECMD_H
class c_basecmd
{

public:
	c_basecmd(){};
	~c_basecmd(){};
	//virtual void update(int,int)=0; //֪ͨ�ӿ�:����,ֵ(-1Ĭ��)
	virtual int cmd(int,int,int,const char *)=0; //֪ͨ�ӿ�:����,ֵ(-1Ĭ��)
protected:
private:
};

#endif


