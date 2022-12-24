//
// Created by Lendor on 14.12.2022.
//

#include "FileDelete.h"
std::string ErrorsFile::FileDel() {
    return "File was delete: ";
}

std::string ErrorsPlayer::IncorrectPlayer() {
    return "Incorrect Players characters";
}

std::string ErrorsBit::IncorrectBits(){
    return "The file sizes do not match the saved one";
}