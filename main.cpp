#include <QCoreApplication>

#include "Subject.h"
#include <chrono>
#include <thread>

int main()              //тестовый пример
{             
    QString fileName = "test.txt";                                  //задаем имя файла и создаем объект MyFile и 2 наблюдателя
    MyFile testFile(fileName);
    ObserverFile fistObserver(fileName + " first"), secondObserver(fileName + " second");

    testFile.attach(&fistObserver);                                 //привязываем первого наблюдателя к файлу
    testFile.notify(true, 256);                                     //тестовый вызов обновления наблюдателей с переданными данными(данный взяты для примера)

    testFile.attach(&secondObserver);                               //прявязываем второго наблюдателя
    testFile.updateObservers();                                     //обновляем данные в наболюдателях(двух привязанных ранее)

    testFile.detach(&fistObserver);                                 //отключаем одного наблюдателя
    testFile.updateObservers();                                     //обновляем данные в наболюдателях(одном оставшемся)

    for(int i = 0; i < 120; i++)                                    //2 минуты с интервалом в 1 секунду отслеживаем состояние файла
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        testFile.updateObservers();
    }

    return 0;
}
