#include "mockos/TextFile.h"
#include <iostream>

int main() {
    // Test 1: Create TextFile and write data
    TextFile textFile("ex.txt");

    std::vector<char> data = {'H', 'e', 'l', 'l', 'o'};
    int writeResult = textFile.write(data);

    if (writeResult == 0) {
        std::cout << "Write successful!" << std::endl;
    } else {
        std::cerr << "Error writing to the file." << std::endl;
        return 1;
    }

    // Display file content after Test 1
    std::cout << "File content after Test 1: ";
    textFile.read();
    std::cout << std::endl;

    // Test 2: Read from the file
    std::cout << "File content: ";
    textFile.read();
    std::cout << std::endl;

    // Test 3: Append to the file
    std::vector<char> dataToAppend = {' ', 'A', 'p', 'p', 'e', 'n', 'd'};
    int appendResult = textFile.append(dataToAppend);

    if (appendResult == 0) {
        std::cout << "Append success" << std::endl;
    } else {
        std::cerr << "Error appending to the file." << std::endl;
        return 1;
    }

    // Display file content after Test 3
    std::cout << "File content after Test 3: ";
    textFile.read();
    std::cout << std::endl;

    // Test 4: Read after append
    std::cout << "File content after append: ";
    textFile.read();
    std::cout << std::endl;

    // Test 5: Get file size and name
    std::cout << "File size: " << textFile.getSize() << " bytes" << std::endl;
    std::cout << "File name: " << textFile.getName() << std::endl;

    return 0;
}
