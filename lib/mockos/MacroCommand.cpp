#include <iostream>
#include <iomanip>
#include <string>

#include "../include/mockos/MacroCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/AbstractParsingStrategy.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
  : file_system(fs), file_factory(ff) {
    
}

void MacroCommand::displayInfo() {
    cout << "macro" << endl;
}

int MacroCommand::execute(std::string flags) {
    vector<string> params = strategy->parse(flags);
    for (int i = 0; i < params.size(); ++i) {
        int res = commands[i]->execute(params[i]);
        if (res != OK)
            return res;
    }
    return OK;
}

void MacroCommand::addCommand(AbstractCommand* cmd) {
    commands.push_back(cmd);
}
