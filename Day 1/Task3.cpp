/*
 * Написать бабл сорт для массива длины N(вводится с клавиатуры).
 */
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int N;

    cout << "Input N:" << endl;
    cin >> N;

    int arr[N];

    cout << "Array is:" << endl;

    for(int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << "; ";
    }

    // Bubble sort O(n^2)
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - i; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << endl << "Array after compression is:" << endl;

    for(int i = 0; i < N; i++) {
        cout << arr[i] << "; ";
    }

    return 0;
}