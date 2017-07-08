/*
 * Создать массив длины N(вводится с клавиатуры).
 * Переместить все нули в конце массива.
 */
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int N;

    cout << "Enter N: ";
    cin >> N;

    int* arr = new int[N];

    cout << "Array is:" << endl;

    for(int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << "; ";
    }

    int last_zero = N;

    while(arr[last_zero-- - 1] == 0) { }

    /*
     * Инвариант:
     * * в интервале (last_zero; N) только нули
     * * в интервале [0; i] (в конце итерации цикла) нет нулей
     */
    for(int i = 0; i < last_zero; i++) {
        if(arr[i] == 0) {
            swap(arr[i], arr[last_zero--]);
        }
    }

    cout << endl << "Array after compression is:" << endl;

    for(int i = 0; i < N; i++) {
        cout << arr[i] << "; ";
    }

    delete[] arr;

    return 0;
}
