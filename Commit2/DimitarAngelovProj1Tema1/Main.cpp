#include "ComReader.h"

void norm(std::string& str){
    for(int i=0;i<str.length();i++){
        if(str[i]>=65&&str[i]<=90){
            str[i]=str[i]+32;
        }
    }
}

int main(int argc, const char** argv){

    AllReports Allrep;
    Users usrs;

    CommandReader cmd;
    std::string c="";

    User usr;
    UserReports Myrep;
    int currR=0,userR=0;

    while(true){
        norm(c);
        if(c=="exit"){
            break;
        }
        cmd.setcomd(c);
        cmd.execute(usr,Myrep,Allrep,usrs,currR,userR);
        if(cmd.getstate()==2){
            std::cout<<"LogAs:"<<usr.getName()<<" rep"<<currR<<"/"<<userR<<" ";
        }
        if(cmd.getstate()==1){
            std::cout<<"LogAs:"<<usr.getName()<<" ";
        }
        std::cout<<">";
        std::cin>>c;
    }

    return 0;
}
