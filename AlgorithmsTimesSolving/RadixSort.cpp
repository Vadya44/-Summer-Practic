void radixSort(int *array, int length)
{
    int max = array[0];

    for (int i = 0; i < length; i++)
        if (array[i] > max)
            max = array[i];

    int *temp = new int[length];

    long long exp = 1;

    while (max / exp > 0)
    {
        int *helpArr = new int[10];

        for (int i = 0; i < 10; ++i)
            helpArr[i] = 0;
        for (int i = 0; i < length; i++)
            helpArr[array[i] / exp % 10]++;
        for (int i = 1; i < 10; i++)
            helpArr[i] += helpArr[i - 1];
        for (int i = length - 1; i >= 0; --i)
            temp[--helpArr[array[i] / exp % 10]] = array[i];
        for (int i = 0; i < length; i++)
            array[i] = temp[i];

        exp *= 10;

        delete [] helpArr;
    }

    delete [] temp;
}