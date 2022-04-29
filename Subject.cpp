#include "Subject.h"

void ASubject::attach(ObserverFile *newObserver)            //добавление наблюдателя
{
    list.push_back(newObserver);
}

void ASubject::detach(ObserverFile *removedFile)            //удаление наблюдателя
{
    list.removeAll(removedFile);
}

void ASubject::notify(bool fileExist, int size)             //обновление данных о наблюдателях(с передачей данных в виде аргумента)
{
    for (int i = 0; i < list.size(); i++)                   //идем по циклу и обновляем данные в наблюдателях
        if (list[i] != nullptr)
            list[i]->update(fileExist, size);
}


void MyFile::updateObservers()                              //обновление данных о наблюдателях(данные берем напрямую от файла)
{
    notify(file.exists(), file.size());
}

