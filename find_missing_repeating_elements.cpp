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
    int *findTwoElement(int *arr, int n)
    {

        int arrXor = 0;
        int rangeXor = 0;

        for (int i = 0; i < n; i++)
        {
            arrXor ^= arr[i];
            rangeXor ^= (i + 1);
        }

        int missingRepeatingXor = arrXor ^ rangeXor;

        // right most set bit of missing and repeating element's xor value

        int rmsb = log2(missingRepeatingXor & (-missingRepeatingXor));

        int arrXorG1 = 0, arrXorG2 = 0;
        int rangeXorG1 = 0, rangeXorG2 = 0;

        for (int i = 0; i < n; i++)
        {
            if ((((i + 1) >> rmsb) & 1) == 0)
            {
                rangeXorG1 ^= (i + 1);
            }
            else
            {
                rangeXorG2 ^= (i + 1);
            }

            if (((arr[i] >> rmsb) & 1) == 0)
            {
                arrXorG1 ^= arr[i];
            }
            else
            {
                arrXorG2 ^= arr[i];
            }
        }

        int e1 = rangeXorG1 ^ arrXorG1;
        int e2 = rangeXorG2 ^ arrXorG2;

        int e1Cnt = 0, e2Cnt = 0;

        for (int i = 0; i < n; i++)
        {
            e1Cnt += int(arr[i] == e1);
            e2Cnt += int(arr[i] == e2);
        }

        int *ans = new int[2];

        if (e1Cnt == 0)
        {
            ans[0] = e2;
            ans[1] = e1;
        }
        else
        {
            ans[0] = e1;
            ans[1] = e2;
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
        int n;
        cin >> n;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        int *ans = ob.findTwoElement(arr, n);

        cout << ans[0] << " " << ans[1] << endl;

        delete[] arr;
        delete[] ans;
    }
}
