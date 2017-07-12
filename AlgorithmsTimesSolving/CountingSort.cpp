#include <iostream>
/*
 * Сортировка подсчетом
 */
int getMin(int *array, int n);
int getMax(int *array, int n);
void countingSort(int *array, int n)
{
    int min = getMin(array, n);
    int max = getMax(array, n);
    int tempLegth = max - min + 1;
    int *temp = new int[tempLegth]; // вспомогающий массив

    for (int k = 0; k < n; ++k) {
        temp[k] = 0;
    }

    for (int i = 0; i < n; i++) {
        temp[array[i] - min]++;
    }

    int j = 0;

    for (int i = min; i <= max; i++) {
        while (temp[i - min]) {
            array[j++] = i;
            temp[i - min]--;
        }
    }

    delete [] temp;
}
/*
 * Взятие минимума из массива
 */
int getMin(int *array, int n)
{
    int min = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }

    return min;
}
/*
 * взятие максимума из массива
 */
int getMax(int *array, int n) {
    int max = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    return max;
}