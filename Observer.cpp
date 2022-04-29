#include "Observer.h"
#include <QTextStream>

ObserverFile::ObserverFile(QString fileName)                    //конструктор для наблюдателя файла(принимает имя файла и инициаллизирует поля)
{
    name = fileName;
    size = -1;
    fileExist = false;
}

void ObserverFile::update(bool isExistFile, int sizeFile)       //обновление данных о файле
{       
    QTextStream cout(stdout);                                   //задаем поток для вывода в консоль

    if (isExistFile)                                            //в зависимости новых и старых данных о файле делаем вывод о том что с ним произошло
        if (size == sizeFile)
            if (size != 0)
                cout << "File \"" << name << "\" exist and not empty. Size: " << sizeFile << '\n';
            else
                cout << "File \"" << name << "\" exist and empty.\n";
        else
            cout << "File \"" << name << "\" exist and was changed. New size: " << sizeFile << '\n';
    else
        cout << "File \"" << name << "\" not exist.\n";

    size = sizeFile;                                            //обновляем данные в полях объекта
    fileExist = isExistFile;
}

