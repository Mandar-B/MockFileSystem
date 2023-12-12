#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/Constants.h"

#include <string>
#include <set>

using namespace std;

SimpleFileSystem::SimpleFileSystem(){

}
SimpleFileSystem::~SimpleFileSystem(){

}



int SimpleFileSystem::addFile(const string& filename, AbstractFile* file) {
    // check if the file already exists
    if (filesMap.find(filename) != filesMap.end()) {
        return FLEXI;
    }


    if (!file) {
        return UFILE;
    }


    filesMap[filename] = file;
    return 0;
}

int SimpleFileSystem::createFile(const string& filename) {

    if (filesMap.find(filename) != filesMap.end()) {
        return FLEXI;
    }


    size_t dotPosition = filename.find_last_of('.');
    if (dotPosition == string::npos || dotPosition == 0 || dotPosition == filename.length() - 1) {
        return UFLFM;
    }

    string extension = filename.substr(dotPosition + 1);

    // Create the appropriate file type based on the extension
    AbstractFile* newFile = nullptr;
    if (extension == "txt") {
        newFile = new TextFile(filename);
    } else if (extension == "img") {
        // Assuming you have an ImageFile class
        newFile = new ImageFile(filename);
    } else {
        return UEXTN; // Error code for unsupported file extension
    }

    // Add the file to the file system
    filesMap[filename] = newFile;
    return 0; // Return 0 for a successful create
}

int SimpleFileSystem::deleteFile(const string& filename) {
    // Check if the file exists
    auto it = filesMap.find(filename);
    if (it == filesMap.end()) {
        return UFILE; // Error code for file not found
    }

    // Check if the file is open
    AbstractFile* fileToDelete = it->second;
    if (openFiles.find(fileToDelete) != openFiles.end()) {
        return NODEL; // Error code for file is open
    }

    // Delete the file and remove it from the file system
    delete fileToDelete;
    filesMap.erase(it);

    return OK; // Return OK for a successful delete
}

AbstractFile* SimpleFileSystem::openFile(const string& filename) {
    // Check if the file exists
    auto it = filesMap.find(filename);
    if (it == filesMap.end()) {
        return nullptr; // File not found
    }

    // Check if the file is already open
    AbstractFile* fileToOpen = it->second;
    if (openFiles.find(fileToOpen) != openFiles.end()) {
        return nullptr; // File is already open
    }

    // Add the file to the set of open files
    openFiles.insert(fileToOpen);

    return fileToOpen;
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
    // Check if the file is open
    auto it = openFiles.find(file);
    if (it == openFiles.end()) {
        return FCLSD; // Error code for file not open
    }

    // Remove the file from the set of open files
    openFiles.erase(it);

    return OK;
}

set<string> SimpleFileSystem::getFileNames() {
    set<string> out;
    map<string, AbstractFile*>::iterator it;
    for (it = filesMap.begin(); it != filesMap.end(); ++it) {
        out.insert(it->first);
    }
}