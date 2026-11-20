#pragma once
#include "Directory.h"
#include "FileObject.h"
#include "IndividualFile.h"
 
 


Directory::Directory(const std::string& name, size_t capacity)
    : FileObject(name), capacity(capacity)
{
    fileList = new FileObject * [capacity]();
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
void displayTime(TimePoint time)
{
    time_t converted = chrono::system_clock::to_time_t(time);

    tm timeInfo{};
    localtime_s(&timeInfo, &converted);

    cout << put_time(&timeInfo, "%d/%m/%Y %H:%M");
}

void Directory::display() const
{
    cout << left
        << setw(19) << "Time Created"
        << setw(20) << "Time Modified"
        << setw(16) << "Name"
        << "Size\n";

    for (size_t i = 0; i < count; i++)
    {
        displayTime(fileList[i]->getTimeCreated());
        cout << " | ";

        displayTime(fileList[i]->getTimeModified());
        cout << " | ";

        cout << left
            << setw(16) << fileList[i]->getName()
            << " | ";

        if (fileList[i]->isDirectory()) {
            cout << "<DIR>";
        }
        else {
            cout << fileList[i]->getSize();
        }

        cout << '\n';
    }
}
void Directory::add(FileObject* file) {

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

bool Directory::isDirectory() const {
    return true;
}