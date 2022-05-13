#pragma once

#include "Reports.h"

class CommandReader{
private:
    std::string comd;
    short state;// 0 - for beginning ; 1 - when logged and not in a report ; 2 - when logged and in a report
public:

    CommandReader();
    CommandReader(std::string comd);
    ~CommandReader();

    void setcomd(std::string comd);
    void setstate(short state);
    std::string getcomd()const;
    short getstate()const;

    void Help();//help for project
    void LogOut();//log out from current account
    void Exit();//exits the application and updates files
    void RegLogIn();//the first command
    void ShowMyDataBase();//shows users hole database
    void WriteInMyBase();//allows to write a report in data base
    void NextInMyBase();//prints next report
    void IndexReportInMyBase();//goes to the report with the shown index
    void AddPhoto();//adds photo to current report
    void DeleteThisReport();//deletes current report
    void ShowAllDataBase();//shows all hole database
    void ShowDestDataBase();//shows database for pointed destination + aver grade


    void execute();//executes a function depending on comd

};
