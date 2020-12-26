#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int getMedian(int arr[], int start, int end)
    {
        int mid = (start + end) / 2;

        int arrSize = end - start + 1;

        if (arrSize & 1 == 0)
        {
            return (arr[mid] + arr[mid + 1]) / 2;
        }
        else
        {
            return arr[mid];
        }
    }

    double findMedianOf2SortedArraysOfSameSize(int arr1[], int arr2[], int n)
    {

        if (n == 1)
        {
            return (arr1[0] + arr2[0]) / 2.0;
        }

        int s1 = 0, e1 = n - 1;
        int s2 = 0, e2 = n - 1;

        while (true && s2 < e2)
        {
            // cout << s1 << " " << e1 << " " << s2 << " " << e2 << endl;

            int currSize = e2 - s2 + 1;

            if (currSize == 2)
            {
                int m1 = max(arr1[s1], arr2[s2]);
                int m2 = max(arr1[e1], arr2[e2]);
                return (m1 + m2) / 2.0;
            }
            else
            {

                int m1 = getMedian(arr1, s1, e1);
                int m2 = getMedian(arr2, s2, e2);

                if (m1 == m2)
                {
                    return m1;
                }
                else if (m1 < m2)
                {

                    if (currSize & 1 == 0)
                    {
                        s1 = s1 + (currSize / 2) - 1;
                        e2 = e2 - (currSize / 2) + 1;
                    }
                    else
                    {
                        s1 = s1 + (currSize / 2);
                        e2 = e2 - (currSize / 2);
                    }
                }
                else
                {

                    if (currSize & 1 == 0)
                    {
                        s2 = s2 + (currSize / 2) - 1;
                        e1 = e1 - (currSize / 2) + 1;
                    }
                    else
                    {
                        s2 = s2 + (currSize / 2);
                        e1 = e1 - (currSize / 2);
                    }
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
        int n; // size of both the arrays

        cin >> n;

        int arr1[n];
        int arr2[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> arr2[i];
        }

        Solution ob;

        double median = ob.findMedianOf2SortedArraysOfSameSize(arr1, arr2, n);

        cout << median << endl;
    }
    return 0;
}
