#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

class Solution
{
public:
    ll calMinimumChocolateDifference(vector<ll> &arr, int m)
    {

        int n = arr.size();

        sort(arr.begin(), arr.end());

        int s = 0, e = m - 1;

        ll minDiff = LONG_MAX;

        while (e < n)
        {
            minDiff = min(minDiff, arr[e] - arr[s]);
            s += 1;
            e += 1;
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
        int n;
        cin >> n;
        vector<ll> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int m;
        cin >> m;

        Solution ob;
        ll minimumChocolateDifference = ob.calMinimumChocolateDifference(arr, m);

        cout << minimumChocolateDifference << endl;
    }
}