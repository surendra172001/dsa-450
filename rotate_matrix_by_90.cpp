#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    void transpose(vector<vector<int>> &matrix, int n)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

    void rotateby90Anticlockwise(vector<vector<int>> &matrix, int n)
    {
        transpose(matrix, n);

        int mid = n / 2;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < mid; i++)
            {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }
    }

    void rotateby90Clockwise(vector<vector<int>> &matrix, int n)
    {
        transpose(matrix, n);

        int mid = n / 2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < mid; j++)
            {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r;

        cin >> r;

        vector<vector<int>> matrix(r, vector<int>(r));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < r; j++)
                cin >> matrix[i][j];
        }

        Solution ob;

        ob.rotateby90Anticlockwise(matrix, r);
    }
    return 0;
}
