#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
/*Створити функцію, яка повертає суму всіх елементів масиву (Приймає цей масив) (Вказати затримку в середині 3 секунди за допомогою this_thread::sleep_for())

Запустити її виконання в окремому потоці

Написати функцію void showProgress() як буде робити симуляцію прогресу
Виводячи в ряд крапки по одному (..........) (з затримкою 500 мілісекунд)

Викликати після потоку цю функцію.

Вивести суму на екран після виконання функції яка рахує суму елементів */




int el_summ(int arr[]) {
    int summ = 0;
    for (int i = 0; i < 10; i++) {
        summ += arr[i];
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << summ << endl;
    return summ;
}

void showprogress() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 6; j++) {
                cout << ".";
                this_thread::sleep_for(chrono::milliseconds(200));
            }
        }
    }



int main() {
    cout << "hello world!" << endl;
     int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i + 1;
    }

    thread t1(el_summ, arr);

    showprogress();
    t1.join();


    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.