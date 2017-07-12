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


int main() {

    test("Bubble sort", bubbleSortArrayClassic);
}


void testIt (void (*sorting)(int*, int), int arrayType) {
    const int testCount = 103;

    out << "Length" << "\t" << "Average" << "\t\t" << "Min" << "\t\t" << "Max" << endl;

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
            bubbleSortArrayClassic(originalArray, INT_MAX);
        if (arrayType == 3) {
            bubbleSortArrayClassic(originalArray, length);
            reSort(originalArray, length);
        }
        if (arrayType == 4) {
            generateRandomArray(originalArray, length, 0, 8000);
            descendingSort(originalArray, length);
        }

        for (int i = 2; i < testCount; ++i) {
            copyArray(originalArray, testArray, length);
            long long lastTime = timeCount(sorting, testArray, length);

            if (lastTime > maxTime)
                maxTime = lastTime;

            if (lastTime < minTime)
                minTime = lastTime;

            totalTime += lastTime;
        }
        delete[] originalArray;
        delete[] testArray;
        out << length << "\t\t" << (totalTime / (testCount - 3)) << "\t\t" << minTime << "\t\t" << maxTime << endl;

    }
}
    long long timeCount(void (*sorting)(int*, int), int *array, int length) {
        auto start_time = std::chrono::high_resolution_clock::now();
        sorting(array, length);
        auto end_time = std::chrono::high_resolution_clock::now();
        return std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    }
    void test(string sortingName, void (*sorting)(int*, int)) {
        out << "***************** " << sortingName << " ***************** " << endl << endl;
        testIt(sorting, 1);
        out << endl;
        testIt(sorting, 2);
        out << endl;
        testIt(sorting, 3);
        out << endl;
        testIt(sorting, 4);
        out << endl;
    }
