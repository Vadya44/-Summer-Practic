#include <iostream>
using namespace std;
void genRnd()
{

}
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
    int position = N - 1;
    for (int i = 0; i < position; i++) {
        if (arr[i] == 0) {
            if (arr[position] != 0) {
                arr[i] = arr[position];
                arr[position--] = 0;
            } else if(arr[position] == 0) {
                while (arr[--position] == 0) {}
                arr[i] = arr[position];
                arr[position--] = 0;
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