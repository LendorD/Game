//
// Created by Lendor on 14.12.2022.
//

#include "SaveLevel.h"

void SaveLevel::CreateFile() {
    on.open("Field.txt",std::ios::out);
}




void SaveLevel::SaveLvl(Field *field) {
    len = field->getLenght();
    wig = field->getWigth();
    if(!on.is_open()){
        throw errorsF.FileDel();
    }
    for(int i = 0; i < len;i++){
        for(int j = 0; j < wig;j++){
            Cell cell = field->getCell(i,j);
            CellView cellView(cell);
            if(cellView.getView() == "X")on <<"X" << "t";
            if(cellView.getView() == "\3")on <<"M" << "f";//Mana
            if(cellView.getView() == "*")on <<"*" << "f";
            if(cellView.getView() == "|")on <<"|" << "t";
            if(cellView.getView() == "\2")on <<"P" << "f";//Player
            if(cellView.getView() == "$")on <<"$" << "f";
            if(cellView.getView() == ".")on <<"." << "f";
        }
        on << '\n';
    }
    on << field->player->getHealth() << '\n';
    on << field->player->getMana()<< '\n';
    on <<  field->player->getKey();
    on.close();
}

void SaveLevel::UploadLvl(Field* field) {
    in.open("Field.txt");
    if(!in.is_open()){
        throw errorsF.FileDel();
    }
    if(std::filesystem::file_size("Field.txt") == 0 or std::filesystem::file_size("Field.txt") != std::filesystem::file_size(file)){
        throw errorsB.IncorrectBits();
    }
    len = field->getLenght();
    wig = field->getWigth();
    for(int i = 0;i< len;i++) {
        for (int j = 0; j < wig; j++) {
            char sim = in.get();
            char bl = in.get();
            if(bl == 't') av = true;
            else av = false;
            if (sim == '|') {
                field->map[i][j].setSign(new WallSign);
                field->map[i][j].setAvailable(av);
            }
            if (sim == 'X') {
                field->map[i][j].setSign(new ExitSign);
                field->map[i][j].setAvailable(av);
            }
            if (sim == 'M') {
                field->map[i][j].setSign(new ManaSign);
                field->map[i][j].setAvailable(av);
            }
            if (sim == '*') {
                field->map[i][j].setSign(new EnemySign);
                field->map[i][j].setAvailable(av);
            }
            if (sim == 'P') {
                field->PlayerX = i;
                field->PlayerY = j;
                field->map[i][j].setSign(new PlayerSign);
                field->map[i][j].setAvailable(av);
            }
            if (sim == '.') {
                field->map[i][j].setSign(new EmptySign);
                field->map[i][j].setAvailable(av);
            }
        }
        char per = in.get();
    }
    field->SetField(field->map);

    for(int i = 0; i < 3;i ++){
        std::getline(in, line);
        int chrPlayer = std::stoi(line);
        if(chrPlayer < 0){
            throw errorsP.IncorrectPlayer();
        }
        if(i == 0) field->player->setHealth(chrPlayer);
        if(i == 1)field->player->setMana(chrPlayer);
        else field->player->setKey(chrPlayer);
    }
    in.close();
}

SaveLevel::~SaveLevel() {

}
