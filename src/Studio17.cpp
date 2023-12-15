#include <iostream>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"


#include "mockos/SimpleFileSystem.h"
#include <iostream>

int main() {
    // Test 1: Create an ImageFile instance
    ImageFile imageFile("test_image.txt");

    // Test 2: Write to the file
    std::vector<char> imageData = {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X', '3'};
    int writeResult = imageFile.write(imageData);

    if (writeResult == 0) {
        std::cout << "Write successful!" << std::endl;
    } else {
        std::cerr << "Error writing to the file. Error code: " << writeResult << std::endl;
        return 1;
    }

    // Test 3: Display the content
    std::cout << "Image content:" << std::endl;
    imageFile.read();
    std::cout << std::endl;

    // Test 4: Invalid write with incorrect size
    std::vector<char> invalidData = {'X', ' ', 'X', ' ', '2'}; // Missing size
    int invalidWriteResult = imageFile.write(invalidData);

    if (invalidWriteResult != 0) {
        std::cout << "Invalid write attempt caught. Error code: " << invalidWriteResult << std::endl;
    }

    // Test 5: Display the content after invalid write
    std::cout << "Image content after invalid write:" << std::endl;
    imageFile.read();
    std::cout << std::endl;

    // Add more tests as needed

    return 0;
}
