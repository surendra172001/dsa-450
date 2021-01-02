#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 1000

int mat[MAX][MAX];

class Solution
{
public:
    void findLessThanEqualToCntInArr(int arr[], int n, int key, int &ltk, int &etk)
    {
        int *itr = lower_bound(arr, arr + n, key);
        int i = itr - arr;

        int lessCnt = i;

        while (i < n && (arr[i] == key))
        {
            i += 1;
        }

        ltk += lessCnt;

        etk += (i - lessCnt);
    }

    void findLessThanEqualToCnt(int mat[MAX][MAX], int n, int key, int &ltk, int &etk)
    {
        for (int i = 0; i < n; i++)
        {
            findLessThanEqualToCntInArr(mat[i], n, key, ltk, etk);
        }
    }

    int kthSmallest(int mat[MAX][MAX], int n, int k)
    {
        int minM = INT_MAX;
        int maxM = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            minM = min(minM, mat[i][0]);
            maxM = max(maxM, mat[i][n - 1]);
        }

        int s = minM;
        int e = maxM;

        while (s <= e)
        {

            int mid = s + (e - s) / 2;

            int ltMid = 0, etMid = 0;
            findLessThanEqualToCnt(mat, n, mid, ltMid, etMid);

            if (ltMid >= k)
            {
                e = mid - 1;
            }
            else if ((ltMid + etMid) < k)
            {
                s = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
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

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        }

        int k;

        cin >> k;

        Solution ob;

        int ans = ob.kthSmallest(mat, n, k);

        cout << ans << endl;
    }
    return 0;
}
