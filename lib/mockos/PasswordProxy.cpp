#include <iostream>
#include <string>

#include "../include/mockos/PasswordProxy.h"
#include "../include/mockos/AbstractFile.h"

PasswordProxy::PasswordProxy(AbstractFile* fp, string pwd)
: file_ptr(fp), password(pwd) {}

PasswordProxy::~PasswordProxy() {
    delete file_ptr;
}

std::string PasswordProxy::passwordPrompt() const {
    std::cout << "Input a password: ";
    std::string pwd;
    std::cin >> pwd;
    return pwd;
}

unsigned int PasswordProxy::getSize() const {
    return file_ptr->getSize();
}

std::string PasswordProxy::getName() const  {
    return file_ptr->getName();
}

int PasswordProxy::write(const std::vector<char>& data)  {
    std::string pwd = passwordPrompt();
    if (pwd == password)
        return file_ptr->write(data);
    else
        return 1;
}

int PasswordProxy::append(const std::vector<char>& data)  {
    std::string pwd = passwordPrompt();
    if (pwd == password)
        return file_ptr->append(data);
    else
        return 2;
}

std::vector<char> PasswordProxy::read() const {
    std::string pwd = passwordPrompt();
    if (pwd == password)
        return file_ptr->read();
    else
        return std::vector<char>();
}

void PasswordProxy::accept(AbstractFileVisitor& fv)  {
    std::string pwd = passwordPrompt();
    if (pwd == password)
        return file_ptr->accept(fv);
}
