#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    int N;
    cout << "Input N:" << "\n";
    cin >> N;
    int arr[N];
    cout << "Array is:" << "\n";
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 10;
        cout << arr[i] << "; ";
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N -1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }

    }
    cout << "\n" << "Array after compression is:" << "\n";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "; ";
    }
    return  0;
}