//
// Created by Lendor on 26.10.2022.
//

#include "LogPrint.h"

FilePrint *FilePrint::FileUpdate(LogReader* obj) {
    this->pr = obj->pref;
    this->l = obj->log;
    return this;
}

ConsolePrint ConsolePrint::ConsoleUpdate(LogReader* obj) {
    this->pr = obj->pref;
    this->l = obj->log;
    return *this;
}


void ConsolePrint::PrintInConsole(LogReader* obj) {
    ConsolePrint a = ConsoleUpdate(obj);
    std::cout << a << '\n';
}

void FilePrint::CreateFile() {
    outF.open("log.txt",std::ios::app|std::ios::out);
}

void FilePrint::PrintInFile(LogReader *obj) {
    CreateFile();
    FilePrint *f = FileUpdate(obj);
//    outF << this->ivector;
    outF << f;
    outF.close();
}

