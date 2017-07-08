/*
 * Написать бабл сорт для массива длины N(вводится с клавиатуры).
 */
#include <iostream>
using namespace std;

const int INF = 1e9;
int arr[INF];

int main(int argc, char* argv[])
{
    int N;

    cout << "Enter N:" << endl;
    cin >> N;

    cout << "Array is:" << endl;

    for(int i = 0; i < N; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << "; ";
    }

    // Bubble sort O(n^2)
    for(int i = 0; i < N -1 ; i++) {
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