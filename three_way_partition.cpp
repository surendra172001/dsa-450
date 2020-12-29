#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void threeWayPartition(vector<int> &array, int a, int b)
    {
        int n = array.size();
        int l = 0;
        int m = 0;
        int h = n - 1;

        while (m <= h)
        {

            if (array[l] < a)
            {
                l += 1;
                m = (l > m ? l : m);
            }
            else if (a <= array[m] && array[m] <= b)
            {
                m += 1;
            }
            else if (array[h] > b)
            {
                h -= 1;
            }
            else if (array[m] < a)
            {
                swap(array[l], array[m]);
                l += 1;
                m += 1;
            }
            else if (array[m] > b)
            {
                swap(array[m], array[h]);
                h -= 1;
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        ob.threeWayPartition(arr, a, b);
    }
}