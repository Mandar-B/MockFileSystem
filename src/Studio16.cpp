#include "mockos/TextFile.h"
#include <iostream>

int main() {

    TextFile textFile("ex.txt");


    std::vector<char> data = {'H', 'e', 'l', 'l', 'o'};
    int writeResult = textFile.write(data);

    if (writeResult == 0) {
        std::cout << "Write successful!";
    } else {
        std::cerr << "Error writing to the file.";
        return 1;
    }

    std::cout << "File content: ";
    textFile.read();

    // Test 3: Append to the file
    std::vector<char> dataToAppend = {' ', 'A', 'p', 'p', 'e', 'n', 'd'};
    int appendResult = textFile.append(dataToAppend);

    if (appendResult == 0) {
        std::cout << "Append success";
    } else {
        std::cerr << "error appending";
        return 1;
    }


    std::cout << "File content after append: ";
    textFile.read();

    return 0;
}
