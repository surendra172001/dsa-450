#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

void printArr(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n)
{
    int minJump[n];
    for (int i = 0; i < n; i++)
    {
        minJump[i] = INT_MAX;
    }

    minJump[0] = 0;

    for (int i = 0; i < n; i++)
    {

        if (minJump[i] == INT_MAX)
        {
            return -1;
        }

        int j = i + 1;
        int cnt = arr[i];

        while (cnt > 0 && j < n)
        {
            minJump[j] = min(minJump[j], minJump[i] + 1);
            cnt -= 1;
            j += 1;
        }
    }

    return minJump[n - 1];
}

int minJumpsOptimized(int arr[], int n)
{

    int prevWindowLastIdx = 0;
    int currWindowSize = arr[0];
    int steps = 0;

    while (prevWindowLastIdx < n - 1)
    {

        if (currWindowSize == 0)
        {
            return -1;
        }

        int currWindowEndIdx = prevWindowLastIdx + currWindowSize;
        currWindowEndIdx = (currWindowEndIdx >= n ? n - 1 : currWindowEndIdx);

        int newWindowSize = 0;

        for (int i = prevWindowLastIdx + 1; i <= currWindowEndIdx; i++)
        {

            // no of elements left after ith index in the current window
            int x = currWindowEndIdx - i;

            newWindowSize = max(newWindowSize, arr[i] - x);
        }

        prevWindowLastIdx = currWindowEndIdx;
        currWindowSize = newWindowSize;
        steps += 1;
    }

    return steps;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        cout << minJumpsOptimized(arr, n) << endl;
    }
    return 0;
}