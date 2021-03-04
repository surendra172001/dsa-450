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
    int findTarget(int *arr, int n, int k, int target)
    {

        int ans = -1;

        int i = 0;

        while (i < n)
        {
            if (arr[i] == target)
            {
                ans = i;
                break;
            }

            int offSet = ceil(abs(target - arr[i]) / double(k));

            assert(offSet != 0 && "Wrong assumptions");

            i += offSet;
        }

        return ans;
    }
};

/*
1                                                                                                                                                                            
6 20                                                                                                                                                                         
20 40 50 70 70 60                                                                                                                                                            
60
*/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int target;
        cin >> target;

        Solution ob;
        int ans = ob.findTarget(arr, n, k, target);

        cout << ans << endl;

        delete[] arr;
    }
}
