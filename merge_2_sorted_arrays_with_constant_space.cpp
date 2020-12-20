#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void printArr(int arr[], int n)
{
    cout << n << ": ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    void mergeUsingInsertion(int arr1[], int arr2[], int m, int n)
    {

        for (int i = n - 1; i >= 0; i--)
        {

            if (arr1[m - 1] > arr2[i])
            {

                swap(arr1[m - 1], arr2[i]);

                int j = m - 1;

                while (j > 0 && (arr1[j - 1] > arr1[j]))
                {

                    swap(arr1[j - 1], arr1[j]);
                    j -= 1;
                }
            }
        }
    }

    void iterateWithGapWidth(int arr1[], int arr2[], int n1, int n2, int gap)
    {
        int totalSize = n1 + n2;
        int leftIdx = 0, rightIdx = 0 + gap;
        while (rightIdx < totalSize)
        {
            if (rightIdx < n1)
            {
                if (arr1[leftIdx] > arr1[rightIdx])
                {
                    swap(arr1[leftIdx], arr1[rightIdx]);
                }
            }
            else if (leftIdx < n1)
            {
                if (arr1[leftIdx] > arr2[rightIdx - n1])
                {
                    swap(arr1[leftIdx], arr2[rightIdx - n1]);
                }
            }
            else
            {
                if (arr2[leftIdx - n1] > arr2[rightIdx - n1])
                {
                    swap(arr2[leftIdx - n1], arr2[rightIdx - n1]);
                }
            }
            leftIdx += 1;
            rightIdx += 1;
        }
    }

    void merge(int arr1[], int arr2[], int n1, int n2)
    {

        int gap = ceil((n1 + n2) / 2);

        int oneCnt = 0;

        while (gap > 0 && oneCnt < 2)
        {
            iterateWithGapWidth(arr1, arr2, n1, n2, gap);
            // printArr(arr1, n1);
            // printArr(arr2, n2);
            gap = ceil((double)gap / 2);

            oneCnt += (gap == 1 ? 1 : 0);
        }
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n1, n2;

        cin >> n1 >> n2;

        int arr1[n1];
        int arr2[n2];

        for (int i = 0; i < n1; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < n2; i++)
        {
            cin >> arr2[i];
        }

        Solution ob;
        ob.merge(arr1, arr2, n1, n2);

        printArr(arr1, n1);
        printArr(arr2, n2);
    }
    return 0;
}
