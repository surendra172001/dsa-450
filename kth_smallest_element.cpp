#include <bits/stdc++.h>
using namespace std;

int findPivot(int arr[], int l, int r)
{
    int arrSize = r - l + 1;
    int randomIdx = l + (rand() % arrSize);
    int pivotElement = arr[randomIdx];
    int cntOfElementLessThanPivot = 0;
    for (int i = l; i <= r; i++)
    {
        cntOfElementLessThanPivot += int(pivotElement > arr[i]);
    }
    int pivotIndex = l + cntOfElementLessThanPivot;
    swap(arr[pivotIndex], arr[randomIdx]);
    int i = l;
    int j = r;
    while (i < pivotIndex && pivotIndex < j)
    {
        if (arr[i] < arr[pivotIndex])
        {
            i += 1;
        }
        else if (arr[j] > arr[pivotIndex])
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

    return pivotIndex;
}

int quickSelect(int arr[], int l, int r, int k)
{
    if (l > r)
    {
        return -1;
    }
    if (l == r)
    {
        return arr[l];
    }
    int pivotIndex = findPivot(arr, l, r);
    if (pivotIndex < k - 1)
    {
        return quickSelect(arr, pivotIndex + 1, r, k);
    }
    else if (pivotIndex > k - 1)
    {
        return quickSelect(arr, l, pivotIndex - 1, k);
    }
    else
    {
        return arr[pivotIndex];
    }
}

int kthSmallest(int arr[], int l, int r, int k)
{
    return quickSelect(arr, l, r, k);
}

int main()
{
    return 0;
}