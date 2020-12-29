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
    vector<int> getElementsInSortedOrder(vector<vector<int>> &matrix, int r, int c)
    {
        vector<int> ans = matrix[0];

        for (int i = 1; i < r; i++)
        {

            int n1 = ans.size();

            int n2 = c;

            int i1 = 0;

            int i2 = 0;

            vector<int> &arr1 = ans;
            vector<int> &arr2 = matrix[i];

            vector<int> aux;

            while (i1 < n1 && i2 < n2)
            {
                if (arr1[i1] < arr2[i2])
                {
                    aux.push_back(arr1[i1]);
                    i1 += 1;
                }
                else
                {
                    aux.push_back(arr2[i2]);
                    i2 += 1;
                }
            }

            while (i1 < n1)
            {
                aux.push_back(arr1[i1]);
                i1 += 1;
            }

            while (i2 < n2)
            {
                aux.push_back(arr2[i2]);
                i2 += 1;
            }

            ans = aux;
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

        int n;

        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> matrix[i][j];
        }

        Solution ob;

        vector<int> ans = ob.getElementsInSortedOrder(matrix, n, n);

        printVector(ans);
    }
    return 0;
}
