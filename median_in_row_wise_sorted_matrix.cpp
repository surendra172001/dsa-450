#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void findLessThanAndEqualToKey(vector<vector<int>> &matrix, int r, int c, int key, int &ltk, int &etk)
    {
        // ltk -> less than key
        // etk -> equal to key

        for (int i = 0; i < r; i++)
        {

            vector<int>::iterator it = lower_bound(matrix[i].begin(), matrix[i].end(), key);

            int notLessThanPos = it - matrix[i].begin();

            int e = notLessThanPos;

            while (e < matrix[i].size() && matrix[i][e] == key)
            {
                e += 1;
            }

            ltk += notLessThanPos;

            etk += e - notLessThanPos;
        }
    }

    int median(vector<vector<int>> &matrix, int r, int c)
    {

        int start = INT_MAX;
        int end = INT_MIN;

        for (int i = 0; i < r; i++)
        {

            start = min(start, matrix[i][0]);
            end = max(end, matrix[i][c - 1]);
        }

        int half = (r * c) / 2;

        while (start <= end)
        {

            int mid = start + (end - start) / 2;

            int lessThanMidCnt = 0;
            int equalToMidCnt = 0;

            findLessThanAndEqualToKey(matrix, r, c, mid, lessThanMidCnt, equalToMidCnt);

            if (lessThanMidCnt > half)
            {
                end = mid - 1;
            }
            else
            { // lessThanMidCnt <= half

                int total = lessThanMidCnt + equalToMidCnt;

                if (total > half)
                {
                    return mid;
                }
                else
                {
                    start = mid + 1;
                }
            }
        }

        return -1;
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

        int rowNumber = ob.median(matrix, r, c);

        cout << rowNumber << endl;
    }
    return 0;
}
