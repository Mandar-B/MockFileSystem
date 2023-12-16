#include "mockos/SimpleFileSystem.h"
#include "mockos/TextFile.h"
#include "mockos/ImageFile.h"
#include "mockos/Constants.h"
#include <iostream>

int main() {
    AbstractFileSystem* fileSystem = new SimpleFileSystem();

    // Test Case 1: Create and add a TextFile
    std::cout << "Test Case 1: Create and add a TextFile";
    int result = fileSystem->createFile("test.txt");
    if (result == OK) {
        std::cout << "File 'test.txt' created successfully.";
    } else {
        std::cerr << "Error creating file: " << result ;
    }
cout<<endl;

    std::cout << "Test Case 2: Attempt to create a file with an invalid extension";
    result = fileSystem->createFile("File.invalidExtension");
    if (result == UEXTN) {
        std::cout << "Correctly detected invalid file extension.";
    } else {
        std::cerr << "Error creating file: " << result ;
    }

    cout<<endl;

    std::cout << "Test Case 3: Open an existing file";
    AbstractFile* openedFile = fileSystem->openFile("test.txt");
    if (openedFile != nullptr) {
        std::cout << "File 'test.txt' opened successfully";
    } else {
        std::cerr << "Error opening file";
    }

    cout<<endl;
    std::cout << "\nTest Case 4: Attempt to open a non-existing file";
    AbstractFile* nonExistingFile = fileSystem->openFile("nonExistingFile.txt");
    if (nonExistingFile == nullptr) {
        std::cout << "Correctly detected non-existing file";
    } else {
        std::cerr << "Error: Opened a non-existing file";
    }
    cout<<endl;


    result = fileSystem->closeFile(openedFile);
    if (result == OK) {
        std::cout << "File closed successfully";
    } else {
        std::cerr << "Error closing file: " << result;
    }
    cout<<endl;


    result = fileSystem->closeFile(openedFile);
    if (result == FCLSD) {
        std::cout << "Correctly detected attempt to close a non-open file";
    } else {
        std::cerr << "Error: Closed a file that was not open";
    }

    cout<<endl;



    result = fileSystem->deleteFile("test.txt");
    if (result == OK) {
        std::cout << "File 'test.txt' deleted successfully";
    } else {
        std::cerr << "Error deleting file: " << result ;
    }

    cout<<endl;
    std::cout << "Test Case 9: Attempt to delete a non-existing file";
    result = fileSystem->deleteFile("nonExistingFile.txt");
    if (result == UFILE) {
        std::cout << "detected attempt to delete a non-existing file";
    } else {
        std::cerr << "Deleted a non-existing file";
    }




    return 0;
}
