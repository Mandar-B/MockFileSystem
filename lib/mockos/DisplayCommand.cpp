#include <iostream>
#include <iomanip>
#include <string>

#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
  : file_system(fs), file_factory(ff) {
    
}

void DisplayCommand::displayInfo() {
    cout << "ds" << endl;
}

int DisplayCommand::execute(std::string flags) {
    // TODO
    return OK;
}
