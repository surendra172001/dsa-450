#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    void heapify(int arr[], int n, int i)
    {
        if (i < 0)
            return;

        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l] > arr[largest])
        {
            largest = l;
        }

        if (r < n && arr[r] > arr[largest])
        {
            largest = r;
        }

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

public:
    void buildHeap(int arr[], int n)
    {

        int half = n / 2;

        for (int i = half; i >= 0; i--)
        {
            heapify(arr, n, i);
        }
    }

public:
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for (int hSize = n; hSize > 1; hSize--)
        {
            heapify(arr, hSize, 0);
            swap(arr[0], arr[hSize - 1]);
        }
    }
};

void printArr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        ob.heapSort(arr, n);

        printArr(arr, n);

        delete[] arr;
    }
}