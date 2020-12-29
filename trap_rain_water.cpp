#include <iostream>
#include <vector>
using namespace std;

#define ll long long

class Solution
{
public:
    int calTrappedWaterUnits(vector<ll> &arr)
    {

        int n = arr.size();

        int i = 0;

        ll totalWaterUnits = 0;

        while (i < n)
        {

            int e = i + 1;

            ll waterUnitsForI = 0;

            while (e < n && arr[i] >= arr[e])
            {
                waterUnitsForI += (arr[i] - arr[e]);
                e += 1;
            }

            if (e == n)
            {
                break;
            }

            totalWaterUnits += waterUnitsForI;

            i = e;
        }

        // now i is the index of the greatest element in the array

        int j = n - 1;

        while (j > i)
        {

            int s = j - 1;

            while (s > i && arr[j] >= arr[s])
            {
                totalWaterUnits += arr[j] - arr[s];
                s -= 1;
            }

            j = s;
        }

        return totalWaterUnits;
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

        Solution ob;
        ll totalWaterUnits = ob.calTrappedWaterUnits(arr);

        cout << totalWaterUnits << endl;
    }
}