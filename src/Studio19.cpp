#include <iostream>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"


#include "mockos/SimpleFileSystem.h"
#include <iostream>

int main() {
    TextFile textFile("ex.txt");

    // Write a text file with "Hello" as its contents
    std::vector<char> data = {'H', 'e', 'l', 'l', 'o'};
    int writeResult = textFile.write(data);

    // Read contents and update to be "Hello World"
    std::vector<char> contents = textFile.read();
    contents.push_back(' ');
    contents.push_back('W');
    contents.push_back('o');
    contents.push_back('r');
    contents.push_back('l');
    contents.push_back('d');

    // Rewrite file
    writeResult = textFile.write(contents);

    std::cout << "Test rewriting file\t" 
        << (writeResult ? "ERROR while rewriting file" : "SUCCESS") << std::endl;

    return 0;
}
