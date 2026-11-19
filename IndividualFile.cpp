#include "IndividualFile.h"
#include "FileObject.h"
#include <iostream>
#include <string>
#include <chrono>

IndividualFile::IndividualFile(size_t bytes, const string& name)
    : FileObject(name), bytes(bytes)
{
}

void IndividualFile::display() const
{
    std::cout << "File size: " << bytes << " bytes\n";
}