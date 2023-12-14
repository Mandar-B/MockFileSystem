#pragma once

#include "AbstractCommand.h"
#include "AbstractFileFactory.h"
#include "AbstractFileSystem.h"

class AbstractFileSystem;

class CatCommand : public AbstractCommand {
public:
    CatCommand(AbstractFileSystem* fs);
    virtual void displayInfo();
    virtual int execute(std::string args);

private:
    std::string getUserInput() const;

    AbstractFileSystem* file_system;
    std::string userInput; // To store user input for testing purposes
};