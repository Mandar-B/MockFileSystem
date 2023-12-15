#include <iostream>
#include <iomanip>
#include <string>

#include "../include/mockos/LSCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* lfs)
        : file_system(lfs) {

}

void LSCommand::displayInfo() {
    cout << "ls displays all files in the current directory. Add the `-m` flag to display the metadata of each file" << endl;
}



int LSCommand::execute(std::string flags) {
    set<string> files = file_system->getFileNames();


    if (flags == "-m") {
        MetadataDisplayVisitor* mdv = new MetadataDisplayVisitor;
        for (std::string fileName : files) {
            AbstractFile* file = file_system->openFile(fileName);
            cout<<fileName;
            if (file==nullptr) {
                return UFILE;

            }
            file->accept(mdv);
            file_system->closeFile(file);
        }
    } else {
        int i = 0;
        for (std::string fileName : files) {
            if (i % 2 == 0) {
                cout << left << setw(FNAME_WIDTH) << fileName;
            } else {
                cout << right << setw(FNAME_WIDTH) << fileName << "\n";
            }
            ++i;
        }

        if (i % 2 != 0) {
            cout << "\n";
        }
    }

    return OK;
}
