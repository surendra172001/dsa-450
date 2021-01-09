#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void longestPalindromicSubstringUtil(string &str, int l, int r, int &startIdx, int &maxLen)
    {

        int n = str.length();

        while (l >= 0 && r < n && (str[l] == str[r]))
        {
            l -= 1;
            r += 1;
        }

        l += 1;
        r -= 1;

        if (maxLen < r - l + 1)
        {
            maxLen = r - l + 1;
            startIdx = l;
        }
    }

    string longestPalindromicSubstring(string &str)
    {

        int maxLen = 1;
        int startIdx = 0;

        int n = str.length();

        for (int i = 0; i < n; i++)
        {
            longestPalindromicSubstringUtil(str, i, i + 1, startIdx, maxLen);
            longestPalindromicSubstringUtil(str, i - 1, i + 1, startIdx, maxLen);
        }

        return str.substr(startIdx, maxLen);
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

        string ans = ob.longestPalindromicSubstring(str);

        cout << ans << endl;
    }

    return 0;
}