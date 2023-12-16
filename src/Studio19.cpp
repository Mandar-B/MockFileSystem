#include <iostream>
#include <string>
#include <vector>
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/BasicDisplayVisitor.h"
#include "mockos/MetadataDisplayVisitor.h"
#include "mockos/SimpleFileSystem.h"

void print_test(string name, int& num, int res) {
    cout << num++ << ": " << name << "\t" 
        << (res ? "ERROR; code " : "SUCCESS") << (res ? to_string(res) : "") << endl;
}

int main() {
    // Create TextFile
    TextFile ft("text.txt");

    const string inp_str = "some initial example input"; 
    const vector<char> data(inp_str.begin(), inp_str.end());

    ft.write(vector<char>());

    vector<char> contents = ft.read();

    for (char c : contents) {
        cout << c;
    }
    cout << endl;

    ft.write(data);

    contents = ft.read();

    for (char c : contents) {
        cout << c;
    }
    cout << endl;

    contents[3] = 'X';
    contents[7] = 'Z';

    ft.write(contents);

    contents = ft.read();

    for (char c : contents) {
        cout << c;
    }
    cout << endl;

    // Create MetadataDisplayVisitor
    MetadataDisplayVisitor metadataDisplayVisitor;

    ft.accept(&metadataDisplayVisitor);

    ImageFile img("image.img");

    const string image_content = "X  X  X  X3";
    const vector<char> data2(image_content.begin(), image_content.end());

    img.write(data2);

    img.accept(&metadataDisplayVisitor);

    return 0;
}