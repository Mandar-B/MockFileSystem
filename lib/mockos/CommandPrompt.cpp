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

using namespace std;

CommandPrompt::CommandPrompt() {
    file_system = nullptr;
    file_factory = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* fs) {
    file_system = fs;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* ff) {
    file_factory = ff;
}

int CommandPrompt::addCommand(string n, AbstractCommand* cmd) {
    pair<map<string, AbstractCommand*>::iterator, bool> ret = cobjs.insert({n, cmd});
    return ret.second ? 0 : 4;
}

void CommandPrompt::listCommands() {
    copy(begin(cobjs), end(cobjs), ostream_iterator<string>(cout, "\n"));
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
        string inp = prompt();

        if (inp == "q")
            return 0;
        else if (inp == "help")
            listCommands();
        else {
            if (inp.find(' ') != string::npos) {
                istringstream ss(inp);
                string w1;
                ss >> w1;

                if (w1 == "help") {
                    string w2;
                    ss >> w2;
                    if (cobjs.find(w2) != cobjs.end())
                        cobjs[w2]->displayInfo();   
                    else
                        cout << "That command doesn't seem to exist! Use `help` to get a list of commands"; 
                } else {
                    if (cobjs.find(w1) != cobjs.end()) {
                        int ret = cobjs[w1]->execute(ss.str());
                        if (ret != 0) cout << "There was an error running " << w1 << "! Use `help " << w1 << "` to get more info about how to use the command" << endl;
                    } else
                        cout << "That command doesn't seem to exist! Use `help` to get a list of commands";
                }
            } else {
                if (cobjs.find(inp) != cobjs.end())
                    int ret = cobjs[inp]->execute("");   
                    if (ret != 0) cout << "There was an error running " << inp << "! Use `help " << inp << "` to get more info about how to use the command" << endl;
                else
                    cout << "That command doesn't seem to exist! Use `help` to get a list of commands";                 
            }
        }
    } while (1);
}

void 