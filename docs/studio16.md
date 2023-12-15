# Studio 16
1) An interface is declared using an abstract class. An abstract class is a class that has atleast 1 pure virtual function, and it cannot be instantiated on its own. The abstract class serves as a base class which provides a sort of blue print for the concrete classes that inherit from it. These concrete classes can be instantiated.

2) This is an example of "interface inheritance." When a class inherits publicly from an abstract base class that declares a set of pure virtual functions, it is considered interface inheritance. TextFile inherits the interface of AbstractFile and provides concrete implementations for all the pure virtual functions declared in the base class.

3) The member variables should be kept private. As they are specific to the class, you do not want them to be altered from outside of the class. However, using methods like getName(), the member variables can still be accessed without being changed.

4) You can utilize a pointer to the abstract base class. This way, main can interact with any file type derived from AbstractFile without knowing the specific derived type at compile time.

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

