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

    int position = N - 1;

    // Перемещаем в конец массива все нули
    for(int i = 0; i < position; i++) {
        if(arr[i] == 0) {
            if(arr[position] != 0) {  //Случай, когда элемент в конце не 0
                arr[i] = arr[position];
                arr[position--] = 0;
            }
            else if(arr[position] == 0) {  // Случай, когда элемент в конце равен нулю, поэтому перемещаемся
                while(arr[--position] == 0) { }  // к близжайшему от конца элементу, который не равен нулю.
                arr[i] = arr[position];
                arr[position--] = 0;
            }
        }
    }

    cout << endl << "Array after compression is:" << endl;

    for(int i = 0; i < N; i++) {
        cout << arr[i] << "; ";
    }

    delete[] arr;

    return 0;
}
