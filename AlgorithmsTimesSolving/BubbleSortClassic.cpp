void bubbleSortArrayClassic(int *arr, int end)
{
    for (int i = 0; i < end - 1; ++i)
    {
        for (int j = 0; j < end - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int buff = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = buff;
            }
        }
    }
}