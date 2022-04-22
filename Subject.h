#ifndef SUBJECT_H
#define SUBJECT_H

#include <QList>
#include "Observer.h"


class ASubject
{
    QList<ObserverFile*> list;
public:
    void Attach(ObserverFile *newFile);
    void Detach(ObserverFile *product);
    void Notify(float price);
};

#endif // SUBJECT_H
