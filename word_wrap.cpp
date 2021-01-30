#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &A)
{
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> findCorrectWordArrangement(vector<int> &arr, int n, int lineSize)
    {
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            int charCnt = 0;
            for (int j = i; j < n; j++)
            {
                charCnt += arr[j];
                if (charCnt > lineSize)
                {
                    break;
                }
                dp[i][j] = lineSize - charCnt;
                dp[i][j] *= dp[i][j]; // imp line
                if (j == n - 1)       // imp line
                {
                    dp[i][j] = 0;
                }
                charCnt += 1;
            }
        }

        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < n; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        vector<int> cost(n, INT_MAX);
        vector<int> path(n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (dp[j][i] != -1)
                {
                    int c = (j - 1 < 0 ? 0 : cost[j - 1]);
                    if (cost[i] > (c + dp[j][i]))
                    {
                        cost[i] = c + dp[j][i];
                        path[i] = j;
                    }
                }
            }
        }

        // printVector(cost);
        // printVector(path);

        vector<int> ans;

        int start = path[n - 1];
        int end = n - 1;

        while (true)
        {
            ans.push_back(end);
            ans.push_back(start);
            end = start - 1;
            if (end < 0)
            {
                break;
            }
            start = path[end];
        }

        reverse(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] += 1;
        }

        return ans;
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

        int lineSize;
        cin >> lineSize;

        Solution ob;
        vector<int> ans = ob.findCorrectWordArrangement(arr, n, lineSize);
        printVector(ans);
    }
}
