#include <iostream>
#include <iomanip>
#include <string>

#include "../include/mockos/LSCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* fs, AbstractFileFactory* ff)
  : file_system(fs), file_factory(ff) {
    
}

void LSCommand::displayInfo() {
    cout << "ls displays all files in the current directory. Add the `-m` flag to display the metadata of each file" << endl;
}

int LSCommand::execute(std::string flags) {
    set<string>::iterator itr;
    set<string> files = file_system->getFileNames();
    int i = 0;
    for (itr = files.begin(); itr != files.end(); ++itr) {
        if (flags == "-m") {
            MetadataDisplayVisitor mdv();
            AbstractFile* cfile = file_system->openFile(*itr);
            cout << *itr << endl; // TODO: properly utilize metadata visitor 
        } else {
            cout << (i % 2 ? left : right) << setw(FNAME_WIDTH) << *itr << (i % 2 ? "" : "\n");
        }
        ++i;
    }
    return OK;
}
