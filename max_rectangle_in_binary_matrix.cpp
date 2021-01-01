#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

#define MAX 1000

class Solution
{
public:
    int findMaxAreaUnderHistogram(vector<int> &arr, int n)
    {
        vector<int> aux1(n);
        vector<int> aux2(n);

        stack<int> st;

        st.push(0);
        aux1[0] = -1;

        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                aux1[i] = -1;
            }
            else
            {
                aux1[i] = st.top();
            }
            st.push(i);
        }

        while (!st.empty())
        {
            st.pop();
        }

        st.push(n - 1);
        aux2[n - 1] = n;

        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                aux2[i] = n;
            }
            else
            {
                aux2[i] = st.top();
            }
            st.push(i);
        }

        int maxRectangleArea = 0;

        for (int i = 0; i < n; i++)
        {

            int currWidth = aux2[i] - aux1[i] - 1;
            maxRectangleArea = max(maxRectangleArea, currWidth * arr[i]);
        }

        return maxRectangleArea;
    }

    int maxArea(vector<vector<int>> &M, int n, int m)
    {

        vector<int> heights(m);

        int maxRectangleArea = 0;

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    heights[j] = M[i][j];
                }
            }
            else
            {
                for (int j = 0; j < m; j++)
                {
                    heights[j] = (M[i][j] == 0 ? 0 : heights[j] + 1);
                }
            }
            int currArea = findMaxAreaUnderHistogram(heights, m);
            maxRectangleArea = max(maxRectangleArea, currArea);
        }

        return maxRectangleArea;
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

        int maxRectangleArea = ob.maxArea(matrix, r, c);

        cout << maxRectangleArea << endl;
    }
    return 0;
}
