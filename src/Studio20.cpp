#include <iostream>
#include <string>
#include "mockos/Constants.h"
#include "mockos/ImageFile.h"
#include "mockos/TextFile.h"
#include "mockos/PasswordProxy.h"
#include "mockos/SimpleFileSystem.h"
#include "mockos/BasicDisplayVisitor.h"

using namespace std;

void print_test(string name, int& num, int res) {
    cout << num++ << ": " << name << "\t" 
        << (res ? "ERROR; code " : "SUCCESS") << (res ? to_string(res) : "") << endl;
}

int main() {

    int test_num = 0;

    cout << "Running Studio 20 Tests...\n" << endl;

    TextFile* textFile = new TextFile("ex.txt");
    PasswordProxy* proxy = new PasswordProxy(textFile, "somepassword");

    // Write a text file with "Hello" as its contents
    vector<char> data = {'H', 'e', 'l', 'l', 'o'};

    cout << "Provide a correct password to the following prompt:" << endl;

    int test_res = proxy->write(data);

    print_test("Test writing file [correct password]", test_num, test_res);

    // Read contents and update to be "Hello World"
    vector<char> contents = proxy->read();
    contents.push_back(' ');
    contents.push_back('W');
    contents.push_back('o');
    contents.push_back('r');
    contents.push_back('l');
    contents.push_back('d');

    cout << "Provide a correct password to the following prompt:" << endl;

    // Rewrite file
    test_res = proxy->write(contents);

    print_test("Test rewriting file [correct password]", test_num, test_res);

    test_res = "ex.txt" == proxy->getName();

    print_test("Test getName()", test_num, test_res);

    cout << "Provide a correct password to the following prompt:" << endl;

    AbstractFileVisitor* fv = new BasicDisplayVisitor();
    proxy->accept(fv);

    print_test("Test accepting basic display visitor [correct password] CONFIRM MANUALLY", test_num, OK);

    cout << "Provide a correct password to the following prompt:" << endl;

    test_res = proxy->write(contents) != OK;

    print_test("Test rewriting file [incorrect password]", test_num, test_res);

    AbstractFileVisitor* fx = new BasicDisplayVisitor();
    proxy->accept(fx);

    print_test("Test accepting basic display visitor [incorrect password] CONFIRM MANUALLY", test_num, OK);

    return OK;
}
