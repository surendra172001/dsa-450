/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

//User function template for C++
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(int *arr, int n)
    {

        long long globalMax = arr[0];
        long long currMax = arr[0];
        long long currMin = arr[0];

        for (int i = 1; i < n; i++)
        {

            if (arr[i] < 0)
            {
                long long newMax = max(currMin * arr[i], (long long)arr[i]);
                long long newMin = min(currMax * arr[i], (long long)arr[i]);
                currMax = newMax;
                currMin = newMin;
            }
            else if (arr[i] > 0)
            {
                currMax = max(currMax * arr[i], (long long)arr[i]);
                currMin = min(currMin * arr[i], (long long)arr[i]);
            }
            else
            {
                currMax = 0;
                currMin = 0;
            }

            globalMax = max(currMax, globalMax);
        }

        return globalMax;
    }
};

int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Solution ob;
    long long maxProdSubarray = ob.maxProduct(arr, n);
    cout << maxProdSubarray << endl;
    return 0;
}
