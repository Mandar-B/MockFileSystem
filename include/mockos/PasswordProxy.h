#pragma once

#include <string>

class PasswordProxy : public AbstractFile {
private:
    AbstractFile* file_ptr;
    std::string password;
public:
    PasswordProxy(AbstractFile* fp, std::string pwd);
    ~PasswordProxy();
    unsigned int getSize() const override;
    std::string getName() const override;
    int write(const std::vector<char>& data) override;
    int append(const std::vector<char>& data) override;
    std::vector<char> read() const override;
    void accept(AbstractFileVisitor* fv) override;
    AbstractFile* copy(std::string) const override;
protected:
    std::string passwordPrompt() const;
};