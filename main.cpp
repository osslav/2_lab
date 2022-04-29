#include <QCoreApplication>

#include "Subject.h"
#include <chrono>
#include <thread>

QTextStream cout(stdout);

int main()              //тестовый пример
{
    try
    {
        QString fileName = "test.txt";                                  //задаем имя файла и создаем объект MyFile и 2 наблюдателя
        MyFile testFile(fileName);
        ObserverFile fistObserver(fileName), secondObserver(fileName);

        testFile.attach(&fistObserver);                                 //привязываем наблюдателей к файлу
        testFile.attach(&secondObserver);

        testFile.updateObservers();                                     //обновляем данные в наболюдателях(двух привязанных ранее)

        testFile.detach(&secondObserver);                               //отключаем одного наблюдателя

        testFile.updateObservers();                                     //обновляем данные в наболюдателях(одном оставшемся)

        testFile.write("test message");                                 //записываем в файл тестовое сообщение

        cout << testFile.read();                                        //проверка правильности записанного сообщения

        for(int i = 0; i < 120; i++)                                    //2 минуты с интервалом в 1 секунду отслеживаем состояние файла
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            testFile.updateObservers();
        }
    }
    catch (ErrorCodeSubjects err)                                       //обработка возможных исключений
    {
        switch(err)
        {
        case(ErrorCodeSubjects::errorStreamInWrite):
            cout << "Error stream in write\n";
            break;
        case(ErrorCodeSubjects::errorStreamInRead):
            cout << "Error stream in read\n";
            break;
        case(ErrorCodeSubjects::errorFileIsNotWritable):
            cout << "Error file is not writable\n";
            break;
        case(ErrorCodeSubjects::errorFileIsNotReadable):
            cout << "Error file is not readable\n";
            break;
        }
    }
    catch (...)
    {
        cout << "Unknown error.";
    }

    return 0;
}
