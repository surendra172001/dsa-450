#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int n = nums.size();

        if (n == 1)
        {
            return (target == nums[0] ? 0 : -1);
        }

        int s = 0, e = nums.size() - 1;

        if (nums[s] < nums[e])
        { // k == 0

            int targetIdx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
            if (targetIdx != n && nums[targetIdx] == target)
            {
                return targetIdx;
            }
            else
            {
                return -1;
            }
        }

        int idx = -1; // rightmost element such that a[s] < a[idx] and (idx < e and a[idx] > a[e])

        bool comingFromRight = true;
        // I am initializing as true since we can assume that e is the left of mid of a larger array which was having larger sorted right subpart and we came left since idx was residing left of the

        while (s <= e)
        {

            int m = (s + e) / 2;

            // cout << s << " " << e << " " << comingFromRight << endl;

            if (nums[s] <= nums[e])
            { // == is used to handle case when s == e
                // if idx is not found till now
                // then e is the idx if s to e is the left increasing part
                // if s to e is the right increasing part then it means we have already found the idx
                if (comingFromRight == true)
                {
                    idx = e;
                }
                break;
            }
            else if (nums[s] <= nums[m])
            { // If I come here I know currSize is > 3 and == is used to handle case when s == e

                idx = m;
                comingFromRight = false;
                s = m + 1;
            }
            else if (nums[s] > nums[m])
            { // If I come here I know currSize is > 3

                comingFromRight = true;
                e = m - 1;
            }
            else
            {
                break;
            }
        }

        assert((idx != -1) && "Wrong assumptions");

        // cout << idx << endl;

        int targetIdx1 = (lower_bound(nums.begin(), nums.begin() + idx + 1, target) - nums.begin());

        if ((targetIdx1 != idx + 1) && (nums[targetIdx1] == target))
        {
            return targetIdx1;
        }

        int targetIdx2 = (lower_bound(nums.begin() + idx + 1, nums.end(), target) - nums.begin());

        if ((targetIdx2 != n) && (nums[targetIdx2] == target))
        {
            return targetIdx2;
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

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int target;
        cin >> target;

        Solution ob;
        int ans = ob.search(arr, target);
        cout << ans << endl;
    }
}
