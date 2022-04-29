#ifndef SUBJECT_H
#define SUBJECT_H

#include <QFile>
#include <QList>
#include "Observer.h"


class ASubject
{
    QList<ObserverFile*> list;
public:
    void attach(ObserverFile *newFile);
    void detach(ObserverFile *removedFile);
    void notify(int statusFile, int size);
};

class MyFile : public ASubject
{
    QFile file;
public:
    MyFile(QString fileName) : file(fileName) {};
    void updateObservers();
};


#endif // SUBJECT_H
