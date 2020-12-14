#include <bits/stdc++.h>
using namespace std;

void countingMethod(int a[], int n)
{
    int zeroCnt = 0;
    int oneCnt = 0;
    int twoCnt = 0;
    for (int i = 0; i < n; i++)
    {
        zeroCnt += int(a[i] == 0);
        oneCnt += int(a[i] == 1);
        twoCnt += int(a[i] == 2);
    }
    int i = 0;
    for (; i < zeroCnt; i++)
    {
        a[i] = 0;
    }
    for (; i < zeroCnt + oneCnt; i++)
    {
        a[i] = 1;
    }
    for (; i < zeroCnt + oneCnt + twoCnt; i++)
    {
        a[i] = 2;
    }
}

void threeWayPartitioning(int a[], int n)
{
    int low = 0,
        mid = 0,
        high = n - 1;

    while (mid <= high)
    {
        if (a[low] == 0)
        {
            low += 1;
            mid = (low > mid ? low : mid);
        }
        else if (a[mid] == 1)
        {
            mid += 1;
        }
        else if (a[high] == 2)
        {
            high -= 1;
        }
        else if (a[mid] == 0)
        {
            swap(a[low], a[mid]);
            low += 1;
            mid += 1;
        }
        else if (a[mid] == 2)
        {
            swap(a[mid], a[high]);
            high -= 1;
        }
    }
}

void sort012(int a[], int n)
{
    // countingMethod(a, n);
    threeWayPartitioning(a, n);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort012(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}