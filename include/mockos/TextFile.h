#ifndef TEXTFILE_H
#define TEXTFILE_H

#include "AbstractFile.h"
#include <vector>
#include <string>

using namespace std;

class TextFile : public AbstractFile {
private:
    vector<char> contents;
    string name;

public:
    TextFile(string filename);
    virtual ~TextFile() = default;

    virtual void read() const override;
    virtual int write(const vector<char>& data) override;
    virtual int append(const vector<char>& data) override;
    virtual unsigned int getSize() const override;
    virtual string getName() const override;
};

#endif