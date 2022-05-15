#pragma once

#include "Reports.h"

class CommandReader{
private:
    std::string comd;
    short state;// 0 - for beginning ; 1 - when logged and not in a report ; 2 - when logged and in a report
public:

    CommandReader();
    CommandReader(std::string comd,short state);
    ~CommandReader();

    void setcomd(std::string comd);
    void setstate(short state);
    std::string getcomd()const;
    short getstate()const;

    void Begin();//Just the beginning of the program (state 0)
/*!*/    void Help();//help for project and all commands [>h , >help]  (state 0,1,2)
    void LogOut();//log out from current account [>logout]  (state 1,2) //enters state 0
/*!*/    void Exit();//exits the application and updates files [>e , >exit]  (state 0,1,2)
/*!*/    void RegLogIn(User& usr);//register or login [>r , >reg , >l , >log] 'enter' (state 0) //enters state 1
    void ShowMyDataBase(UserReports& Myrep);//shows users hole database [>s , >show]  (state 1,2)
    void WriteInMyBase(UserReports& Myrep,int& currR,int& userR);//allows to write a report in data base [>w , >write]  (state 1,2) //enters state 2
    void NextInMyBase(UserReports& Myrep,int& currR,int& userR);//prints and goes to next report [>n , >next]  (state 2)
    void CurrInMyBase(UserReports& Myrep,int& currR,int& userR);//prints current report [>c , >curr]  (state 2)
    void PrevInMyBase(UserReports& Myrep,int& currR,int& userR);//prints and goes to next report [>b , >back]  (state 2)
    void IndexReportInMyBase(UserReports& Myrep,int& currR,int& userR);//goes to the report with the shown index [>go , >g] 'enter' x //where x is index start 1  (state 1,2) //enters state 2
    void EnterInMyBase();//enters state 2 in index 1 or 0 if empty [>i , >in] (state 1) //enters state 2
    void OutOfMyBase();//enters state 1 from 2 [>o , >out] (state 2) //enters state 1
    void DeleteThisReport(UserReports& Myrep,int& currR,int& userR);//deletes current report [>d , >delete]  (state 2)
/*not implemented*/    void AddPhoto(UserReports& Myrep,int& currR,int& userR);//adds photo to current report [>addp 'enter' name]  (state 2)
/*not implemented*/    void DeletePhoto(UserReports& Myrep,int& currR,int& userR);//deletes photo in current report [>delp 'enter' name]  (state 2)
    void ShowAllUsers(Users& usrs);//shows all registered users [>su , >showusers]  (state 0,1,2)
    void ShowAllDataBase(AllReports& Allrep);//shows the hole database [>sa , >showall]  (state 1,2)
    void ShowDestDataBase(AllReports& Allrep);//shows database for pointed destination + aver grade [>sd 'enter' name]  (state 1,2)


    void execute(User& usr,UserReports& Myrep,AllReports& Allrep,Users& usrs,int& currR,int& userR);//executes a function depending on comd

};
