/*
 * Создать массив длины N(вводится с клавиатуры).
 * Переместить все нули в конце массива.
 */
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int N;

    cout << "Enter N:" << endl;
    cin >> N;

    int *arr = new int[N];

    cout << "Array is:" << endl;

    for(int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << "; ";
    }

    // Число встреченных нулей
    int zeroes_encountered = 0;

    for(int i = 0; i < N; i++) {
        if(arr[i] == 0) {
            zeroes_encountered += 1;
        }
        else if(zeroes_encountered) {
            /*
             * Меняем ненулевой элемент местами с первым по счету нулем
             */
            arr[i - zeroes_encountered] = arr[i];
            arr[i] = 0;
        }

        /*
         * На промежутке [0; i - zeroes_encountered] нет нулей;
         * На промежутке (i - zeroes_encountered; i] только нули
         */
    }

    cout << endl << "Array after compression is:" << endl;

    for(int i = 0; i < N; i++) {
        cout << arr[i] << "; ";
    }

    return 0;
}
