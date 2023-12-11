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

    virtual vector<char> read() const override;
    virtual int write(const vector<char>& data) override;
    virtual int append(const vector<char>& data) override;
    virtual unsigned int getSize() const override;
    virtual string getName() const override;
    void accept(AbstractFileVisitor* visitor) override;
    AbstractFile* copy(std::string) const override;
};

#endif
// Include guards and #pragma once should not be repeated in the same file
