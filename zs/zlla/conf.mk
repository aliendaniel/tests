#-------��Ҫ���ݲ�ͬƽ̨���õ�ֵ----------
#make,gmake
#��windowsƽ̨ʱSYSֵΪwin2000,winxp,bsd47,linux,bsd54,bsd70,mac
SYS = winxp
#LV�ǿ�İ汾����ͬ�汾stl��hash����ͷ�ļ����ܲ�ͬ,ȡֵ-D LV���
LV = 
#DEBUG�Ƿ���԰汾,-D DEBUG,-D NDEBUG, -g��ӡgdb��Ϣ
DEBUG = -D DEBUG $(LV) -g
#DEBUG = -D NDEBUG $(LV)
#-----------���ñ���----------
CC = g++
OPTIONS = -o3
MAKE = make
DIR_INC = 
DIR_LIB = 
#--------end ��Ҫ���ݲ�ͬƽ̨���õ�ֵ-----
