#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

class Solution
{
public:
    int findLessThanEqualCnt(vector<int> &arr, int n, int k)
    {

        int cnt = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= k)
            {
                cnt += 1;
            }
        }

        return cnt;
    }

    int findMinimumSwaps(vector<int> &arr, int n, int k)
    {

        int windowSize = findLessThanEqualCnt(arr, n, k);

        int maxWindowCnt = 0;

        for (int i = 0; i < windowSize; i++)
        {
            if (arr[i] <= k)
            {
                maxWindowCnt += 1;
            }
        }

        int currWindowCnt = maxWindowCnt;

        int i = 1;
        int j = windowSize;

        while (j < n)
        {

            int includeCnt = int(arr[j] <= k);
            int excludeCnt = int(arr[i - 1] <= k);

            currWindowCnt += includeCnt - excludeCnt;

            maxWindowCnt = max(maxWindowCnt, currWindowCnt);

            i += 1;
            j += 1;
        }

        int minSwaps = windowSize - maxWindowCnt;

        return minSwaps;
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

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        Solution ob;
        int minimumSwaps = ob.findMinimumSwaps(arr, n, k);

        cout << minimumSwaps << endl;
    }
}