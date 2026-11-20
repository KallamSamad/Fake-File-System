#include "Console.h"


 

Console::Console(Directory& root)
    : root(root), currentDirectory(&root)
{
}

void Console::run()
{
    string command;

    do {

        cout << "Initialisation Complete" << "\n";
        cout << "> ";
        cin >> command;

        if (command == "dir") {
            dir();
        }
        else if (command == "sortsize") {
            sortSize();
        }
        else if (command == "sortname") {
            sortName();
        }

    } while (command != "7");
}


void Console::dir() {

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