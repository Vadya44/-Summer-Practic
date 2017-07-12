#include <iostream>
#include <stdlib.h>

using namespace std;

void printArray(int *array, int length) {
    for (int i = 0; i < length; ++i)
        cout << array[i] << " ";
    cout << endl;
}

void copyArray(int *mainArray, int copy[], int length) {
    for (int i = 0; i < length; ++i)
        copy[i] = mainArray[i];
}

void generateRandomArray(int *array, int length, int min, int max) {
    for (int i = 0; i < length; ++i)
        array[i] = min + (rand() % (max - min + 1));
}

void reSort(int *array, int length)
{
    swap(array[3], array[23]);
    swap(array[30], array[223]);
    swap(array[331], array[523]);
    swap(array[63], array[823]);
    swap(array[31], array[123]);
}

void descendingSort(int *array, int length) {
    for (int i = length - 1; i > 0; --i)
        for (int j = 0; j < i; ++j)
            if (array[j] < array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
}