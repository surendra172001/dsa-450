#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    priority_queue<int> h1;
    priority_queue<int, vector<int>, greater<int>> h2;

    int totalSize = 0;

    // Function to insert heap
    void insertHeap(int &x)
    {
        if (h1.empty())
        {
            h1.push(x);
        }
        else
        {
            if (h1.top() >= x)
            {
                h1.push(x);
            }
            else
            {
                h2.push(x);
            }
        }
        totalSize += 1;
        balanceHeaps();
    }

    // Function to balance heaps
    void balanceHeaps()
    {
        if (h2.size() > h1.size())
        {
            h1.push(h2.top());
            h2.pop();
        }
        else if (h1.size() - h2.size() > 1)
        {
            h2.push(h1.top());
            h1.pop();
        }
        // h1 size should be greater than h2
        //  if h1 size is > and the diff betwn the sizes is more than one than pop
        // one element from the top of the h1 and put it inside h2
    }

    // Function to return getMedian
    double getMedian()
    {
        if (totalSize % 2 == 0)
        {
            return (h1.top() + h2.top()) / 2.0;
        }
        else
        {
            return h1.top();
        }
    }
};

int main()
{
    int tt;
    cin >> tt;
    while (tt--)
    {
        int n, x;
        cin >> n;
        Solution ob;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << ob.getMedian() << endl;
        }
    }

    return 0;
}
