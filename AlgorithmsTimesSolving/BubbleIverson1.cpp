int bubbleSortArrayIverson1(int *arr, int end)
{
    bool flag = false;
    for (int i = 0; i < end - 1 && !flag; ++i)
    {
        flag = true;
        for (int j = 0; j < end - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                int buff = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = buff;
            }
            flag = false;
        }
    }
}