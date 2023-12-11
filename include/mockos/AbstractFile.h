#ifndef ABSTRACT_FILE_H
#define ABSTRACT_FILE_H

#include <vector>
#include <string>
class AbstractFileVisitor;
class AbstractFile {
public:
    virtual ~AbstractFile() = default; // Virtual destructor for proper polymorphism

    virtual unsigned int getSize() const = 0;
    virtual std::string getName() const = 0;
    virtual int write(const std::vector<char>&) = 0;
    virtual int append(const std::vector<char>&) = 0;
    virtual std::vector<char> read() const = 0;
    virtual void accept(AbstractFileVisitor*) = 0;
    virtual AbstractFile* copy(std::string) const = 0;
};

#endif // ABSTRACT_FILE_H
