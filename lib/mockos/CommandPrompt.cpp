#include <utility>
#include <iterator>
#include <algorithm>
#include <ostream>
#include <iostream>
#include <sstream>

#include "../include/mockos/CommandPrompt.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/AbstractCommand.h"
#include "../include/mockos/Constants.h"

using namespace std;

CommandPrompt::CommandPrompt() {
    file_system = nullptr;
    file_factory = nullptr;
}
CommandPrompt::~CommandPrompt() {


}

void CommandPrompt::setFileSystem(AbstractFileSystem* fs) {
    file_system = fs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* ff) {
    file_factory = ff;
}

int CommandPrompt::addCommand(string n, AbstractCommand* cmd) {
    pair<map<string, AbstractCommand*>::iterator, bool> ret = cobjs.insert({n, cmd});
    return ret.second ? OK : CMDIN;
}

void CommandPrompt::listCommands() {
    std::cout << "Available commands:" << std::endl;
    for (const auto& pair : cobjs) {
        std::cout << pair.first << std::endl;
    }
}

string CommandPrompt::prompt() {
    cout << "Provide a valid command, or use `q` to quit, `help` for a list of commands, or `help <command name>` for details on a specific command\n" << endl;
    cout << "$  ";
    string inp;
    getline(cin, inp);
    return inp;
}

int CommandPrompt::run() {
    do {
        std::string inp = prompt();

        if (inp == "q") {
            return QUIT;
        } else if (inp == "help") {
            listCommands();
        } else {
            if (inp.find(' ') != std::string::npos) {
                std::istringstream ss(inp);
                std::string w1;
                ss >> w1;

                if (w1 == "help") {
                    std::string w2;
                    ss >> w2;
                    if (cobjs.find(w2) != cobjs.end())
                        cobjs[w2]->displayInfo();
                    else
                        std::cout << "That command doesn't seem to exist! Use `help` to get a list of commands" << std::endl;
                } else {
                    if (cobjs.find(w1) != cobjs.end()) {
                        string remainder;
                        getline(ss,remainder);
                        int ret = cobjs[w1]->execute(remainder);

                        if (ret != OK)
                            std::cout << "There was an error running " << w1 << "(error code " << ret << " )! Use `help " << w1 << "` to get more info about how to use the command" << std::endl;
                    } else {
                        std::cout << "That command doesn't seem to exist! Use `help` to get a list of commands" << std::endl;
                    }
                }
            } else {
                if (cobjs.find(inp) != cobjs.end()) {
                    int ret = cobjs[inp]->execute("");
                    if (ret != OK)
                        std::cout << "There was an error running " << inp << "! Use `help " << inp << "` to get more info about how to use the command" << std::endl;
                } else {
                    std::cout << "That command doesn't seem to exist! Use `help` to get a list of commands" << std::endl;
                }
            }
        }
    } while (true);

    return OK;
}