#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string intToString(int num)
    {
        string ans;

        while (num > 0)
        {
            ans += char((num % 10) + 48);
            num /= 10;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    string createCntString(string &str)
    {
        int s = 0;
        int e = str.length() - 1;

        string ans;

        while (s <= e)
        {
            int i = s + 1;

            while (i <= e && str[i] == str[s])
            {
                i += 1;
            }

            int cnt = i - s;

            string temp = intToString(cnt);

            ans += temp;

            ans += str[s];

            s = i;
        }
        return ans;
    }

    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }

        string partialAns = countAndSay(n - 1);

        return createCntString(partialAns);
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int num;

        cin >> num;

        Solution ob;

        string ans = ob.countAndSay(num);

        cout << ans << endl;
    }

    return 0;
}