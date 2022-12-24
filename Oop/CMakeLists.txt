cmake_minimum_required(VERSION 3.22)
project(Oop)

set(CMAKE_CXX_STANDARD 17)

include_directories(Cell)
include_directories(Event)
include_directories(Field)
include_directories(Player)

add_executable(Oop test.cpp Cell/Cell.cpp Cell/Cell.h Field/Field.cpp Field/Field.h Player/Player.cpp
        Player/Player.h Event/Event.cpp Event/Event.h
        Field/FieldView.cpp Field/FieldView.h Event/EventFactory.cpp Event/EventFactory.h Event/EventEvil.cpp Event/EventEvil.h
        Event/EventPretty.cpp Event/EventPretty.h
        Cell/CellSign.cpp Cell/CellSign.h Cell/CellView.cpp Cell/CellView.h Logs/LogReader.cpp Logs/LogReader.h Logs/LogPrint.cpp Logs/LogPrint.h
        Logs/Message.cpp Logs/Message.h
        Comands/PlayerMove.cpp Comands/PlayerMove.h Comands/up.cpp Comands/up.h Comands/left.cpp Comands/left.h
        Comands/down.cpp Comands/down.h Comands/right.cpp Comands/right.h Comands/MoveInterface.cpp Comands/MoveInterface.h GeneratorField/Generator.h GeneratorField/RulesSpawnPlayer.h GeneratorField/RulesSizeField.h GeneratorField/RulesSetEvent.h GeneratorField/RulesCharacteristicPlayer.h GeneratorField/RulesExitPos.h GeneratorField/RulesSpawnEnemy.h GeneratorField/Random.h GeneratorField/LevelField.h GameStart.cpp GameStart.h SaveGame/SaveLevel.cpp SaveGame/SaveLevel.h SaveGame/Errors/FileDelete.cpp SaveGame/Errors/FileDelete.h)