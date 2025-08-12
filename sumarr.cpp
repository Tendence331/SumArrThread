#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <thread>

// Подсчёт суммы элементов массива

int main()
{
    int N = 1000000;         // размер массива
    int M = 4;          // части
    int part = N / M;   // деление на 4 части
    int arr[N];         // массив размера N = 20
    int sumAll = 0;     // сумма всех элементов массива
    int temp1[part];    // 1 часть разделенного массива
    int temp2[part];    // 2 часть разделенного массива
    int temp3[part];    // 3 часть разделенного массива
    int temp4[part];    // 4 часть разделенного массива
    srand(time(0));
    // Генерируем случайные числа
    std::cout << "Массив случайных чисел: ";
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100 + 1;        // генерация случайных чисел
        sumAll += arr[i];               // подсчет суммы элеменов массива
        // std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Сумма всего массива: " << sumAll << std::endl;   // вывод суммы элеменов массивa
    // Разбиваем массив на 4 части
    for (int i = 0; i < part; i++)          // присвоение времменным переменным части массива
    {
        temp1[i] = arr[i];                  // 1 часть
        temp2[i] = arr[part + i];           // 2 часть
        temp3[i] = arr[2 * part + i];       // 3 часть
        temp4[i] = arr[3 * part + i];       // 4 часть
    }
    int summa1 = 0;
    int summa2 = 0;
    int summa3 = 0;
    int summa4 = 0;
    std::thread t1([&] () {
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < part; i++)
        {
            summa1 += temp1[i];
        }
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Результат выполнения: " << elapsed.count() << " сек" << std::endl;
        std::cout << "Сумма 1 части = " << summa1 << std::endl;
    });
    std::thread t2([&] () {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < part; i++)
        {
            summa2 += temp2[i];
        }
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Результат выполнения: " << elapsed.count() << " сек" << std::endl;
        std::cout << "Сумма 2 части = " << summa2 << std::endl;
    });
    std::thread t3([&] () {
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < part; i++)
        {
            summa3 += temp3[i];
        }
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Результат выполнения: " << elapsed.count() << " сек" << std::endl;
        std::cout << "Сумма 3 части = " << summa3 << std::endl;
    });
    std::thread t4([&] () {
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < part; i++)
        {
            summa4 += temp4[i];
        }
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        std::cout << "Результат выполнения: " << elapsed.count() << " сек" << std::endl;
        std::cout << "Сумма 4 части = " << summa4 << std::endl;
    });
    
    if (t1.joinable())
    {
        t1.join();
    }
    if (t2.joinable())
    {
        t2.join();
    }
    if (t3.joinable())
    {
        t3.join();
    }
    if (t4.joinable())
    {
        t4.join();
    }
    
    std::cout << "Сумма всех частей массива = " << summa1 + summa2 + summa3 + summa4 << std::endl;

    return 0;
}