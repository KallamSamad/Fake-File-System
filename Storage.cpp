#include <iostream>
#include <fstream>
#include "Directory.h"
#include "FileObject.h"
#include "IndividualFile.h"
#include "Storage.h"

using namespace std;

void Storage::save(const Directory& root) {
    ofstream file("Files.txt");

    if (file.is_open()) {

        root.display(file);
        file.close();

        cout << "File saved successfully!\n";
    }
    else {
        cout << "Failed to open Files.txt\n";
    }
}