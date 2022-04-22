#ifndef SUBJECT_H
#define SUBJECT_H

#include <QList>
#include "Observer.h"


class ASubject
{
    QList<ObserverFile*> list;
public:
    void Attach(ObserverFile *newFile);
    void Detach(ObserverFile *removedFile);
    void Notify(int statusFile, int size);
};

class MyFile : public ASubject
{
public:
    void ChangeSize(int statusFile, int size);
};


#endif // SUBJECT_H
