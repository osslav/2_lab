#include "Subject.h"

void ASubject::attach(ObserverFile *newFile)
{
    list.push_back(newFile);
}

void ASubject::detach(ObserverFile *removedFile)
{
    list.removeAll(removedFile);
}

void ASubject::notify(int statusFile, int size)
{
    for (int i = 0; i < list.size(); i++)
        if (list[i] != 0)
            list[i]->update(statusFile, size);
}


void MyFile::updateObservers()
{
    notify(file.exists(), file.size());
}

QString MyFile::read()
{
    QString str;
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        QString newStr = stream.readLine();
        while (newStr.size() != 0)
        {
            str += newStr + '\n';
            newStr = stream.readLine();
        }

        file.close();
        if (stream.status() != QTextStream::Ok)
        {
            throw ErrorCodeSubjects::errorStreamInWrite;
        }
    }
    else
        throw ErrorCodeSubjects::errorFileIsNotReadable;

    return str;
}

void MyFile::write(const QString& str)
{
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream stream(&file);
        stream << str;
        file.close();
        if (stream.status() != QTextStream::Ok)
        {
            throw ErrorCodeSubjects::errorStreamInWrite;
        }
    }
    else
        throw ErrorCodeSubjects::errorFileIsNotWritable;

    updateObservers();
}
