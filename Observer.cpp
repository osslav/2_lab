#include "Observer.h"
#include <QTextStream>

QTextStream cout(stdout);

ObserverFile::ObserverFile(QString fileName)
{
    name = fileName;
    size = 0;
}

void ObserverFile::update(int statusFile, int sizeFile)
{
    size = sizeFile;
    switch(statusFile)
    {
    case 0:
        cout << "File \"" << name << "\" exist and not empty. Size: " << size << '\n';
        break;
    case 1:
        cout << "File \"" << name << "\" exist and was changed. New size: " << size << '\n';
        break;
    case 2:
        cout << "File \"" << name << "\" not exist.\n";
        break;
    }
}
