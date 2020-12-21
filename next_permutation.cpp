#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &nums)
{
    for (int &x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
}

class Solution
{
public:
    void reverse(vector<int> &nums, int start, int end)
    {
        if (end <= start)
        {
            return;
        }

        int rangeSize = end - start + 1;

        int mid = rangeSize / 2;

        for (int i = 0; i < mid; i++)
        {
            swap(nums[i + start], nums[nums.size() - i - 1]);
        }
    }

    void nextPermutation(vector<int> &nums)
    {

        int pivotIndex = -1;

        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] < nums[i + 1])
            {
                pivotIndex = i;
            }
        }

        if (pivotIndex == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }

        int ceilIndex = -1;

        for (int i = n - 1; i > pivotIndex; i--)
        {
            if (nums[i] > nums[pivotIndex])
            {
                ceilIndex = i;
                break;
            }
        }

        assert(ceilIndex != -1);

        swap(nums[pivotIndex], nums[ceilIndex]);

        reverse(nums, pivotIndex + 1, nums.size() - 1);
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

        vector<int> permutation(n);

        for (int i = 0; i < n; i++)
        {
            cin >> permutation[i];
        }

        Solution ob;
        ob.nextPermutation(permutation);

        printVector(permutation);
    }
    return 0;
}
