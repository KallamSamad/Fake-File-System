#include <iostream>
#include "FileObject.h"
#include "Directory.h"
#include "IndividualFile.h"
#include "Console.h"

int main()
{
    Directory root("Root");

    root.add(new IndividualFile(100, "document.txt"));
    root.add(new IndividualFile(500, "image.png"));
    root.add(new IndividualFile(900, "video.mp4"));

    Directory* documents = new Directory("Documents");
    Directory* downloads = new Directory("Downloads");
    Directory* coursework = new Directory("Coursework");

    documents->add(new IndividualFile(200, "essay.docx"));
    documents->add(new IndividualFile(300, "notes.txt"));

    downloads->add(new IndividualFile(400, "installer.exe"));
    downloads->add(new IndividualFile(600, "archive.zip"));

    coursework->add(new IndividualFile(1000, "project.cpp"));
    coursework->add(new IndividualFile(2000, "assignment.pdf"));

    documents->add(coursework);

    Console console(root);
    console.run();

    return 0;
}