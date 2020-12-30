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
    int binSearchLeftMost(vector<int> &arr, int n, int x)
    {
        int s = 0, e = n - 1;

        int pos = -1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (arr[mid] < x)
            {
                s = mid + 1;
            }
            else
            {
                pos = mid;
                e = mid - 1;
            }
        }

        return pos;
    }

    int binSearchRightMost(vector<int> &arr, int n, int x)
    {
        int s = 0, e = n - 1;

        int pos = -1;

        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (arr[mid] <= x)
            {
                pos = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return pos;
    }

    void printFirstLastOccurence(vector<int> &arr, int n, int x)
    {

        int left = binSearchLeftMost(arr, n, x);

        if (left == -1)
        {
            cout << -1 << endl;
            return;
        }

        int right = binSearchRightMost(arr, n, x);

        cout << left << " " << right << endl;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;

        cin >> n >> x;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        ob.printFirstLastOccurence(arr, n, x);
    }
    return 0;
}
