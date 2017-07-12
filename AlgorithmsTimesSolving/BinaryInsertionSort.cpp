void binaryInsertionSort(int *array, int n)
{
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
        }
        array[leftBound] = temp;
    }
}