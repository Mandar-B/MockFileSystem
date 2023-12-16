#include <iostream>
#include <string>
#include <vector>
#include "mockos/SimpleFileSystem.h"
#include "mockos/Constants.h"
#include "mockos/SimpleFileFactory.h"
#include "mockos/CommandPrompt.h"
#include "mockos/TouchCommand.h"

void print_test(string name, int& num, int res) {
    cout << num++ << ": " << name << "\t" 
        << (res ? "ERROR; code " : "SUCCESS") << (res ? to_string(res) : "") << endl;
}

using namespace std;

int main() {
    SimpleFileSystem* fs = new SimpleFileSystem();
    SimpleFileFactory* ff = new SimpleFileFactory();
    TouchCommand* tc = new TouchCommand(fs, ff);

    cout << "Attempt to create invalid files with `touch`, then create a file called 'example.txt', a file called 'image.img', and a file called 'aLongerName.txt'" << endl;

    CommandPrompt cmd_prompt;
    cmd_prompt.setFileSystem(fs);
    cmd_prompt.setFileFactory(ff);
    cmd_prompt.addCommand("touch", tc);

    cmd_prompt.run();

    int test_num;

    AbstractFile* f1 = fs->openFile("example.txt");
    print_test("example.txt is created", test_num, f1 != nullptr);
    AbstractFile* f2 = fs->openFile("image.img");
    print_test("image.img is created", test_num, f2 != nullptr);
    AbstractFile* f3 = fs->openFile("aLongerName.txt");
    print_test("aLongerName.txt is created", test_num, f3 != nullptr);

    fs->closeFile(f1);
    fs->closeFile(f2);
    fs->closeFile(f3);

    AbstractFile* f1 = fs->openFile("example.txt");
    AbstractFile* f2 = fs->openFile("image.img");
    AbstractFile* f3 = fs->openFile("aLongerName.txt");

    cout << "No unexpected behaviour after closing and opening all files" << endl;

    return OK;
}
