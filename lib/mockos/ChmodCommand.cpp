//
// Created by Mandar Brahmbhatt on 12/15/23.
//
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <ostream>
#include <iterator>

#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"
#include "../include/mockos/BasicDisplayVisitor.h"
#include "../include/mockos/PermissionFile.h"
#include "../include/mockos/ChmodCommand.h"


using namespace std;

ChmodCommand::ChmodCommand(AbstractFileSystem* fs)
        : file_system(fs) {

}

void ChmodCommand::displayInfo() {
    cout << "chmod <filename> [-|+][r][w][x]" << endl;
}

int ChmodCommand::execute(string args) {
    if (args == "") return NARGS;

    istringstream ss(args);

    string fname;
    string perms;

    if (!(ss >> fname)) return NARGS;
    if (!(ss >> perms)) return NARGS;

    AbstractFile* f = file_system->openFile(fname);

    if (f == nullptr)
        return UFILE;

    if (perms != "") {
        PermissionFile* pf = dynamic_cast<PermissionFile*>(f);

        if (pf == nullptr)
            return PRMCS;

        pf->setRead(false);
        pf->setWrite(false);
        pf->setExecute(false);
        for (char p : perms) {
            if (p == 'r') {
                pf->setRead(true);
            } else if (p == 'w') {
                pf->setWrite(true);
            } else if (p == 'x') {
                pf->setExecute(true);
            }
        }
        file_system->closeFile(pf);
    }

    return OK;
}