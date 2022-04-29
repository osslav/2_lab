#ifndef SUBJECT_H
#define SUBJECT_H

#include <QFile>
#include <QTextStream>
#include <QList>
#include "Observer.h"

enum class ErrorCodeSubjects                    //коды для срабатывания исключений
{
    errorStreamInWrite,                         //ошибка потока при чтении/записи
    errorStreamInRead,

    errorFileIsNotWritable,                     //ошибка - файл не доступен для чтения/записи
    errorFileIsNotReadable
};

class ASubject                                  //класс для обслуживания наблюдателей
{
    QList<ObserverFile*> list;                  //список наблюдателей
public:
    void attach(ObserverFile *newFile);         //добавление наблюдателя
    void detach(ObserverFile *removedFile);     //удаление наблюдателя
    void notify(bool fileExist, int size);      //обновление данных в наблюдателях
};

class MyFile : public ASubject                  //класс для обслуживания наблюдателей за файлом
{
    QFile file;                                 //объект файла
public:
    MyFile(const QString& fileName) : file(fileName) {};    //конструктор(инициаллизирует файл по имени файла)
    void updateObservers();                     //обновление данных в наблюдателях

    QString read();                             //чтение из файла
    void write(const QString& str);             //запись в файл
};


#endif // SUBJECT_H
