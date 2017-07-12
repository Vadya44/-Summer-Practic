int bubbleSortArrayIverson2(int *arr, int end)
{
    int bound = end - 1;
    int t = 0;

    do
    {
        t = 0;

        for (int i = 0; i < bound; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                t = i;
            }
        }
        bound = t;
    } while (t != 0);
}