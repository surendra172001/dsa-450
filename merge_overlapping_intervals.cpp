#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b)
{
    if (a[0] != b[0])
    {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        sort(intervals.begin(), intervals.end(), cmp);

        int s = 0, r = 1;
        vector<vector<int>> ans;

        int initialSize = intervals.size();
        int leftEndValue = intervals[s][0];
        int rightEndValue = intervals[s][1];

        while (s + r < initialSize)
        {
            int e = s + r;
            if (rightEndValue >= intervals[e][0])
            {
                leftEndValue = min(leftEndValue, intervals[e][0]);
                rightEndValue = max(rightEndValue, intervals[e][1]);
                r += 1;
            }
            else
            {
                ans.push_back(vector<int>({leftEndValue, rightEndValue}));
                s = e;
                r = 1;
                leftEndValue = intervals[s][0];
                rightEndValue = intervals[s][1];
            }
        }

        // The last one is not going to be added in the loop
        // so we are handling it here
        int e = s + r;
        leftEndValue = min(intervals[e - 1][0], leftEndValue);
        rightEndValue = max(intervals[e - 1][1], rightEndValue);
        ans.push_back(vector<int>({leftEndValue, rightEndValue}));

        return ans;
    }
};

void printVectorOfVector(vector<vector<int>> &intervals)
{
    cout << "[";

    for (int i = 0; i < intervals.size(); i++)
    {
        vector<int> &a = intervals[i];
        if (i < intervals.size() - 1)
        {
            cout << "[" << a[0] << ", " << a[1] << "], ";
        }
        else
        {
            cout << "[" << a[0] << ", " << a[1] << "]";
        }
    }

    cout << "]\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;

        cin >> n;

        vector<vector<int>> intervals(n, vector<int>(2));

        for (int i = 0; i < n; i++)
        {
            cin >> intervals[i][0] >> intervals[i][1];
        }

        Solution ob;
        ob.merge(intervals);

        printVectorOfVector(intervals);
    }
    return 0;
}
