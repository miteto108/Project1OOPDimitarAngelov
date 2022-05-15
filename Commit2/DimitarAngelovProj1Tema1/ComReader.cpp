#include "ComReader.h"

CommandReader::CommandReader(){
    this->comd="logout";
    this->state=0;
}

CommandReader::CommandReader(std::string comd,short state){
    this->comd=comd;
    this->state=state;
}

CommandReader::~CommandReader(){
    //just in case if i add something i want to delete in a destructor
}

void CommandReader::setcomd(std::string comd){
    this->comd=comd;
}

void CommandReader::setstate(short state){
    this->state=state;
}

std::string CommandReader::getcomd()const{
    return this->comd;
}

short CommandReader::getstate()const{
    return this->state;
}

void CommandReader::Begin(){
    if(this->getstate()!=0){
        std::cout<<"******This case is impossible by just in case ;-)******************"<<'\n';
        this->setstate(0);
    }
    std::cout<<'\n';
    std::cout<<"-----------You entered the `Diary of the traveler`-------------------"<<'\n'<<'\n';
    std::cout<<"If you have an account you can type >l or >log and then log in, or if you are new you can type >r or >reg and create new account"<<'\n';
    std::cout<<"Or see the list of all users by typing >su or >showusers"<<'\n';

}

void CommandReader::Help(){
    //std::cout<<"how to navigate in the project";
}

void CommandReader::LogOut(){
    if(this->getstate()!=0){
        std::cout<<"You successfully logged out!"<<'\n';
        this->setstate(0);
    }
    if(this->getstate()==0){
        std::cout<<"You are not logged in so you cant log out. If you want to exit the program type >e"<<'\n';
        return;
    }
    this->Begin();
}

void CommandReader::Exit(){
    this->setcomd("exit");
}

void CommandReader::RegLogIn(User& usr){
    if(this->getstate()!=0){
        std::cout<<"You cannot login or register while you are in an other account!"<<'\n';
        return;
    }
    if(this->getcomd()=="r"||this->getcomd()=="reg"){
        //...
    }
    if(this->getcomd()=="l"||this->getcomd()=="log"){
        //...
    }
    this->setstate(1);
}

void CommandReader::ShowMyDataBase(UserReports& Myrep){
    if(this->getstate()==0){
        std::cout<<"You are not logged in so you cant see your database!"<<'\n';
        return;
    }
    Myrep.pr();
}

void CommandReader::WriteInMyBase(UserReports& Myrep,int& currR,int& userR){
    if(this->getstate()==0){
        std::cout<<"You are not logged to write in your reports"<<'\n';
        return;
    }
    std::string des="";
    std::cout<<'\n'<<"Input Destination:";
    std::cin>>des;
    std::string d1="",d2="";
    std::cout<<'\n'<<"Input two dates (time period):";
    std::cin>>d1>>d2;
    Period per (d1,d2);
    int gr;
    std::cout<<'\n'<<"Input grade:";
    std::cin>>gr;
    std::string comm="";
    std::cout<<'\n'<<"Input comment:";
    std::getline (std::cin,comm);
    std::cout<<'\n'<<"Input 1 photo later you can add more with >addp :";
    std::string photo="";
    std::cin>>photo;
    std::vector<std::string> photos;
    photos.clear();
    photos.push_back(photo);
    Report rep (des,per,gr,comm,photos);

    if(rep.validReport()){
        Myrep.getUrep().push_back(rep);
        userR++;
    }
    this->setstate(2);
    currR=1;
}

void CommandReader::NextInMyBase(UserReports& Myrep,int& currR,int& userR){
    if(this->getstate()==0||this->getstate()==1){
        std::cout<<"You are not into your reports reports"<<'\n';
        return;
    }
    currR++;
    if(currR>userR){
        currR=1;
        if(userR==0){
            currR=0;
        }
    }

    Myrep.getUrep()[currR-1].pr();
}

void CommandReader::CurrInMyBase(UserReports& Myrep,int& currR,int& userR){
    if(this->getstate()==0||this->getstate()==1){
        std::cout<<"You are not into your reports"<<'\n';
        return;
    }
    Myrep.getUrep()[currR-1].pr();
}

void CommandReader::PrevInMyBase(UserReports& Myrep,int& currR,int& userR){
    if(this->getstate()==0||this->getstate()==1){
        std::cout<<"You are not into your reports"<<'\n';
        return;
    }
    currR--;
    if(currR<1){
        currR=userR;
    }

    Myrep.getUrep()[currR-1].pr();
}

void CommandReader::IndexReportInMyBase(UserReports& Myrep,int& currR,int& userR){
    if(this->getstate()==0){
        std::cout<<"You are not logged"<<'\n';
        return;
    }
    std::cout<<"Enter index:";
    int ind;
    std::cin>>ind;
    if(ind>userR||ind<1){
        std::cout<<"Not valid number"<<'\n';
    }
    else{
        this->setstate(2);
        currR=ind;
        Myrep.getUrep()[currR-1].pr();
    }
}

void CommandReader::EnterInMyBase(){
    if(this->getstate()==0){
        std::cout<<"You are not logged"<<'\n';
        return;
    }
    this->setstate(2);
}

void CommandReader::OutOfMyBase(){
    if(this->getstate()==0){
       std::cout<<"You are not logged"<<'\n';
       return;
    }
    if(this->getstate()==2){
       std::cout<<"You are currently not in your base to exit"<<'\n';
       return;
    }
    this->setstate(1);
}

void CommandReader::DeleteThisReport(UserReports& Myrep,int& currR,int& userR){
    if(this->getstate()!=2){
       std::cout<<"You are not logged or in you database so cant delete report"<<'\n';
       return;
    }
    Myrep.getUrep().erase(Myrep.getUrep().begin()+currR-1);
    userR--;
    currR--;
}

void CommandReader::AddPhoto(UserReports& Myrep,int& currR,int& userR){
    if(this->getstate()!=2){
       std::cout<<"You are not logged or in you database so cant add photos"<<'\n';
       return;
    }
    std::cout<<"This function is not implemented yet"<<'\n';
    //Myrep.getUrep()[currR-1].getPhs()

}

void CommandReader::DeletePhoto(UserReports& Myrep,int& currR,int& userR){
    if(this->getstate()!=2){
       std::cout<<"You are not logged or in you database so cant delete photos"<<'\n';
       return;
    }
    std::cout<<"This function is not implemented yet"<<'\n';


}

void CommandReader::ShowAllUsers(Users& usrs){
    usrs.pr();
}

void CommandReader::ShowAllDataBase(AllReports& Allrep){
    if(this->getstate()==0){
       std::cout<<"You are not logged so you cant see the hole database"<<'\n';
       return;
    }
    Allrep.pr();

}

void CommandReader::ShowDestDataBase(AllReports& Allrep){
    if(this->getstate()==0){
       std::cout<<"You are not logged so you cant see the hole database"<<'\n';
       return;
    }
    std::cout<<"Enter Location:";
    std::string locstr="";
    std::cin>>locstr;
    bool b=0;
    int sum=0;
    for(int i=0;i<Allrep.getArep().size();i++){
        if(Allrep.getArep()[i][0].getDest()==locstr){
            for(int j=0;j<Allrep.getArep()[i].size();j++){
                Allrep.getArep()[i][j].pr();
                sum=sum+Allrep.getArep()[i][j].getGr();
            }
            std::cout<<" ---Average score for this destination is: "<<(double)sum/(Allrep.getArep()[i].size())<<'\n';
            b=1;
            break;
        }
    }
    if(b==0){
        std::cout<<"There was not a destination '"<<locstr<<"' in the app yet"<<'\n';
    }
}

void CommandReader::execute(User& usr,UserReports& Myrep,AllReports& Allrep,Users& usrs,int& currR,int& userR){
    std::string command="";
    command=this->getcomd();

    if(command=="h"||command=="help"){
        this->Help();
    }
    else if(command=="logout"){
        this->LogOut();
    }
    else if(command=="e"||command=="exit"){
        this->Exit();
    }
    else if(command=="r"||command=="reg"||command=="l"||command=="log"){
        this->RegLogIn(usr);
    }
    else if(command=="s"||command=="show"){
        this->ShowMyDataBase(Myrep);
    }
    else if(command=="w"||command=="write"){
        this->WriteInMyBase(Myrep,currR,currR);
    }
    else if(command=="n"||command=="next"){
        this->NextInMyBase(Myrep,currR,currR);
    }
    else if(command=="c"||command=="curr"){
        this->CurrInMyBase(Myrep,currR,currR);
    }
    else if(command=="b"||command=="back"){
        this->PrevInMyBase(Myrep,currR,currR);
    }
    else if(command=="go"||command=="g"){
        this->IndexReportInMyBase(Myrep,currR,currR);
    }
    else if(command=="i"||command=="in"){
        this->EnterInMyBase();
    }
    else if(command=="o"||command=="out"){
        this->OutOfMyBase();
    }
    else if(command=="d"||command=="delete"){
        this->DeleteThisReport(Myrep,currR,currR);
    }
    else if(command=="addp"){
        this->AddPhoto(Myrep,currR,currR);
    }
    else if(command=="delp"){
        this->DeletePhoto(Myrep,currR,currR);
    }
    else if(command=="su"||command=="showusers"){
        this->ShowAllUsers(usrs);
    }
    else if(command=="sa"||command=="showall"){
        this->ShowAllDataBase(Allrep);
    }
    else if(command=="sd"){
        this->ShowDestDataBase(Allrep);
    }
    else{
        std::cout<<"---Do not recognize the command---"<<'\n';
    }


}
