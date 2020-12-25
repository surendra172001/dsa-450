#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct Location
    {
        int r, c;
        Location(int r, int c)
        {
            this->r = r;
            this->c = c;
        }
    };

    Location getRowCol(int colSize, int index)
    {
        return Location(index / colSize, index % colSize);
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int s = 0;

        int e = matrix.size() * matrix[0].size() - 1;

        while (s <= e)
        {

            int mid = (s + e) / 2;

            Location newLocation = getRowCol(matrix[0].size(), mid);

            int i = newLocation.r;
            int j = newLocation.c;

            int &key = matrix[i][j];

            // cout << s << " " << e << " " << mid << " " << key<< endl;

            if (key < target)
            {
                s = mid + 1;
            }
            else if (key > target)
            {
                e = mid - 1;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int m, n;

        cin >> m >> n;

        vector<vector<int>> matrix(m, vector<int>(n));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }

        int target;
        cin >> target;

        Solution ob;
        cout << ob.searchMatrix(matrix, target) << endl;
    }
    return 0;
}

/*
1
3 4
1 3 5 7 10 11 16 20 23 30 34 60
3
*/
