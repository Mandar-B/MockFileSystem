#pragma once

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
    void setFileSystem(AbstractFileSystem*);
    void setFileFactory(AbstractFileFactory*);
    int addCommand(std::string, AbstractCommand*);
    int run();
};