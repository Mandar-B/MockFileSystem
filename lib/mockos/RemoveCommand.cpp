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

RemoveCommand::RemoveCommand(AbstractFileSystem* sfs)
        : file_system(sfs) {}

void RemoveCommand::displayInfo() {
    std::cout << "rm removes a file, usage: rm <filename>" << std::endl;
}

int RemoveCommand::execute(std::string flags) {
    if (flags == "") return NARGS;

    istringstream ss(flags);
    string fname;
    if (!(ss >> fname)) return NARGS;

    return file_system->deleteFile(fname);
}
