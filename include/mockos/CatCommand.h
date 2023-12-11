#pragma once

#include "AbstractCommand.h"
class CatCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
public:
    CatCommand(AbstractFileSystem*, AbstractFileFactory*);
    void displayInfo() override;
    int execute(std::string) override;
};