#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
    void printAllSequenceUtil(vector<string> &ans, string &originalStr, string str, int curr, int n)
    {
        if (curr == n)
        {
            ans.push_back(str);
            return;
        }
        printAllSequenceUtil(ans, originalStr, str + string(1, originalStr[curr]), curr + 1, n);
        printAllSequenceUtil(ans, originalStr, str, curr + 1, n);
    }

    vector<string> printAllSequence(string &str)
    {
        int n = str.length();

        vector<string> ans;

        printAllSequenceUtil(ans, str, "", 0, n);

        return ans;
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

        vector<string> ans = ob.printAllSequence(str);

        set<string> uniqueAns(ans.begin(), ans.end());

        for (auto permutation : uniqueAns)
        {
            cout << permutation << " ";
        }
        cout << endl;
    }

    return 0;
}