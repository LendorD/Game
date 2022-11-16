#include <iostream>
#include "Field/FieldView.h"
#include "Logs/LogPrint.h"
int main() {
    Field f;
    Field* cp_f = &f;
    FieldView a;
    std::cout << "Choce print logs: 1 - File; 2 - Console; 3 - File and Console; 0 - Not Logs:" << '\n';
    int pr;
    std::cin >> pr;
    int lvl;
    std::cout << "Choce level logs: 1 - ErrorLogs; 2 - PlayerLogs; 3 - FieldLogs;" << '\n';
    std::cin >> lvl;
    a.start(f);
    LogReader::LogLevel level;
    LogReader *logs = new LogReader;
    if (lvl == 1)level = LogReader::LogLevel::ErrorLogs;
    if(lvl == 2)level = LogReader::LogLevel::PlayerLogs;
    if(lvl == 3)level = LogReader::LogLevel::FieldLogs;
    logs->Create(cp_f,level);
    FilePrint file(level);
    ConsolePrint console(level);
    bool t = a.GameOver(f);
    char action;
    while (t) {
        if(lvl == 1)logs->CreateLogError(cp_f);
        if(lvl == 2)logs->CreateLogPlayer(cp_f);
        else logs->CreateLogField(cp_f);
        switch(pr) {
            case(1):
                file.PrintInFile(logs);
                break;
            case(2):
                console.PrintInConsole(logs);
                break;
            case(3):
                file.PrintInFile(logs);
                console.PrintInConsole(logs);
                break;
            default:
                break;
        }
        std::cin >> action;
        f.ChangesFrame(action);
        std::cout<< "left = a right = d\nup = w down = s\ncast = z none = 0"<< " " << '\n';
        t = a.GameOver(f);
        a.start(f);
    }
    return 0;
}

