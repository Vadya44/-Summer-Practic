/*
 * Написать бабл сорт трех типов :
 * 1. методом пузырька
 * 2. методом пузырька с условием Айверсона 1
 * 3. методом пузырька с условием Айверсона 2
 */
#include <iostream>
using namespace std;

void bubbleSortArrayClassic(int *arr, int begin, int end);

void bubbleSortArrayIverson1(int *arr, int begin, int end);

void bubbleSortArrayIverson2(int *arr, int begin, int end);

void generateArray(int *arr, int min, int max, int N);

void printArray(int array[], int N);


int main(int argc, char* argv[])
{
    int min, max, N;

    cout << "Enter N:" << endl;
    cin >> N;

    cout << "Enter min num for generate:" << endl;
    cin >> min;

    cout << "Enter max num for generate:" << endl;
    cin >> max;

    int *arr = new int[N];
    generateArray(arr, min,max, N);
    cout << "Array is:" << endl;
    printArray(arr, N);
    bubbleSortArrayClassic(arr, 0, N);

    generateArray(arr, min,max, N);
    cout << "Array is:" << endl;
    printArray(arr, N);
    bubbleSortArrayIverson1(arr, 0, N);

    generateArray(arr, min,max, N);
    cout << "Array is:" << endl;
    printArray(arr, N);
    bubbleSortArrayIverson2(arr, 0, N);

    delete[] arr;

    return 0;
}

void bubbleSortArrayClassic(int *arr, int begin, int end)
{
    int countOfOutterCycles = 0;
    int countOfInnerCycles = 0;
    int countOfSwaps = 0;
    for (int i = begin; i < end - 1; ++i) {
        for (int j = begin; j < end - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
            {
                int buff = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = buff;
                countOfSwaps++;
            }
            countOfInnerCycles++;
        }
        countOfOutterCycles++;
    }
    cout << endl << "Array after classic bubble sort is:" << endl;
    printArray(arr, end);
    cout << endl << "Count of Outter Cycles : " << countOfOutterCycles << endl;
    cout << "Count of Inner Cycles : " << countOfInnerCycles << endl;
    cout << "Count of Swaps : " << countOfSwaps << endl << endl;
}

void bubbleSortArrayIverson1(int *arr, int begin, int end)
{
    int countOfOutterCycles = 0;
    int countOfInnerCycles = 0;
    int countOfSwaps = 0;
    bool flag = false;
    for (int i = begin; i < end - 1 && !flag; ++i) {
        flag = true;
        for (int j = begin; j < end - i - 1; ++j) {
            if (arr[j] > arr[j + 1])
            {
                int buff = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = buff;
                countOfSwaps++;
            }
            countOfInnerCycles++;
            flag = false;
        }
        countOfOutterCycles++;
    }
    cout << endl << "Array after Iverson1 bubble sort is:" << endl;
    printArray(arr, end);
    cout << endl << "Count of Outter Cycles : " << countOfOutterCycles << endl;
    cout << "Count of Inner Cycles : " << countOfInnerCycles << endl;
    cout << "Count of Swaps : " << countOfSwaps << endl << endl;
}

void bubbleSortArrayIverson2(int *arr, int begin, int end)
{
    int countOfOutterCycles = 0;
    int countOfInnerCycles = 0;
    int countOfSwaps = 0;
    int bound = end - 1;
    int t = 0;

    do {
        t = 0;

        for (int i = 0; i < bound; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                t = i;
                countOfSwaps++;
            }
            countOfInnerCycles++;
        }
        countOfOutterCycles++;
        bound = t;
    } while (t != 0);
    cout << endl<< "Array after Iverson2 bubble sort is:" << endl;
    printArray(arr, end);
    cout << endl << "Count of Outter Cycles : " << countOfOutterCycles << endl;
    cout << "Count of Inner Cycles : " << countOfInnerCycles << endl;
    cout << "Count of Swaps : " << countOfSwaps << endl << endl;
}

void printArray(int  *array, int N) {
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
}

void generateArray(int *arr, int min, int max, int N){
    srand(time(0));

    for (int i = 0; i < N; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}
