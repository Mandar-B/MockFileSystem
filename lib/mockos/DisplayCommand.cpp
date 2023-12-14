#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "../include/mockos/DisplayCommand.h"
#include "../include/mockos/Constants.h"
#include "../include/mockos/AbstractFileSystem.h"
#include "../include/mockos/AbstractFileFactory.h"
#include "../include/mockos/MetadataDisplayVisitor.h"
#include "../include/mockos/BasicDisplayVisitor.h"

using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* fs)
        : file_system(fs) {

}

void DisplayCommand::displayInfo() {
    std::cout << "ds <filename> [-d]" << std::endl;
}

int DisplayCommand::execute(std::string args) {
    if (args == "")
        return 1;

    std::istringstream ss(args);

    std::string fname;


    if (!(ss >> fname)) return 1;
    cout<<fname;
    AbstractFile* f = file_system->openFile(fname);

    if (f == nullptr) {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }

    std::string flag;
    ss >> flag;

    if (flag == "-d") {
        // Display unformatted data only
        std::vector<char> contents = f->read();
        std::copy(contents.begin(), contents.end(), std::ostream_iterator<char>(std::cout, ""));
        std::cout << std::endl;
    } else {
        // Display formatted contents
        std::cout << "Displaying formatted contents of file: " << fname << std::endl;
        AbstractFileVisitor* fv = new BasicDisplayVisitor();

        f->accept(fv);
        // You may want to implement a visitor pattern or other methods to display formatted contents
    }

    file_system->closeFile(f);

    return 0;
}