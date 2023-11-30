#include "mockos/SimpleFileFactory.h"
#include "mockos/TextFile.h"  // Include the header for the TextFile class
#include "mockos/ImageFile.h" // Include the header for the ImageFile class

AbstractFile* SimpleFileFactory::createFile(const std::string& fileName) {
    // Determine the file extension by finding the position of the last dot in the file name
    int dotPosition = fileName.find_last_of('.');

    if (dotPosition == std::string::npos) {
        return nullptr;
    }


    std::string fileExtension = fileName.substr(dotPosition + 1);


    if (fileExtension == "txt") {
        return new TextFile(fileName);
    } else if (fileExtension == "img") {
        return new ImageFile(fileName);
    }


    return nullptr;
}