//#include <stdio.h>
#include <iostream>  
#include <time.h>  
#include <stdlib.h>  
using std::cout;  
const int SIZE_CHAR = 32; //����32 + 1λC Style�ַ���  
const char CCH[] = "_0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";  
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

