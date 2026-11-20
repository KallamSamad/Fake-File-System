#pragma once
#include <iostream>
#include <string>
#include "Directory.h"

using namespace std;

class Console
{
public:
    Console(Directory& root);
    void run();

private:
    void dir();
    void sortSize();
    void sortName();
    void cd(const string& name);
    void mkdir(const string& name);
    void mkfile(const string& name);
    void del(const string& name);

    Directory& root;
    Directory* currentDirectory;
};