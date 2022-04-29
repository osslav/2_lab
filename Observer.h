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
    bool fileExist;
public:
    ObserverFile(QString fileName);
    void update(bool isExistFile, int sizeFile = 0);
};

#endif // OBSERVER_H
