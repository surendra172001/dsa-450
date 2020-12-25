#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isPlaindrome(string s)
    {
        int mid = s.size() / 2;
        for (int i = 0; i < mid; i++)
        {
            if (s[i] != s[s.size() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.isPlaindrome(s) << endl;
    }
    return 0;
}
