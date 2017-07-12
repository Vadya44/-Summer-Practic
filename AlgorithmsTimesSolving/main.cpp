#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <string>
#include "help.h"
#include "BinaryInsertionSort.h"
#include "BubbleIverson2.h"
#include "BubbleIverson1.h"
#include "BubbleSortClassic.h"
#include "InsertionSort.h"
#include "CountingSort.h"
#include "BinaryInsertionSort.h"
#include "RadixSort.h"


using namespace std;
long long timeCount(void (*sorting)(int*, int), int *array, int length);
void testIt(void (*sorting)(int*, int), int arrayType);
void test(string sortingName, void (*sorting)(int*, int));
ofstream out("/Users/Vadya/Desktop/AlgorithmsTimesSolving/results.txt");
ofstream CSVout("/Users/Vadya/Desktop/AlgorithmsTimesSolving/results.csv");



int main() {

    test("Bubble sort", bubbleSortArrayClassic);
    test("Iverson's bubble sort number One", bubbleSortArrayIverson1);
    test("Iverson's bubble sort number Two", bubbleSortArrayIverson2);
    test("Counting sort", countingSort);
    test("Binary insertion sort", binaryInsertionSort);
    test("Insertion sort", insertionSort);
    test("Radix sort", radixSort);
}


void testIt (void (*sorting)(int*, int), int arrayType) {
    const int testCount = 103;

    out << "Length" << "\t" << "Average" << "\t\t" << "Min" << "\t\t" << "Max" << endl;
    CSVout << "Length" << ";" << "Average" << ";" << "Min" << ";" << "Max" << endl;

    for (int length = 1000; length <= 9000; length += 1000) {
        cout << "Длина массива: " << "\t\t" << length << endl;

        long long minTime = INT_MAX;
        long long maxTime = INT_MIN;
        long long totalTime = 0;

        int *originalArray = new int[length];
        int *testArray = new int[length];

        if (arrayType == 1)
            generateRandomArray(originalArray, length, 0, 7);
        if (arrayType == 2)
            generateRandomArray(originalArray, length, 0, INT_MAX);
        if (arrayType == 3) {
            generateRandomArray(originalArray, length, 0, INT_MAX);
            bubbleSortArrayClassic(originalArray, length);
            reSort(originalArray, length);
        }
        if (arrayType == 4) {
            generateRandomArray(originalArray, length, 0, 8000);
            descendingSort(originalArray, length);
        }

        for (int i = 0; i < testCount; ++i) {
            copyArray(originalArray, testArray, length);
            long long lastTime = timeCount(sorting, testArray, length);
            if (i > 2)
            {
                if (lastTime > maxTime)
                    maxTime = lastTime;

                if (lastTime < minTime)
                    minTime = lastTime;
                totalTime += lastTime;
            }
        }
        delete[] originalArray;
        delete[] testArray;
        out << length << "\t\t" << (totalTime / (testCount - 3)) << "\t\t" << minTime << "\t\t" << maxTime << endl;
        CSVout << length << ";" << (totalTime / (testCount - 3)) << ";" << minTime << ";" << maxTime << endl;

    }
}
    long long timeCount(void (*sorting)(int*, int), int *array, int length) {
        auto start_time = std::chrono::high_resolution_clock::now();
        sorting(array, length);
        auto end_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();
    }
    void test(string sortingName, void (*sorting)(int*, int)) {
        out << "************ " << sortingName << " ************ " << endl << endl;
        CSVout << sortingName << endl << endl;
        for (int i = 1; i < 5; ++i)
        {
            CSVout << endl << "type is " << i << endl;
            out << "Now is array with ";
            if (i == 1)
                out << " from 0 to 7 numbers." << endl;
            if (i == 2)
                out << "from 0 to INT_MAX numbers." << endl;
            if (i == 3)
                out << "semi-sorted numbers." << endl;
            if (i == 4)
                out << "already sorted numbers." << endl;
            testIt(sorting, i);
            out << endl;
            CSVout << endl;
        }
    }
