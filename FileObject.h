#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <chrono>

using namespace std;
using TimePoint = chrono::system_clock::time_point;

class FileObject
{
public:
 
 	FileObject(const string& name);
	virtual ~FileObject()=default;
	friend ostream& operator<<(ostream& os, const FileObject& rhs);
	void virtual display() const = 0;
	size_t virtual getSize() const = 0;
	TimePoint getTimeCreated() const { return timeCreated; }
	TimePoint getTimeModified() const { return timeModified; } 

	string getName() const { return name; }
private:
	string name;
	TimePoint timeCreated;
	TimePoint timeModified;

};

 