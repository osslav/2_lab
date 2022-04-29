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

QString MyFile::read()                                      //чтение из файла
{
    QString str;
    if (file.open(QIODevice::ReadOnly))                     //проверка доступен ли файл для чтения
    {
        QTextStream stream(&file);
        QString newStr = stream.readLine();
        while (newStr.size() != 0)
        {
            str += newStr + '\n';
            newStr = stream.readLine();
        }

        file.close();
        if (stream.status() != QTextStream::Ok)             //проверка статуса потока после чтения
        {
            throw ErrorCodeSubjects::errorStreamInWrite;
        }
    }
    else
        throw ErrorCodeSubjects::errorFileIsNotReadable;

    return str;
}

void MyFile::write(const QString& str)                      //запись в файл(с удалением всей текущей информации в файле)
{
    if (file.open(QIODevice::WriteOnly))                    //проверка доступен ли файл для записи
    {
        QTextStream stream(&file);
        stream << str;
        file.close();
        if (stream.status() != QTextStream::Ok)             //проверка статуса потока после записи
        {
            throw ErrorCodeSubjects::errorStreamInWrite;
        }
    }
    else
        throw ErrorCodeSubjects::errorFileIsNotWritable;

    updateObservers();                                      //обновление наблюдателей, поскольку файл изменился
}
