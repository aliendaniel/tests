#zll,2006-5-31
#----------˵��------------
#���ݲ�ͬƽ̨������Ӧ��ͷ�ļ��Ϳ��ļ�
#�������ļ�֮ǰ���붨��DIR_LIB�������
#DIR_LIB = ../lib/
#---------end ˵��---------
#winxp
ifeq ($(SYS),winxp)
LIBS = -L"D:/tools/Dev-Cpp/pthread/Pre-built.2/lib" -lpthreadGC2 -L"D:/tools/Dev-Cpp/lib" -lws2_32
LINKLIB = $(DIR_LIB)libtm.xp.a
LINKS = $(DIR_LIB)libsmpth.xp.a
endif
#FreeBSD7.0
ifeq ($(SYS),bsd70)
INCS = -I"/usr/local/include/mysql"
LIBS = -lpthread
LINKLIB = $(DIR_LIB)libtm.bsd70.a
LINKS = $(DIR_LIB)libsmpth.bsd70.a
MAKE = gmake
endif
#mac
ifeq ($(SYS),mac)
INCS = -I"/usr/local/mysql/include"
LIBS = -lpthread
LINKLIB = $(DIR_LIB)libtm.mac.a
LINKS = $(DIR_LIB)libsmpth.mac.a
endif

