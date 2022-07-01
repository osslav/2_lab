#ifndef SUBJECT_H
#define SUBJECT_H

#include <QFile>
#include <QTextStream>
#include <QList>
#include "Observer.h"

class ASubject                                  //класс для обслуживания наблюдателей
{
    QList<IObserver*> list;                  //список наблюдателей
public:
    void attach(ObserverFile *newObserver);         //добавление наблюдателя
    void detach(ObserverFile *removedObserver);     //удаление наблюдателя
    void notify(bool fileExist, int size);      //обновление данных в наблюдателях
};

class MyFile : public ASubject                  //класс для обслуживания наблюдателей за файлом
{
    QFile file;                                 //объект файла
public:
    MyFile(const QString& fileName) : file(fileName) {};    //конструктор(инициаллизирует файл по имени файла)
    void updateObservers();                     //обновление данных в наблюдателях
};


#endif // SUBJECT_H
