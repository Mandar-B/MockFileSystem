#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>

class CommandPrompt {
protected:
    void listCommands();
    std::string prompt();
private:
    std::map<std::string, AbstractCommand*> cobjs;
    AbstractFileSystem* file_system;
    AbstractFileFactory* file_factory;
public:
    CommandPrompt();
    ~CommandPrompt();
    void setFileSystem(AbstractFileSystem* fs);
    void setFileFactory(AbstractFileFactory* ff);
    int addCommand(std::string, AbstractCommand* command);
    int run();
};