#include <iostream>
#include "FileObject.h"
#include "Directory.h"
#include "IndividualFile.h"
#include "Console.h"
#include "Storage.h"

int main()
{
    Directory root("Root");

    Storage storage;
    storage.load(root);


    Console console(root);
    console.run();

    storage.save(root);

    return 0;
}