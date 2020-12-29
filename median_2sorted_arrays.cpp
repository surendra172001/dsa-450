#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double getMedian(vector<int> &arr)
    {

        int n = arr.size();
        int half = n / 2;

        if ((n & 1) == 0)
        {
            return (arr[half] + arr[half - 1]) / 2.0;
        }
        else
        {
            return arr[half];
        }
    }

    // linear time algorithm
    double findMedianSortedArrays1(vector<int> &arr1, vector<int> &arr2)
    {

        int n1 = arr1.size();
        int n2 = arr2.size();

        if (n1 == 0 && n2 == 0)
        {
            return -1;
        }
        else if (n1 == 0)
        {
            return getMedian(arr2);
        }
        else if (n2 == 0)
        {
            return getMedian(arr1);
        }

        int totalSize = (n1 + n2);

        int half = totalSize / 2;

        int i1 = 0, i2 = 0, k = 0;

        int prev = -1, curr = -1;

        while (i1 < n1 && i2 < n2 && k <= half)
        {

            prev = curr;

            if (arr1[i1] < arr2[i2])
            {

                curr = arr1[i1];
                i1 += 1;
            }
            else
            {

                curr = arr2[i2];
                i2 += 1;
            }

            k += 1;
        }

        while (i1 < n1 && k <= half)
        {
            prev = curr;
            curr = arr1[i1];
            i1 += 1;
            k += 1;
        }

        while (i2 < n2 && k <= half)
        {
            prev = curr;
            curr = arr2[i2];
            i2 += 1;
            k += 1;
        }

        if ((totalSize & 1) == 0)
        {
            // cout << i1 << " " << i2 << " " << k << " " << curr << " " << prev << endl;
            return (prev + curr) / 2.0;
        }
        else
        {
            return curr;
        }
    }

    double findMedianSortedArraysUtil(vector<int> &arr1, vector<int> &arr2)
    {

        int n1 = arr1.size();
        int n2 = arr2.size();

        int totalSize = n1 + n2;

        int half = (n1 + n2 + 1) / 2;

        int s1 = 0, e1 = n1;

        while (s1 <= e1)
        {

            int p1 = (s1 + e1) / 2;
            int p2 = half - p1;

            int maxInLeft1 = (p1 <= 0 ? INT_MIN : arr1[p1 - 1]);
            int minInRight1 = (p1 >= n1 ? INT_MAX : arr1[p1]);

            int maxInLeft2 = (p2 <= 0 ? INT_MIN : arr2[p2 - 1]);
            int minInRight2 = (p2 >= n2 ? INT_MAX : arr2[p2]);

            if (maxInLeft1 > minInRight2)
            {
                e1 = p1 - 1;
            }
            else if (maxInLeft2 > minInRight1)
            {
                s1 = p1 + 1;
            }
            else
            {
                if ((totalSize & 1) == 0)
                {
                    return (max(maxInLeft1, maxInLeft2) + min(minInRight1, minInRight2)) / 2.0;
                }
                else
                {
                    return max(maxInLeft1, maxInLeft2);
                }
            }
        }
        return -1;
    }

    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
    {

        int n1 = arr1.size();
        int n2 = arr2.size();

        if (n1 == 0 && n2 == 0)
        {
            return -1;
        }
        else if (n1 == 0)
        {
            return getMedian(arr2);
        }
        else if (n2 == 0)
        {
            return getMedian(arr1);
        }

        if (n1 < n2)
        {
            return findMedianSortedArraysUtil(arr1, arr2);
        }
        else
        {
            return findMedianSortedArraysUtil(arr2, arr1);
        }
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n1, n2; // size of both the arrays

        cin >> n1 >> n2;

        vector<int> arr1(n1);
        vector<int> arr2(n2);

        for (int i = 0; i < n1; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> arr2[i];
        }

        Solution ob;

        double median = ob.findMedianSortedArrays(arr1, arr2);

        cout << median << endl;
    }
    return 0;
}
