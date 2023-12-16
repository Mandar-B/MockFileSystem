#include "mockos/SimpleFileSystem.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/TextFile.h"
#include "mockos/Constants.h"
#include <iostream>
using namespace std;
int main() {
    // Initialize a SimpleFileSystem and SimpleFileFactory
    AbstractFileSystem* fileSystem = new SimpleFileSystem();
    AbstractFileFactory* fileFactory = new SimpleFileFactory();

    // Test Case 1: Create and Add TextFiles
    int createResult1 = fileSystem->createFile("file1.txt");
    int createResult2 = fileSystem->createFile("file2.txt");

    // Add files to the file system
    int addResult1 = fileSystem->addFile("file1.txt", fileFactory->createFile("file1.txt"));
    int addResult2 = fileSystem->addFile("file2.txt", fileFactory->createFile("file2.txt"));

    // Print results
    cout << "Test Case 1 Results:" << endl;
    cout << "Create file1.txt result: " << createResult1 << endl;
    cout << "Create file2.txt result: " << createResult2 << endl;
    cout << "Add file1.txt result: " << addResult1 << endl;
    cout << "Add file2.txt result: " << addResult2 << endl;

    // Test Case 2: Open, Write, and Read from TextFiles
    AbstractFile* file1 = fileSystem->openFile("file1.txt");
    AbstractFile* file2 = fileSystem->openFile("file2.txt");

    // Check if files were opened successfully
    if (file1 != nullptr && file2 != nullptr) {
        // Write data to file1.txt
        vector<char> dataToWrite = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd', '!'};
        int writeResult = file1->write(dataToWrite);
        cout << "Write to file1.txt result: " << writeResult << endl;

        // Read from file1.txt
        vector<char> file1Contents = file1->read();
        cout << "Contents of file1.txt: ";
        for (char c : file1Contents) {
            cout << c;
        }
        cout << endl;

        // Read from file2.txt (expecting empty contents)
        vector<char> file2Contents = file2->read();
        cout << "Contents of file2.txt: ";
        for (char c : file2Contents) {
            cout << c;
        }
        cout << endl;

        // Close the files
        fileSystem->closeFile(file1);
        fileSystem->closeFile(file2);
    } else {
        std::cout << "Failed to open files for reading and writing." << std::endl;
    }

    // Clean up
    delete fileSystem;
    delete fileFactory;

    return 0;
}
