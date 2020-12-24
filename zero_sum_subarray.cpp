#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        arr[i] += arr[i - 1];
    }

    set<int> prefixSumHolder;

    for (int i = 0; i < n; i++)
    {
        // This case can happen when the first element is 0 OR the subarray sum is 0
        if (arr[i] == 0)
        {
            return true;
        }

        if (prefixSumHolder.find(arr[i]) != prefixSumHolder.end())
        {
            return true;
        }

        prefixSumHolder.insert(arr[i]);
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;

        cin >> n;

        int A[n];

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        bool ans = subArrayExists(A, n);

        if (ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}