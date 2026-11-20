#include <algorithm>
#include "Console.h"
#include <cctype>

using namespace std;

 

Console::Console(Directory& root)
    : root(root), currentDirectory(&root)
{
}
Console::Command Console::parseCommand(const string& input) const
{
    if (input == "dir") return Command::DIR;
    if (input == "sortsize") return Command::SORTSIZE;
    if (input == "sortname") return Command::SORTNAME;
    if (input == "cd") return Command::CD;
    if (input == "mkdir") return Command::MKDIR;
    if (input == "mkfile") return Command::MKFILE;
    if (input == "del") return Command::DEL;
    if (input == "exit") return Command::EXIT;

    return Command::INVALID;
}

string Console::toLower(string input)
{
    for (char& c : input)
        c = static_cast<char>(tolower(static_cast<unsigned char>(c)));

    return input;
}

 
void Console::run()
{
    string input;

 
    do {
        cout << "Initialisation Complete.....\n";
        cout << "\\ : > ";

        cin >> input;
        input = Console::toLower(input);

        Command command = parseCommand(input);

        switch (command) {
        case Command::DIR:
            dir();
            break;

        case Command::SORTSIZE:
            sortSize();
            break;

        case Command::SORTNAME:
            sortName();
            break;

        case Command::CD:
        {
            string name;
            cin >> name;
            cd(name);
            break;
        }

        case Command::MKDIR:
        {
            string name;
            cin >> name;
            mkdir(name);
            break;
        }

        case Command::MKFILE:
        {
            string name;
            cin >> name;
            mkfile(name);
            break;
        }

        case Command::DEL:
        {
            string name;
            cin >> name;
            del(name);
            break;
        }

        case Command::EXIT:
            return;

        default:
            cout << "Invalid command\n";
            break;
        }

    } while (true);
}


void Console::dir()
{
    currentDirectory->display(cout);
}

void Console::sortSize() {

}
void Console::sortName() {

}
void Console::cd(const string& name) {

}
void Console::mkdir(const string& name) {

}
void Console::mkfile(const string& name) {

}
void Console::del(const string& name) {

}