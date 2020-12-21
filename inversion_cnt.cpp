#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

void printRange(ll *arr, int start, int end)
{
    cout << start << " " << end << ": ";
    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

ll merge(long long arr[], long long start, long long mid, long long end)
{

    ll totalSize = end - start + 1;

    ll aux[totalSize] = {0};

    ll inversionCnt = 0;

    ll l = start;
    ll r = mid + 1;
    ll k = 0;

    // printRange(arr, start, end);

    while (l <= mid && r <= end)
    {
        if (arr[l] > arr[r])
        {
            inversionCnt += mid - l + 1;
            aux[k] = arr[r];
            r += 1;
        }
        else
        {
            aux[k] = arr[l];
            l += 1;
        }
        k += 1;
    }

    while (l <= mid)
    {
        aux[k] = arr[l];
        l += 1;
        k += 1;
    }

    while (r <= end)
    {
        aux[k] = arr[r];
        r += 1;
        k += 1;
    }

    for (int i = 0; i < totalSize; i++)
    {
        arr[start + i] = aux[i];
    }

    // printRange(aux, start, end);

    return inversionCnt;
}

ll mergeSort(long long arr[], long long start, long long end)
{
    if (start >= end)
    {
        return 0;
    }

    ll mid = (end + start) / 2;

    ll leftSubarrayCnt = mergeSort(arr, start, mid);
    ll rightSubarrayCnt = mergeSort(arr, mid + 1, end);

    ll currArrayCnt = merge(arr, start, mid, end);

    // printRange(arr, start, end);

    return (leftSubarrayCnt + rightSubarrayCnt + currArrayCnt);
}

ll inversionCount(long long arr[], long long N)
{
    return mergeSort(arr, 0, N - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        ll n;

        cin >> n;

        ll A[n];

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        ll inversionCnt = inversionCount(A, n);

        cout << inversionCnt << endl;
    }
    return 0;
}