#include <QCoreApplication>

#include "Subject.h"
#include <chrono>
#include <thread>

int main()              //тестовый пример
{             
    QString fileName = "test.txt";                                  //задаем имя файла и создаем объект MyFile и 2 наблюдателя
    MyFile testFile(fileName);
    ObserverFile fistObserver(fileName), secondObserver(fileName);

    testFile.attach(&fistObserver);                                 //привязываем наблюдателей к файлу
    testFile.attach(&secondObserver);

    testFile.updateObservers();                                     //обновляем данные в наболюдателях(двух привязанных ранее)

    testFile.detach(&secondObserver);                               //отключаем одного наблюдателя

    testFile.updateObservers();                                     //обновляем данные в наболюдателях(одном оставшемся)

    for(int i = 0; i < 120; i++)                                    //2 минуты с интервалом в 1 секунду отслеживаем состояние файла
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        testFile.updateObservers();
    }

    return 0;
}
