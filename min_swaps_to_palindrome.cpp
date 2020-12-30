#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

class Solution
{
public:
    void leftShift(string &str, int s, int e)
    {
        char ch = str[s];

        for (int i = s + 1; i <= e; i++)
        {
            str[i - 1] = str[i];
        }

        str[e] = ch;
    }

    int findMinimumSwapsToPalindrome(string &str)
    {

        int n = str.length();
        int mid = n / 2;

        int swapCnt = 0;

        for (int i = 0; i < mid; i++)
        {

            if (str[i] != str[n - i - 1])
            {
                int l = n - i - 1;
                while (l > i && str[l] != str[i])
                {
                    l -= 1;
                }
                if (l <= i)
                {
                    return -1;
                }
                swapCnt += n - i - 1 - l;
                leftShift(str, l, n - i - 1);
            }
        }

        return swapCnt;
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
        int minimumSwaps = ob.findMinimumSwapsToPalindrome(s);

        cout << minimumSwaps << endl;
    }
}