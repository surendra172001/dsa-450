#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Function to find majority element in the array
    // a: input array
    // size: size of input array

    class ElementCount
    {
    public:
        int e, cnt;
        ElementCount()
        {
            e = -1, cnt = 0;
        }
    };

    int findIdx(vector<ElementCount> &bucket, int key)
    {
        int idx = -1;
        for (int i = 0; i < bucket.size(); i++)
        {
            ElementCount &b = bucket[i];
            if (b.e == key)
            {
                idx = i;
                break;
            }
        }
        return idx;
    }

    bool isArrayFull(vector<ElementCount> &bucket)
    {

        bool ans = true;

        for (int i = 0; i < bucket.size(); i++)
        {
            ElementCount &b = bucket[i];
            if (b.cnt <= 0)
            {
                ans = false;
                break;
            }
        }

        return ans;
    }

    void insertInBucket(vector<ElementCount> &bucket, int key)
    {
        for (int i = 0; i < bucket.size(); i++)
        {
            ElementCount &b = bucket[i];
            if (b.cnt <= 0)
            {
                b.e = key;
                b.cnt = 1;
                break;
            }
        }
    }

    void decreaseCntBy1(vector<ElementCount> &bucket)
    {
        for (int i = 0; i < bucket.size(); i++)
        {
            bucket[i].cnt -= 1;
        }
    }

    int majorityElementUtil(int a[], int k, int n)
    {

        if (k == 0)
        {
            return a[0];
        }

        int bucketSize = ceil(n / k);
        // cout << bucketSize << endl;

        vector<ElementCount> bucket(bucketSize);

        for (int i = 0; i < n; i++)
        {
            int currIdx = findIdx(bucket, a[i]);
            if (currIdx != -1)
            {
                // cout << i << " -1 " << endl;
                bucket[currIdx].cnt += 1;
            }
            else if (isArrayFull(bucket) == true)
            {
                // cout << i << " decrease " << endl;
                decreaseCntBy1(bucket);
            }
            else
            {
                // cout << i << " insert " << endl;
                insertInBucket(bucket, a[i]);
            }
        }

        int ans = -1;

        for (ElementCount &b : bucket)
        {
            // cout << b.e << " " << b.cnt << endl;
            if (b.cnt > 0)
            {
                int currElementCnt = 0;
                for (int i = 0; i < n; i++)
                {
                    currElementCnt += int(a[i] == b.e);
                }
                if (currElementCnt > n / 2)
                {
                    ans = b.e;
                    break;
                }
            }
        }

        return ans;
    }

    int majorityElement(int a[], int size)
    {
        return majorityElementUtil(a, size / 2, size);
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

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        Solution ob;
        int ans = ob.majorityElement(arr, n);

        cout << ans << endl;

        delete[] arr;
    }
}
