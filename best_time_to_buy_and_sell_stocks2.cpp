#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getTopMostParent(vector<int> &arr, int currParent)
    {

        int topMostParent = currParent;

        while (currParent != -1)
        {
            topMostParent = currParent;
            currParent = arr[currParent];
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

        // smallest left side element index
        vector<int> SLSEI(n);
        // next smaller left side element index
        stack<int> NSLSEI;

        SLSEI[0] = -1;
        NSLSEI.push(0);

        for (int i = 1; i < n; i++)
        {

            while (!NSLSEI.empty() && prices[NSLSEI.top()] > prices[i])
            {
                NSLSEI.pop();
            }

            if (!NSLSEI.empty())
            {
                SLSEI[i] = getTopMostParent(SLSEI, NSLSEI.top());
            }
            else
            {
                SLSEI[i] = -1;
            }

            NSLSEI.push(i);
        }

        // max profit on buying at i
        int MPOBA[n];
        MPOBA[n - 1] = 0;

        for (int i = n - 2; i >= 0; i--)
        {
            MPOBA[i] = MPOBA[i + 1];
            if (GREI[i] != -1)
            {
                MPOBA[i] = max(MPOBA[i], prices[GREI[i]] - prices[i]);
            }
        }

        int maxGain = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (SLSEI[i] != -1)
            {
                int currIndexGain = prices[i] - prices[SLSEI[i]];
                maxGain = max(maxGain, currIndexGain + (i + 1 < n ? MPOBA[i + 1] : 0));
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
