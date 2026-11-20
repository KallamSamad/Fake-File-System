#pragma once
#include "Directory.h"
#include "FileObject.h"
#include "IndividualFile.h"
 
 


Directory::Directory(const std::string& name, size_t capacity)
    : FileObject(name), capacity(capacity)
{
    fileList = new FileObject * [capacity]();
}

Directory::Directory(const string& name, TimePoint created, TimePoint modified)
    : FileObject(name, created, modified), capacity(2)
{
    fileList = new FileObject * [capacity];
}
Directory::~Directory()
{

    for (int i = 0; i < count; i++) {
        delete fileList[i];
    }
    delete[] fileList;
}

size_t Directory::getSize() const
{
    size_t totalSize = 0;

    for (size_t i = 0; i < count; i++)
    {
        totalSize += fileList[i]->getSize();
    }

    return totalSize;
}

void displayTime(ostream& os, TimePoint time)
{
    time_t converted = chrono::system_clock::to_time_t(time);

    tm timeInfo{};

    localtime_s(&timeInfo, &converted);

    os << put_time(&timeInfo, "%d/%m/%Y %H:%M");
}


void Directory::display() const
{
    display(cout);
}

void Directory::display(ostream& os) const
{
    os << left
        << setw(19) << "Time Created"
        << setw(20) << "Time Modified"
        << setw(16) << "Name"
        << "Size\n";

    size_t fileCount = 0;
    size_t dirCount = 0;
    size_t totalBytes = 0;



    for (size_t i = 0; i < count; i++)
    {
        

        displayTime(os, fileList[i]->getTimeCreated());
        os << " | ";

        displayTime(os, fileList[i]->getTimeModified());
        os << " | ";

        os << left
            << setw(16) << fileList[i]->getName()
            << " | ";
         
        if (fileList[i]->isDirectory()) {
            os << "<DIR>";
        }
        else {
            os << fileList[i]->getSize();
        }

        os << '\n';
        if (dynamic_cast<IndividualFile*>(fileList[i]))
        {
            fileCount++;
            totalBytes += fileList[i]->getSize();
        }
        else if (dynamic_cast<Directory*>(fileList[i]))
        {
            dirCount++;
        }
  
    }
    os << fileCount << " File(s)  "
        << totalBytes << " total bytes\n";

    os << dirCount << " Dir(s)\n";
}
void Directory::add(FileObject* file) {
    updateModifiedTime();

    if (count == capacity) {
        resize();
    }
   

        fileList[count] = file;
        count++;
    
   
}

void Directory::resize() {
    capacity = capacity * 2;
    FileObject** newArray = new FileObject*[capacity]();

    for (int i = 0; i < count; i++) {
        newArray[i] = fileList[i];
    }
    delete[] fileList;
    fileList = newArray;


}
void Directory::clear()
{
    for (size_t i = 0; i < count; i++)
    {
        delete fileList[i];
        fileList[i] = nullptr;
    }

    count = 0;
    updateModifiedTime();
}

bool Directory::isDirectory() const {
    return true;
}

FileObject* Directory::getFile(size_t index) const
{
    if (index >= count)
        return nullptr;

    return fileList[index];
}

size_t Directory::getCount() const
{
    return count;
}