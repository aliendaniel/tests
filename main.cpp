//--------�Ƚ������--------
/*
����
IE
FF
*/
//#include <stdio.h>
#include <iostream>  
#include <time.h>  
#include <stdlib.h>  
#include <vector>
using namespace std;  
const int SIZE_CHAR = 32; //����32 + 1λC Style�ַ���  
const char CCH[] = "_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";  
typedef vector<int> tp_vi;
void print(tp_vi &tmp);
int main()  
{  
    srand((unsigned)time(NULL));  
    char ch[SIZE_CHAR + 1] = {0};  
    for (int i = 0; i < SIZE_CHAR; ++i)  
    {  
       int x = rand()%sizeof(CCH);     
       ch[i] = CCH[x];  
    }  
    cout <<ch <<"/n";        
    return 0;  
}  
void rash(void)
{
	srand((unsigned int)time(NULL));
	int num = 80;
	tp_vi vi_ls;
	vi_ls.reserve(num);
	for(int i =0;i<num;++i){
		vi_ls.push_back(i);
	}

	//����
	int key,val;
	for(int i =0;i<vi_ls.size();++i){
		key = rand()%num;
		val = vi_ls[key];
		vi_ls[key] = vi_ls[i];
		vi_ls[i] = val;
	}
}
void print(tp_vi &tmp)
{
	for(int i=0;i<tmp.size();++i){
		cout << tmp[i] << ",";
	}
	cout << endl;
}
void ques()
{
	//����
	
	//��ʱ��
	//����������
	//��������λ��ע
	//��עʧ�ܣ��߳�
	//ע���ϼ��Ƿ�Ϊ0
	//��ע���ʳ�
	//ȡ��Ŀ��ѡ��
	//����Ŀ
	//��մ����ʶ
	//�㲥�ʳص�����
	//�㲥��Ŀ����
}
void click()
{
	//ѡ��

	//����������
	//������λ�û�
	//�����Ѵ�
	//������ʶ
	//�ʳر䶯����
	//�Ƿ�ѡ��
	//��Ǯ
	//�Ƿ���ȷ
	//��ȷ����Ǯ
	//�㲥�ʳص���
	//��λǮ����
	//ѡ��ͽ������
}
//������
//���б�ʶ
//�ʳ�
//��Ŀ��ѡ��
//��λ��
//�ƶ�
//ÿ�ִ����ʶ

//����
//ϴ��
//�ı�����״̬.������λ��
//�߳�
/*int main(int argc, char *argv[])
{
	printf("Hello, world\n");
	
	return 0;
}
*/
/*
#include <iostream>  
#include <string>  
#include <vector>  
using namespace std;  
int main()  
{  
    string tmp1,tmp2;  
    tmp1="rusher;lewjan;bill;stan;yx;";  
    tmp2="abcc";  
    vector<string>list;  
    list.push_back(tmp1);  
    list.push_back(tmp2);  
    for (unsigned int i=0;i<list.size();i++)  
    {  
       cout<<list[i]<<endl;  
    }  
    return 0;  
}  
*/	

