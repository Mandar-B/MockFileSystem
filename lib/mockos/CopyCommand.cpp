#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "../include/mockos/CopyCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"

using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* fs)
        : file_system(fs) {

}

void CopyCommand::displayInfo() {
    cout << "cp copies the contents of one file to a new file with the specified title. destination file name should not include the file extension. command format: cp <original_file> <destination_name>" << endl;
}

int CopyCommand::execute(std::string args) {
    if (args == "") return NARGS;

    std::istringstream ss(args);

    std::string originalName, newName;

    if (!(ss >> originalName >> newName)) return NARGS;

    AbstractFile* originalFile = file_system->openFile(originalName);

    if (originalFile == nullptr) {
        std::cout << "File to copy does not exist" << std::endl;
        return UFILE;
    }

    AbstractFile* copy = originalFile->copy(newName);

    if (copy == nullptr) {
        std::cout << "Copy failed" << std::endl;
        file_system->closeFile(originalFile);
        return COPFL;
    }
    file_system->closeFile(originalFile);
    int result = file_system->addFile(copy->getName(), copy);


    return result;
}
