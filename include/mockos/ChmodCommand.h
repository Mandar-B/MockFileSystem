//
// Created by Mandar Brahmbhatt on 12/15/23.
//
#pragma once

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
class ChmodCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
public:
    ChmodCommand(AbstractFileSystem*);
    void displayInfo() override;
    int execute(std::string) override;

};