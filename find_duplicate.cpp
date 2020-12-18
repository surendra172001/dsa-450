#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int slowPtr = nums[0];
        int fastPtr = nums[0];

        do
        {
            slowPtr = nums[slowPtr];
            fastPtr = nums[nums[fastPtr]];
        } while (slowPtr != fastPtr);

        fastPtr = nums[0];

        while (slowPtr != fastPtr)
        {
            fastPtr = nums[fastPtr];
            slowPtr = nums[slowPtr];
        }

        return slowPtr;
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

        Solution ob;
        cout << ob.findDuplicate(arr) << endl;
    }
    return 0;
}
