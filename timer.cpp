一,2013-08-05
二,2013-08-06
//写入广播,19:00
//成功注册,18:00
//失败注册
//失败登录,17:30
//成功登录,17:00
//登录请求处理,deal_cmd,17:00
//请求结构
//响应结构
//请求环境,16:30
//处理消息框架,14:00-16:00
//旧有登录流程,14:00-15:00
//框架整理
//粘包处理
//bytes==-1处理
//git工作机
//登录流程


三,2013-08-07
//压入环境,10:30
//打包压入广播表,11:00
//push_bc函数,11:00
//get_yemore,11:40
//push_wirte,12:00
//取广播表写入,12:00
//检查广播流程,12:00
//广播系统,流程检查,14:00
//注册登录
//注册
//登录测试,15:30
//登录失败,15:30
//文件框架,测试环境,16:00
//订阅配对请求,16:30
//定义配对消息
//处理配对请求,17:00
//配对
//安装配对对象,17:30
//定义消息　
//定义消息
//提交参数,18:00
//处理消息
//订阅消息
//调用函数
//列表函数
//游戏逻辑实现
//广播战斗列表,19:00
//列表排错

四,2013-08-08
//设置环境变量,11:00
//安装devcpp,10:30
//安装gcc套件,11:30
//编译测试
//mysql,12:00
//安装数据库,13:30
//安装ssh,14:00
//查找ssh软件
//安装ssh
//测试ssh
//配置ssh
//git:配置,ci,up
//安装cvs,15:00
//qq程序员,16:00
//工作机环境
//git空项目
//老高  13:50:28
// 279323376
//编译完整版,17:00
//运行排错,17:30
//测试全部逻辑,18:00



五,2013-08-09
//openssh排错
//当日计划,10:15
//cvs使用ssh,11:00
//去注释，关页面,11:15
//check代码,11:45
//改include,13:30
//编译运行框架,14:00
//make,14:00
//git-cmd整合,15:30
//整理框架提交,17:00
//下载iso
//看无光驱安装文章


一,2013-08-12
//今日计划,10:15
//通讯服视图,11:00
//旧有客户端测试,11:30
//去无用注释SOCK,12:00
//收发代码整理
//ws
//usersock
//cals
//sockls
//bufio
//cmd_buf_pk改cmd_buf,13:30
//客户端空项目,14:00
//客户端框架,14:30
//开会,16:00
//去逻辑服,17:15
//去广播器,17:30
//commu库,17:30
//逻辑服接口,18:00
//通讯分支,18:30


二,2013-08-13
//计划,10:15
//通讯分支,11:15
//消息处理器安装,11:45
//消息处理器接口,11:30
//回调转接实验,14:30
//去注释,15:15
//客户端连接,15:30
//连接管理器,16:30
//发送请求,17:00
//发送排错,18:00
//去注释,18:15
//处理消息
//客户端框架
//响应消息
//看英雄设定,18:30

三,2013-08-14
//今日计划,10:30
//安装操作系统,13:30
//安装,12:00
//刻盘,11:30
//外网安装,15:00
//外网联通网卡,15:30
//广播器框架,16:30
//压入广播,通知,17:00
//是否为空,17:45
//取用户表,18:00
//取用户广播,18:15
//接口基类,18:30



四,2013-08-15
内网服务器环境安装,gcc,mysql
分离逻辑服
战斗列表值乱码
分离通讯服
模拟客户端
战斗列表
提交指令
配对指令
战斗需求分析
广播器接口
监听新广播,取出到写缓冲


五,2013-08-16
动态缓冲区
定时器线程安全


2013-09
record服务器
login/dispatch服务器

cvs -d mwjx@fish838.com:/usr/home/mwjx/cvsroot checkout -r "yesgame" -d zs_ye fc_server2
cvs -d mwjx@fish838.com:/usr/home/mwjx/cvsroot checkout -r "yesgame" commu
cvs -d mwjx@fish838.com:/usr/home/mwjx/cvsroot checkout -r "yesgame" -d kp dqs 

cvs -d mwjx@fish838.com:/usr/home/mwjx/cvsroot checkout tt

cvs -d mwjx@fish838.com:/usr/home/mwjx/cvsroot import -m "" zc_ye zll yegame start
cvs -d mwjx@fish838.com:/usr/home/mwjx/cvsroot checkout zc_ye

cvs tag -b "yesgame_commu"
cvs -d mwjx@fish838.com:/usr/home/mwjx/cvsroot checkout -r "yesgame_commu" commu


注册登录请求:
id(4),用户名(32)
注册登录响应:
id(4),返回码(4)

IP Address. . . . . . . . . . . . : 192.168.16.174
MDEF["port"] = 8091;

包格式:包头(1),父命令(1),子命令(2),包长(4),包体


电信：125.89.70.104
联通：112.91.150.232 
公司珠海机房的IP

明日灵感<coolner@vip.qq.com>  13:55:11
电信ip：125.89.70.104
掩码：255.255.255.224
网关：125.89.70.97

联通ip：112.91.150.232
掩码：255.255.255.224
网关：112.91.150.225

你安装系统时只配置电信ip，配置好之后再配置联通ip，联通网关默认不用配置
202.96.128.166
202.96.128.86




defaultrouter="58.215.76.129"
hostname="ptjf5.com"
ifconfig_msk0="inet 58.215.76.132  netmask 255.255.255.128"
inetd_enable="YES"
linux_enable="YES"
sshd_enable="YES"
git_daemon_enable="YES"<A1><B1>


hostname=""
keymap="hy.armscii-8.kbd"
ifconfig_em0=" inet 125.89.70.104 netmask 0xffffffe0"
defaultrouter="125.89.70.97"
ifconfig_em1=" inet 112.91.150.232 netmask 0xffffffe0"
defaultrouter="112.91.150.225"
sshd_enable="YES"
moused_enable="YES"
# Set dumpdev to "AUTO" to enable crash dumps, "NO" to disable
dumpdev="AUTO"
