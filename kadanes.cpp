#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(int arr[], int n)
{

    int currMax = 0;
    int globalMax = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        currMax += arr[i];

        if (currMax > globalMax)
        {
            globalMax = currMax;
        }

        if (currMax < 0)
        {
            currMax = 0;
        }
    }

    return globalMax;
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

        int maxSum = maxSubarraySum(A, n);

        cout << maxSum << endl;
    }
    return 0;
}