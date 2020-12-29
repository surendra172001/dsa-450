#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

class Solution
{
public:
    int findSmallestSubarrayLength(vector<int> &arr, int n, int x)
    {

        int minLength = n;

        for (int i = 0; i < n; i++)
        {

            int j = i;

            int subarraySum = 0;

            while (j < n && (j - i + 1) < minLength)
            {

                subarraySum += arr[j];
                if (subarraySum > x)
                {
                    minLength = j - i + 1;
                    break;
                }

                j += 1;
            }
        }

        return minLength;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        cin >> x;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        int smallestSubarrayLength = ob.findSmallestSubarrayLength(arr, n, x);

        cout << smallestSubarrayLength << endl;
    }
}