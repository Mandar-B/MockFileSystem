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

        if (pf == nullptr) {
            file_system->closeFile(f);
            return PRMCS;
        }


        if (perms[0] != '+' && perms[0] != '-') {
            file_system->closeFile(f);
            return NARGS;
        }
        
        bool should_add = perms[0] == '+';

        for (int i = 0; i < perms.length(); ++i) {
            if (perms[i] == 'r')
                pf->setRead(should_add);
            else if (perms[i] == 'w')
                pf->setWrite(should_add);
            else if (perms[i] == 'x')
                pf->setExecute(should_add);
        }

        file_system->closeFile(pf);
    }

    return OK;
}