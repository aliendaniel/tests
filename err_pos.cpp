void c_cmd_buf::_recv_bc(void)
{
        //�������,Ŀǰ��Ҫ����㲥
        //����:��
        //���:��
        //cout << "c_cmd_buf::_recv_bc start" << endl;
        for(;;){
                mt_bc->lock();
                while(p_bl->bc_empty()){
                        mt_bc->wait();
                }
                mt_bc->unlock();
                p_bl->get_ul(obj_bc); //�У�ȡ�¹㲥������
                if(!obj_bc.to.empty()){start_bc();}
        }
}
void c_cmd_buf::start_bc(void)
{
        //��ʼ�㲥
        //����:��
        //���:��
        //cout << "c_cmd_buf::start_bc" << endl;
        //���ҹ㲥uid��socket
        //����д����
        set<int>::iterator it;
        int cli,no;
        for(it = obj_bc.to.begin();it != obj_bc.to.end();++it){
                cli = *it; //�û�ID
                //cerr << "*it=" << *it << endl;
                no = p_us->nobyuid(cli);
                if(no<0){continue;} //�ͻ��˲�����
//              if(p_gms->get_more(cli,buf_))
//                      p_bufio->push_write(fd,buf_,strlen(buf_)+1);
                if(p_bl->get_more(cli,buf_))
                        p_sockls->push_write(no,buf_,strlen(buf_)+1);
                //p_bufio->(buf_,strlen(buf_)+1,fd);
        }
        init_bc();
        /**/
}

int c_usersock::nobyuid(int u)
{
        //�����û�ȡ����
        if(mp_cs.end()==mp_cs.find(u)){return -1;}
        return mp_cs[u];
}