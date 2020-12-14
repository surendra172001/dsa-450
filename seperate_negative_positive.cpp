#include <bits/stdc++.h>
using namespace std;

int seperatePositiveNegative(int arr[], int arrSize)
{
    int i = 0;
    int j = arrSize - 1;
    while (i < j)
    {
        if (arr[i] < 0)
        {
            i += 1;
        }
        else if (arr[j] > 0)
        {
            j -= 1;
        }
        else
        {
            swap(arr[i], arr[j]);
            i += 1;
            j -= 1;
        }
    }
}

int main()
{
    int arr[] = {1, 5, 4, -3, 6, 5, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    seperatePositiveNegative(arr, arrSize);
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}