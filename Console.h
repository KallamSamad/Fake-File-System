#pragma once
#include <iostream>
#include <string>
#include "Directory.h"

using namespace std;

class Console
{
 

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
    enum class Command {
        DIR,
        SORTSIZE,
        SORTNAME,
        CD,
        MKDIR,
        MKFILE,
        DEL,
        EXIT,
        INVALID
    };
public:
    Console(Directory& root);
    static string toLower(string input);
    Command parseCommand(const string& input) const;
    void run();
};