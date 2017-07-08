/*
 * Task 1
 * Создать массив длинной N(вводится с клавиатуры).
 * Выполнить сдвиг влево на k позиций(вводится с клавиатуры).
 */
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int N, k;

    cout << "Input N:" << endl;
    cin >> N;

    cout << "Input k:" << endl;
    cin >> k;

    int arr[N];

    cout << "Array is:" << endl;

    for(int i = 0; i < N; i++) {
        arr[i] = i + 1;
        cout << arr[i] << "; ";
    }

    // Shifting array left for k positions
    for(int i = 0; i < k; i++) {
        {
            int temp = arr[0];

            for(int j = 0; j < N - 1; j++) {
                arr[j] = arr[j + 1];
            }

            arr[N - 1] = temp;
        }
    }

    cout << endl << "Array after shifting is:" << endl;

    for(int i = 0; i < N; i++) {
        cout << arr[i] << "; ";
    }

    return 0;
}
