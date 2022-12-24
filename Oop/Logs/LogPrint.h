//
// Created by Lendor on 26.10.2022.
//

#ifndef OOP_LOGPRINT_H
#define OOP_LOGPRINT_H

#include <fstream>
#include "LogReader.h"

class FilePrint{
public:
    FilePrint(LogReader::LogLevel pref):pref(pref){}
    FilePrint();
    friend std::ostream& operator<<(std::ostream& out, const FilePrint* obj){
        out << obj->pr << "\n";
        out << obj->l;
        return out;
    }
    FilePrint *FileUpdate(LogReader* obj);
    void PrintInFile(LogReader* obj);
    void CreateFile();

private:
    std::string pr;
    std::string l;
    LogReader::LogLevel pref;
    std::ofstream outF;
};

class ConsolePrint{
public:
    ConsolePrint(LogReader::LogLevel pref):pref(pref){}
    friend std::ostream& operator<<(std::ostream& out, const ConsolePrint &obj){
        out << obj.pr << '\n';
        out << obj.l;
        return out;
    }
    ConsolePrint ConsoleUpdate(LogReader *obj);
    void PrintInConsole(LogReader* obj);
    std::string pr;
    std::string l;
private:

    LogReader::LogLevel pref;
};

#endif //OOP_LOGPRINT_H
