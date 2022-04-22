#ifndef OBSERVER_H
#define OBSERVER_H

#include <QString>

class IObserverFile
{
    virtual void update(int statusFile, int sizeFile) = 0;
};

class ObserverFile : public IObserverFile
{
    QString name;
    int size;
    ObserverFile(QString fileName);
    void update(int statusFile, int sizeFile);
};

#endif // OBSERVER_H
