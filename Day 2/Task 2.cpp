/*
 * Написать бабл сорт трех типов :
 * 1. Простыми вставками
 * 2. Бинарными вставками
 */
#include <iostream>
using namespace std;

// Прототипы
void insertionSort(int *arr, int n);

void binaryInsertionSort(int *arr, int n);

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

    /*
     * Генерируем массив
     */
    int *arr = new int[N];
    generateArray(arr, min,max, N);
    cout << "Array is:" << endl;
    printArray(arr, N);
    insertionSort(arr, N);

    /*
     * Генерируем такой же массив
     */
    generateArray(arr, min,max, N);
    cout << "Array is:" << endl;
    printArray(arr, N);
    binaryInsertionSort(arr, N);

    delete[] arr;

    return 0;
}

/*
 * Сортировка вставками
 */
void insertionSort(int *array, int n)
{
    int countOfOutterCycles = 0;
    int countOfSwaps = 0;
    for (int i = 1; i < n; i++)
    {
        int j = i;

        while (j > 0 && array[j] < array[j - 1])
        {
            int temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
            countOfSwaps++;
            j = j - 1;
        }
        countOfOutterCycles++;
    }
    cout << endl << "Array after insertion sort is:" << endl;
    printArray(array, n);
    cout << endl << "Count of Outter Cycles : " << countOfOutterCycles << endl;
    cout << "Count of Swaps : " << countOfSwaps << endl << endl;
}

/*
 * Бинарная сортиврока вставками
 */
void binaryInsertionSort(int *array, int n)
{
    int countOfOutterCycles = 0;
    int countOfSwaps = 0;
    for (int i = 1; i < n; i++) {
        int leftBound = 0;
        int rightBound = i;
        int middle = (leftBound + rightBound) / 2;

        while (leftBound != middle)
        {
            if (array[middle] > array[i])
            {
                rightBound = middle - 1;
            } else
            {
                leftBound = middle;
            }

            middle = (leftBound + rightBound) / 2;
        }

        if (array[leftBound] < array[i])
        {
            if (array[i] > array[rightBound]) {
                leftBound = rightBound + 1;
            } else {
                leftBound = rightBound;
            }
        }

        int temp = array[i];

        for (int j = i; j > leftBound; j--)
        {
            array[j] = array[j - 1];
            countOfSwaps++;
        }
        array[leftBound] = temp;
        countOfOutterCycles++;
        countOfSwaps++;
    }
    cout << endl << "Array after binary insertion sort is:" << endl;
    printArray(array, n);
    cout << endl << "Count of Outter Cycles : " << countOfOutterCycles << endl;
    cout << "Count of Swaps : " << countOfSwaps << endl << endl;
}

/*
 * Печать массива
 *
 */
void printArray(int  *array, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << array[i] << " ";
    }
}
/*
 * Для того, чтоы мы могли объективно сравнивать количество циклов и свапов, будем юзать
 * одинаковые входные массивы.
 */
void generateArray(int *arr, int min, int max, int N)
{
    srand(time(0));

    for (int i = 0; i < N; i++)
    {
        arr[i] = min + rand() % (max - min + 1);
    }
}
