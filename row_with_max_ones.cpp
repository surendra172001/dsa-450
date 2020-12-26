#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {

        int ansIdx = -1;

        int smallestStartIdxForOnes = m;

        for (int i = 0; i < n; i++)
        {
            if (smallestStartIdxForOnes == m)
            {
                int j = m - 1;

                while (j >= 0 && arr[i][j] == 1)
                {
                    j -= 1;
                }

                j += 1;

                if (j < m)
                {
                    smallestStartIdxForOnes = j;
                    ansIdx = i;
                }
            }
            else if (arr[i][smallestStartIdxForOnes] == 1)
            {

                int prevValue = smallestStartIdxForOnes;

                while (smallestStartIdxForOnes >= 0 && arr[i][smallestStartIdxForOnes] == 1)
                {
                    smallestStartIdxForOnes -= 1;
                }

                smallestStartIdxForOnes += 1;

                if (prevValue > smallestStartIdxForOnes)
                {
                    ansIdx = i;
                }
            }

            // here we are supposed to return the first row that contains the maximum
            // number of ones. so when smallestStartIdxForOnes equals to 0 then threre
            // could not be any row that contains more number of ones and we are supposed to return
            // the first row that contains the maximum number of one's so we return the current row
            // immediately

            if (smallestStartIdxForOnes == 0)
            {
                return i;
            }
        }

        return ansIdx;
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

        int rowNumber = ob.rowWithMax1s(matrix, r, c);

        cout << rowNumber << endl;
    }
    return 0;
}
