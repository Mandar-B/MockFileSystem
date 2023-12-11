#include <iostream>
#include <string>

#include "../include/mockos/PasswordProxy.h"
#include "../include/mockos/AbstractFile.h"

using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* fp, string pwd)
: file_ptr(fp), password(pwd) {}

PasswordProxy::~PasswordProxy() {
    delete file_ptr;
}

string PasswordProxy::passwordPrompt() const {
    cout << "Input a password: ";
    string pwd;
    cin >> pwd;
    return pwd;
}

unsigned int PasswordProxy::getSize() const {
    return file_ptr->getSize();
}

string PasswordProxy::getName() const  {
    return file_ptr->getName();
}

int PasswordProxy::write(const vector<char>& data)  {
    string pwd = passwordPrompt();
    if (pwd == password)
        return file_ptr->write(data);
    else
        return 1;
}

int PasswordProxy::append(const vector<char>& data)  {
    string pwd = passwordPrompt();
    if (pwd == password)
        return file_ptr->append(data);
    else
        return 2;
}

vector<char> PasswordProxy::read() const {
    string pwd = passwordPrompt();
    if (pwd == password)
        return file_ptr->read();
    else
        return vector<char>();
}

void PasswordProxy::accept(AbstractFileVisitor* fv)  {
    string pwd = passwordPrompt();
    if (pwd == password)
        return file_ptr->accept(fv);
}

AbstractFile* PasswordProxy::copy(string n) const {
    AbstractFile* nf = file_ptr->copy(n);
    PasswordProxy* cp = new PasswordProxy(nf, nf->getName());
    return cp;
}
