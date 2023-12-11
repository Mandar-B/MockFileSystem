#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "../include/mockos/RemoveCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
  : file_system(fs), file_factory(ff) {
    
}

void RemoveCommand::displayInfo() {
    cout << "rm removes the specified file from the directory" << endl;
}

int RemoveCommand::execute(std::string flags) {
    if (flags == "")
        return NARGS;

    istringstream ss(flags);
    string fname;
    ss >> fname;

    return file_system->deleteFile(fname);
}
