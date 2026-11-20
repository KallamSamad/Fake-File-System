#include "IndividualFile.h"
#include "FileObject.h"
#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <ctime>


IndividualFile::IndividualFile(size_t bytes, const string& name)
    : FileObject(name), bytes(bytes)
{
}
IndividualFile::IndividualFile(size_t bytes, const string& name, TimePoint created, TimePoint modified) : FileObject(name, created, modified), bytes(bytes) {}
 
 
void IndividualFile::display() const
{
    TimePoint created = getTimeCreated();
    TimePoint modified = getTimeModified();
}



bool IndividualFile::isDirectory() const {
    return false;
}