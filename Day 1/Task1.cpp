#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int N, k;
    cout << "Input N:" << "\n";
    cin >> N;
    cout << "Input k:" << "\n";
    cin >> k;
    int arr[N];
    cout << "Array is:" << "\n";
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
        cout << arr[i] << "; ";
    }
    for (int i = 0; i < k; i++) {
        {
            int temp = arr[0];
            for (int j = 0; j < N - 1; j++) {
                arr[j] = arr[j + 1];
            }
            arr[N - 1] = temp;
        }
    }
    cout << "\n" << "Array after shifting is:" << "\n";
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << "; ";
    }
    return  0;
}