#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int LongestRepeatingSubsequence(string str)
    {
        int n = str.length();

        int dp[n][n];

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < n; i++)
        {
            dp[0][i] = max(int(str[0] == str[i]), dp[0][i - 1]);
            dp[i][0] = max(int(str[0] == str[i]), dp[i - 1][0]);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (i != j && (str[i] == str[j]))
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n - 1][n - 1];
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string str;

        cin >> str;

        Solution ob;

        int ans = ob.LongestRepeatingSubsequence(str);

        cout << ans << endl;
    }

    return 0;
}