#include <algorithm>
#include <climits>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    int getTopMostParent(vector<int> &greatestElementOnRight, int currParent)
    {

        int topMostParent = currParent;

        while (currParent != -1)
        {
            topMostParent = currParent;
            currParent = greatestElementOnRight[currParent];
        }

        return topMostParent;
    }

    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();

        if (n <= 0)
        {
            return 0;
        }

        vector<int> greatestRightElementIdx(n);

        stack<int> nearestGreaterRightElementIdx;

        greatestRightElementIdx[n - 1] = -1;
        nearestGreaterRightElementIdx.push(n - 1);

        vector<int> &GREI = greatestRightElementIdx;
        stack<int> &NGREI = nearestGreaterRightElementIdx;

        for (int i = n - 2; i >= 0; i--)
        {

            while (!NGREI.empty() && prices[i] > prices[NGREI.top()])
            {
                NGREI.pop();
            }

            if (NGREI.empty())
            {
                GREI[i] = -1;
            }
            else
            {
                GREI[i] = NGREI.top();
                GREI[i] = getTopMostParent(GREI, GREI[i]);
            }

            NGREI.push(i);
        }

        int maxGain = 0;

        for (int i = 0; i < n; i++)
        {
            if (GREI[i] != -1)
            {
                maxGain = max(maxGain, prices[GREI[i]] - prices[i]);
            }
        }

        return maxGain;
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
        cout << ob.maxProfit(arr) << endl;
    }
    return 0;
}
