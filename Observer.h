#ifndef OBSERVER_H
#define OBSERVER_H

#include <QString>
//класс интерфейс для наблюдателя файла
class IObserver
{
    virtual void update(bool isExistFile, int sizeFile) = 0;        //чистая виртуальная функция для обновления данных о файле
};

//класс реализация для наблюдателя файла
class ObserverFile : public IObserver
{
    QString name;           //имя файла(для вывода в консоль)
    int size;               //размер файла
    bool fileExist;         //флаг - существует ли файл

public:
    ObserverFile(QString fileName);                                 //конструктор
    void update(bool isExistFile, int sizeFile = 0);                //реализация виртуальной функции для обновления данных о файле
};

#endif // OBSERVER_H
