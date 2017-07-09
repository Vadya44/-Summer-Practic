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

    int position = N ;

    // Перемещаем в конец массива все нули
    while(arr[--position] == 0) { }

    for(int i = 0; i < position; i++) {
        if(arr[i] == 0) {
                arr[i] = arr[position];
                arr[position--] = 0;
        }
    }

    cout << endl << "Array after compression is:" << endl;

    for(int i = 0; i < N; i++) {
        cout << arr[i] << "; ";
    }

    return 0;
}
