#pragma once

#include "AbstractCommand.h"
class LSCommand : public AbstractCommand {
private:
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
public:
    LSCommand(AbstractFileSystem*, AbstractFileFactory*);
    void displayInfo() override;
    int execute(std::string) override;
};