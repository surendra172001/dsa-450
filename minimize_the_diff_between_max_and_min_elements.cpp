#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getMinDiff(int arr[], int n, int k)
    {

        sort(arr, arr + n);

        int minDiff = arr[n - 1] - arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] >= k)
            {
                int newMin = min(arr[0] + k, arr[i] - k);
                int newMax = max(arr[i - 1] + k, arr[n - 1] - k);
                int newDiff = newMax - newMin;
                // cout << arr[i] << " " << k << " " << newMax << " " << newMin << endl;
                minDiff = min(minDiff, newDiff);
            }
        }

        return minDiff;
    }
};

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;

        cin >> k;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.getMinDiff(arr, n, k) << endl;
    }
    return 0;
}

int main()
{
}