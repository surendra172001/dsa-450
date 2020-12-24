#include <algorithm>
#include <climits>
#include <cmath>
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
    vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
    {
        vector<int> ans;

        int vMid = r / 2;
        int hMid = c / 2;

        int i = 0;

        while (i < vMid && i < hMid)
        {

            int R = i, C = i;

            for (; C < c - i - 1; C += 1)
                ans.push_back(matrix[R][C]);
            for (; R < r - i - 1; R += 1)
                ans.push_back(matrix[R][C]);
            for (; C > i; C -= 1)
                ans.push_back(matrix[R][C]);
            for (; R > i; R -= 1)
                ans.push_back(matrix[R][C]);

            i += 1;
        }

        int minM = min(r, c);

        if (minM & 1)
        {
            if (r < c)
            {

                int remRowSize = c - (r - 1);

                int rowEnd = vMid + remRowSize - 1;

                for (int j = vMid; j <= rowEnd; j++)
                {
                    ans.push_back(matrix[vMid][j]);
                }
            }
            else
            {

                int remColSize = r - (c - 1);

                int colEnd = hMid + remColSize - 1;

                for (int j = hMid; j <= colEnd; j++)
                {
                    ans.push_back(matrix[j][hMid]);
                }
            }
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
        int r, c;

        cin >> r >> c;

        vector<vector<int>> matrix(r, vector<int>(c));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                cin >> matrix[i][j];
        }

        Solution ob;

        vector<int> spiralTraversal = ob.spirallyTraverse(matrix, r, c);

        printVector(spiralTraversal);
    }
    return 0;
}
