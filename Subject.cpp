#include "Subject.h"

void ASubject::Attach(ObserverFile *newFile)
{
    list.push_back(newFile);
}

void ASubject::Detach(ObserverFile *removedFile)
{
    list.removeAll(removedFile);
}

void ASubject::Notify(int statusFile, int size)
{
    for (int i = 0; 0 < list.size(); i++)
        if (list[i] != 0)
            list[i]->update(statusFile, size);
}


void MyFile::ChangeSize(int statusFile, int size)
{
    Notify(statusFile, size);
}
