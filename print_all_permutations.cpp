#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> printAllPermutationUtil(string &str, int curr, int n)
    {

        if (curr == n - 1)
        {
            return vector<string>(1, string(1, str[curr]));
        }

        vector<string> smallAns = printAllPermutationUtil(str, curr + 1, n);

        // cout << curr << endl;
        // for (int i = 0; i < smallAns.size(); i++)
        // {
        //     cout << smallAns[i] << endl;
        // }

        int m = smallAns[0].length();

        vector<string> ans;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < smallAns.size(); j++)
            {

                string s = smallAns[j];

                s.insert(i, string(1, str[curr]));

                ans.push_back(s);
            }
        }

        for (int j = 0; j < smallAns.size(); j++)
        {
            string s = smallAns[j];

            s.append(string(1, str[curr]));

            ans.push_back(s);
        }

        return ans;
    }

    vector<string> printAllPermutation(string &str)
    {
        int n = str.length();

        return printAllPermutationUtil(str, 0, n);
    }
};

void printStringVec(vector<string> &stringVec)
{
    for (int i = 0; i < stringVec.size(); i++)
    {
        cout << stringVec[i] << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string str;

        cin >> str;

        Solution ob;

        vector<string> ans = ob.printAllPermutation(str);

        set<string> uniqueAns(ans.begin(), ans.end());

        for (auto permutation : uniqueAns)
        {
            cout << permutation << " ";
        }
        cout << endl;
    }

    return 0;
}