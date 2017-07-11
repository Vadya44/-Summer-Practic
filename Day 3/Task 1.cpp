/*
 * Написать сортировки:
 * 1. Подсчетом
 * 2. Цифровую
 */
#include <iostream>
#include <fstream>
using namespace std;
int *arr;
int n;
// Прототипы

void printArray(int array[], int N);

int getMin(int *array, int n);

int getMax(int *array, int n);

void saveArrayToFile(int *array, int n, ofstream& fOut);

void cloneArray(int *inputArray, int *outputArray, int n);

void radixSort(int *array, int n, int base);

void openFile();

void countingSort(int *array, int n);

union un{
    unsigned int a;
    unsigned char ch[4];
};

int main()
{
    ofstream oFile;
    oFile.open("/Users/Vadya/Desktop/C++taskLast/output.txt", ios::out);
    /*
     * Запись в файл исходного массива
     */
    openFile();
    cout << "Array is: " << endl;
    oFile << "Array is: " << endl;
    saveArrayToFile(arr, n, oFile);
    printArray(arr, n);

    /*
     * Запись результатов сортировки подсчетом
     */
    countingSort(arr, n);
    oFile << endl << "Array after counting sort is: " << endl;
    cout << endl << "Array after counting sort is: " << endl;
    printArray(arr,n);
    saveArrayToFile(arr, n, oFile);
    /*
     * Повторная запись исходного массива
     */
    openFile();
    oFile << endl << endl << "Array is: " << endl;
    cout << endl << endl << "Array is: " << endl;
    saveArrayToFile(arr, n, oFile);
    printArray(arr, n);

    /*
     * Запись результатов цифровой сортировки
     */
    radixSort(arr, n , 256);
    oFile << endl << "Array after radix sort is: " << endl;
    cout << endl <<"Array after radix sort is: " << endl;
    printArray(arr,n);
    saveArrayToFile(arr, n, oFile);

    delete[] arr;

    return 0;
}
/*
 * Сортировка подсчетом
 */
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
 * Цифровая сортировка
 */
void radixSort(int *array, int n, int base)
{

    int exponent = 0;
    int max = getMax(array, n);
    un *temp = new un[n];

    while (exponent < 4) {
        for (int i = 0; i < n; i++) {
            temp[i].a = array[i]; // инициализация массива юнионов
        }
        int *cnt = new int[base];

        for (int i = 0; i < n; i++) {
            cnt[temp[i].ch[exponent]]++;
        }

        int sum = 0, j;

        for (int i = 0; i < base; i++) {
            j = cnt[i];
            cnt[i] = sum;
            sum += j;
        }

        for (int i = 0; i < n; i++) {
            int tempIndex = temp[i].ch[exponent];
            array[cnt[tempIndex]] = temp[i].a;
            cnt[tempIndex]++;
        }

        exponent++;
        delete [] cnt;
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
 * Запись массива в файл
 */
void saveArrayToFile(int *array, int n, ofstream& fOut)
{
    for (int i = 0; i < n; i++) {
        fOut << array[i] << " ";
    }

    fOut << "" << endl;
}
/*
 * Копирование массива
 */
void cloneArray(int *inputArray, int *outputArray, int n)
{
    for (int i = 0; i < n; i++) {
        outputArray[i] = inputArray[i];
    }
}

/*
 * Заполняем массив значениями из файла INPUT.TXT
 */
void openFile()
{
    ifstream inFile;
    inFile.open("/Users/Vadya/Desktop/C++taskLast/input.txt", ios::in);
    inFile >> n;
    arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        inFile >> arr[i];
        arr[i] *= 11111111;
    }
    inFile.close();
}