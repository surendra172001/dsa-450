#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getPairsCount(int arr[], int n, int k)
    {

        sort(arr, arr + n);

        int cnt = 0;

        int l = 0, r = n - 1;

        while (l < r)
        {

            int sum = arr[l] + arr[r];

            if (sum < k)
            {
                l += 1;
            }
            else if (sum > k)
            {
                r -= 1;
            }
            else
            {

                // case where the elements summing to give k are equal
                if (arr[l] == arr[r])
                {
                    int windowSize = r - l + 1;
                    cnt += windowSize * (windowSize - 1) / 2;
                    return cnt;
                }

                // case where the elements forming the sum to give k are not equal
                // but they are repeating multiple times
                int leftElementCnt = 0;
                int rightElementCnt = 0;

                int lAux = l;

                while (lAux < r && (arr[lAux] == arr[l]))
                {
                    leftElementCnt += 1;
                    lAux += 1;
                }

                int rAux = r;

                while (rAux > l && (arr[rAux] == arr[r]))
                {
                    rightElementCnt += 1;
                    rAux -= 1;
                }

                l = lAux;
                r = rAux;

                cnt += leftElementCnt * rightElementCnt;
            }
        }

        return cnt;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;

        cin >> n >> k;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        int cntOfPairsSummingToK = ob.getPairsCount(arr, n, k);

        cout << cntOfPairsSummingToK << endl;
    }
    return 0;
}
