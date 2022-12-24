//
// Created by Lendor on 30.11.2022.
//

#include "GameStart.h"

void GameStart::StartGame() {

    std::cout << "Choce game's levels: 1 - 1 level; 2 - 2 level; 3 - standart level" << '\n';
    std::cin >> FieldLevel;
    field = lvlField.ChoiceLevel(FieldLevel);
    std::cout << "Choce print logs: 1 - File; 2 - Console; 3 - File and Console; 0 - Not Logs:" << '\n';
    std::cin >> Logs;
    if(Logs != 0){
        std::cout << "Choce level logs: 1 - ErrorLogs; 2 - PlayerLogs; 3 - FieldLogs;" << '\n';
        std::cin >> lvlLogs;
    }

    if (lvlLogs == 1)levelLog = LogReader::LogLevel::ErrorLogs;
    if(lvlLogs == 2)levelLog = LogReader::LogLevel::PlayerLogs;
    if(lvlLogs == 3)levelLog = LogReader::LogLevel::FieldLogs;
    logs->Create(field,levelLog);
    FilePrint file(levelLog);
    ConsolePrint console(levelLog);
    checkLose = start.GameOver(*field);
    PlayerMove move(field);
    move.ReadTxt();
    std::cout << "Please select the movement settings" << '\n' << "1 - standard 2 - file" << '\n';
    ChoseMove = 1;
    std::cin >> ChoseMove;
    while (checkLose) {
        start.start(field);
        std::cout << "Health: " << field->player->getHealth() << " Mana:" <<field->player->getMana() <<'\n';
        if(lvlLogs == 1)logs->CreateLogError(field);
        if(lvlLogs == 2)logs->CreateLogPlayer(field);
        else logs->CreateLogField(field);
        switch(Logs) {
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
        if(action == 'q'){
            try{
                SaveLevel.CreateFile();
                SaveLevel.SaveLvl(field);
            }catch(ErrorsFile FileDel){
                std::cout << FileDel.FileDel();
            }catch(ErrorsPlayer errP){
                std::cout << errP.IncorrectPlayer();
            }
        }
        if(action == 'e'){
            try{
                SaveLevel.UploadLvl(field);

            }catch(ErrorsFile FileDel){
                std::cout << FileDel.FileDel();
            }catch(ErrorsPlayer errP){
                std::cout << errP.IncorrectPlayer();
            }catch(ErrorsBit errB){
                std::cout << errB.IncorrectBits();
            }
        }
        switch (ChoseMove) {
            case (1):
                field->ChangesFrame(action);
                break;
            case (2):
                move.Move(field, action);
                break;
        }
        std::cout<< "left = a right = d\nup = w down = s\ncast = z none = 0"<< " " << '\n';
        checkLose = start.GameOver(*field);
        std::cout <<'\r';

    }
}