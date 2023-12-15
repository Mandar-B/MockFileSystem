#pragma once

#include <string>
#include "AbstractFile.h"

class PermissionFile : public AbstractFile {
private:
    AbstractFile* file_ptr;
    std::string password;
    bool can_write;
    bool can_read;
    bool can_execute;
public:
    PermissionFile(AbstractFile* fp);
    PermissionFile(AbstractFile* fp, bool cwrite, bool cread, bool cexecute);
    ~PermissionFile();
    unsigned int getSize() const override;
    std::string getName() const override;
    int write(const std::vector<char>& data) override;
    int append(const std::vector<char>& data) override;
    std::vector<char> read() const override;
    void accept(AbstractFileVisitor* fv) override;
    AbstractFile* copy(std::string) const override;
    void setWrite(bool);
    void setRead(bool);
    void setExecute(bool);
};