#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;

class Solution
{
public:
    int isPairSumPresentInSortedArray(int arr[], int s, int e, int k)
    {

        int l = s, r = e;

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
                return true;
            }
        }

        return false;
    }

    bool isTripletSumPresent1(int arr[], int n, int k)
    {
        for (int i = 0; i < n - 2; i++)
        {

            int newK = k - arr[i];

            bool pairSumPresent = isPairSumPresentInSortedArray(arr, i + 1, n - 1, newK);

            if (pairSumPresent)
            {
                return true;
            }
            // cout << newK << " " << pairSumPresent << endl;
        }
        return false;
    }

    bool isTripletSumPresent2(int arr[], int n, int k)
    {
        for (int i = 0; i < n - 2; i++)
        {

            int newK = k - arr[i];

            set<int> s;

            for (int j = i + 1; j < n; j++)
            {
                if (s.count(newK - arr[j]) > 0)
                {
                    return true;
                }
                s.insert(arr[j]);
            }
        }
        return false;
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

        sort(arr, arr + n);

        Solution ob;
        int ans = ob.isTripletSumPresent2(arr, n, k);

        cout << ans << endl;
    }
    return 0;
}
