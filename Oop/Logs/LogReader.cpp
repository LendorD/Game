//
// Created by Lendor on 26.10.2022.
//

#include "LogReader.h"

LogReader::LogReader():pref(""),log("") {
}

void LogReader::Create(Field* obj, LogLevel pref){
    if (pref == ErrorLogs){
        this->pref = "[ErrorLogs]";
        this->log = CreateLogError(obj);
    }
    if(pref == PlayerLogs){
        this->pref = "[PlayerLogs]";
        this-> log = CreateLogPlayer(obj);
    }
    if(pref == FieldLogs){
        this->pref = "[FieldLogs]";
        this->log = CreateLogField(obj);
    }
//    this->text.pr = this->pref;
//    this->text.l = this->log;
}

bool LogReader::StatusField(Field* obj){
    return this->FieldStatus = obj->StatusField();


}

std::string LogReader::CreateLogError(Field* obj){
    this->log.clear();
    if(obj->getWigth() < 0){
        this->log += "Wight is less than zero!!!";
        this->log += '\n';
    }
    if(obj->getLenght() < 0){
        this->log += "Lenght is less than zero!!!";
        this->log += '\n';
    }
    if(obj->player->getHealth() < 0){
        this->log += "The player died :(";
        this->log += '\n';
    }
    if(obj->PlayerY > obj->getWigth() or obj->PlayerY > obj->getLenght()){
        this->log += '\n';
        this->log += "Player ran away from the borders!!!";
    }
//    this->text.l = this->log;
    return this->log;
}


std::string LogReader::CreateLogPlayer(Field* obj){
    this->log.clear();
    this->log += "Health: " + std::to_string(obj->player->health) + " Mana: " + std::to_string(obj->player->mana) +
                 " Key: " + std::to_string(obj->player->key);
    this->log += '\n';
//    this->text.l = this->log;
    return this->log;
}


std::string LogReader::CreateLogField(Field* obj){
    this->log.clear();
    if(obj->getLenght() > 0 and obj->getWigth() >0){
        this->log += "Field is set correctly";
    }
    if(not StatusField(obj)) this->log = "Active";
    else this->log  = "Slipping";
    this->log += '\n';
//    this->text.l = this->log;
    return this->log;
}

std::string LogReader::getLog(){
    return this->log;
}
std::string LogReader::getPref(){
    return this->pref;
}