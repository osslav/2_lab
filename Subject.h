#ifndef SUBJECT_H
#define SUBJECT_H

#include <QFile>
#include <QTextStream>
#include <QList>
#include "Observer.h"

enum class ErrorCodeSubjects
{
    errorStreamInWrite,
    errorStreamInRead,

    errorFileIsNotWritable,
    errorFileIsNotReadable
};

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

    QString read();
    void write(const QString& str);
};


#endif // SUBJECT_H
