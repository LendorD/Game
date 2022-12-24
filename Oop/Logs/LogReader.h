//
// Created by Lendor on 26.10.2022.
//

#ifndef OOP_LOGREADER_H
#define OOP_LOGREADER_H
#include "iostream"
#include "vector"
#include "Field.h"

#include "sstream"
#include "Message.h"
class LogReader {
public:
    enum LogLevel{ErrorLogs, FieldLogs, PlayerLogs};
    LogReader();
    void Create(Field* obj, LogLevel pref);
    ~LogReader() = default;
    std::string getLog();
    std::string getPref();
    std::string CreateLogError(Field* obj);
    std::string CreateLogPlayer(Field* obj);
    std::string CreateLogField(Field* obj);
    bool StatusField(Field* obj);
    bool FieldStatus;
    std::string log;
    Field* obj;
    std::string pref;


//    std::ofstream out;
};


#endif //OOP_LOGREADER_H
