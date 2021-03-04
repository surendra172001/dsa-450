#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void printArr(int *arr, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int doesPairExists(int *arr, int n, int diff)
    {

        int ans = -1;

        sort(arr, arr + n);

        // printArr(arr, n);

        for (int i = 0; i < n; i++)
        {
            int a = arr[i];
            int b = diff + a;
            int idx = (lower_bound(arr + i, arr + n, b) - arr);
            if (idx < n and arr[idx] == b)
            {
                ans = 1;
                break;
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, diff;
        cin >> n >> diff;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        int ans = ob.doesPairExists(arr, n, diff);

        cout << ans << endl;

        delete[] arr;
    }
}
