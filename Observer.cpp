#include "Observer.h"
#include <QTextStream>

ObserverFile::ObserverFile(QString fileName)
{
    name = fileName;
    size = 0;
    fileExist = false;
}

void ObserverFile::update(bool isExistFile, int sizeFile)
{       
    QTextStream cout(stdout);

    if (isExistFile)
        if (size == sizeFile)
            if (size != 0)
                cout << "File \"" << name << "\" exist and not empty. Size: " << sizeFile << '\n';
            else
                cout << "File \"" << name << "\" exist and empty.\n";
        else
            cout << "File \"" << name << "\" exist and was changed. New size: " << sizeFile << '\n';
    else
        cout << "File \"" << name << "\" not exist.\n";

    size = sizeFile;
    fileExist = isExistFile;
}
