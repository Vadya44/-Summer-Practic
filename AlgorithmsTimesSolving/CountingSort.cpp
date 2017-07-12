#include <iostream>
/*
 * Сортировка подсчетом
 */
int getMin(int *array, int n);
int getMax(int *array, int n);
void countingSort(int *array, int n)
{
    int max =getMax(array, n);

    int *c = new int[max + 1];

    for (int i = 0; i < max + 1; ++i)
        c[i] = 0;

    for (int i = 0; i < n; ++i)
        c[array[i]]++;

    for (int i = 1; i < max + 1; ++i)
        c[i] += c[i - 1];

    int* res = new int[n];
    for (int i = n - 1; i >= 0; --i) {
        res[c[array[i]] - 1] = array[i];
        c[array[i]]--;
    }

    for (int i = 0; i < n; ++i)
        array[i] = res[i];

    delete[] c;
    delete[] res;
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