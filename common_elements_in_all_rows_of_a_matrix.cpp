#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <stack>
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

void sortRowWise(vector<vector<int>> &mat, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        sort(mat[i].begin(), mat[i].end());
    }
}

class Solution
{
public:
    vector<int> getCommonElementsInAllRows1(vector<vector<int>> &mat, int r, int c)
    {
        sortRowWise(mat, r, c);

        vector<int> ans;

        vector<int> itr(r);

        for (int j = 0; j < c;)
        {

            int key = mat[0][j];

            bool keyNotFound = false;

            for (int i = 1; i < r; i++)
            {
                while (itr[i] < c && mat[i][itr[i]] < key)
                {
                    itr[i] += 1;
                }

                if (itr[i] == c || mat[i][itr[i]] > key)
                {
                    keyNotFound = true;
                    break;
                }
            }

            if (keyNotFound == false)
            {
                ans.push_back(key);
            }

            int e = j + 1;

            while (e < c && (mat[0][e] == mat[0][j]))
            {
                e += 1;
            }

            j = e;
        }

        return ans;
    }

    vector<int> getCommonElementsInAllRows2(vector<vector<int>> &mat, int r, int c)
    {

        vector<int> ans;

        map<int, int> countHolder;

        for (int j = 0; j < c; j++)
        {
            countHolder[mat[0][j]] = 1;
        }

        for (int i = 1; i < r; i++)
        {
            for (int j = 0; j < c;)
            {

                if (countHolder.count(mat[i][j]) > 0)
                {
                    countHolder[mat[i][j]] += 1;
                }

                int e = j + 1;

                while (e < c && (mat[i][j] == mat[i][e]))
                {
                    e += 1;
                }
                j = e;
            }
        }

        for (map<int, int>::iterator it = countHolder.begin(); it != countHolder.end(); it++)
        {
            if (it->second == r)
            {
                ans.push_back(it->first);
            }
        }

        return ans;
    }
};

/*
1 
4 5
1 1 2 4 8
1 3 5 7 8
1 3 7 7 8
1 2 7 8 9
*/

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;

        cin >> r >> c;

        vector<vector<int>> mat(r, vector<int>(c));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;

        vector<int> ans = ob.getCommonElementsInAllRows2(mat, r, c);

        printVector(ans);
    }
    return 0;
}
