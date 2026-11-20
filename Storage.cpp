
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "Directory.h"
#include "FileObject.h"
#include "IndividualFile.h"
#include "Storage.h"

using namespace std;

string formatTime(TimePoint time)
{
    time_t converted = chrono::system_clock::to_time_t(time);
    tm timeInfo{};

    localtime_s(&timeInfo, &converted);

    ostringstream os;
    os << put_time(&timeInfo, "%d/%m/%Y %H:%M");

    return os.str();
}

TimePoint parseTime(const string& date, const string& time)
{
    tm timeInfo{};

    string combined = date + " " + time;
    istringstream ss(combined);

    ss >> get_time(&timeInfo, "%d/%m/%Y %H:%M");

    time_t converted = mktime(&timeInfo);

    return chrono::system_clock::from_time_t(converted);
}

void Storage::save(const Directory& root)
{
    ofstream file("Files.txt");

    if (!file.is_open())
    {
        cout << "Failed to open Files.txt\n";
        return;
    }

    saveDirectory(root, file);

    cout << "File saved successfully!\n";
}

void Storage::saveDirectory(const Directory& directory, ofstream& file)
{
    for (size_t i = 0; i < directory.getCount(); i++)
    {
        FileObject* current = directory.getFile(i);

        if (Directory* subDir = dynamic_cast<Directory*>(current))
        {
            file << "DIR|"
                << current->getName() << "|"
                << formatTime(current->getTimeCreated()) << "|"
                << formatTime(current->getTimeModified()) << "|"
                << 0 << '\n';

            saveDirectory(*subDir, file);
        }
        else
        {
            file << "FILE|"
                << current->getName() << "|"
                << formatTime(current->getTimeCreated()) << "|"
                << formatTime(current->getTimeModified()) << "|"
                << current->getSize() << '\n';
        }
    }
}void Storage::load(Directory& root)
{
    ifstream file("Files.txt");

    if (!file.is_open())
    {
        cout << "No save file found.\n";
        return;
    }

    root.clear();
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string type, name, createdStr, modifiedStr, sizeStr;

        getline(ss, type, '|');
        getline(ss, name, '|');
        getline(ss, createdStr, '|');
        getline(ss, modifiedStr, '|');
        getline(ss, sizeStr, '|');

        stringstream createdStream(createdStr);
        string createdDate, createdTime;
        createdStream >> createdDate >> createdTime;

        stringstream modifiedStream(modifiedStr);
        string modifiedDate, modifiedTime;
        modifiedStream >> modifiedDate >> modifiedTime;

        TimePoint created = parseTime(createdDate, createdTime);
        TimePoint modified = parseTime(modifiedDate, modifiedTime);

        if (type == "DIR")
        {
            root.add(new Directory(name, created, modified));
        }
        else if (type == "FILE")
        {
            root.add(new IndividualFile(stoul(sizeStr), name, created, modified));
        }
    }
}