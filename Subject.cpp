#include "Subject.h"

void ASubject::attach(ObserverFile *newFile)
{
    list.push_back(newFile);
}

void ASubject::detach(ObserverFile *removedFile)
{
    list.removeAll(removedFile);
}

void ASubject::notify(int statusFile, int size)
{
    for (int i = 0; i < list.size(); i++)
        if (list[i] != 0)
            list[i]->update(statusFile, size);
}


void MyFile::updateObservers()
{
    notify(file.exists(), file.size());
}
