#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void removeDuplicates(int arr[], int &N)
{

    int j = 0;

    for (int i = 0; i < N;)
    {

        int e = i + 1;
        while (e < N && arr[i] == arr[e])
            e += 1;

        arr[j] = arr[i];

        i = e;
        j += 1;
    }

    N = j + 1;
}

// much faster but modifies the array
int findLongestConseqSubseq(int arr[], int N)
{
    int longestConseqSubseq = 0;

    sort(arr, arr + N);

    removeDuplicates(arr, N);

    for (int i = 0; i < N;)
    {

        int e = i + 1;

        while (e < N && (arr[e] - arr[e - 1] == 1))
            e += 1;

        longestConseqSubseq = max(longestConseqSubseq, e - i);

        i = e;
    }

    return longestConseqSubseq;
}

// much slower but doesn't modifies the array
int findLongestConseqSubseq1(int arr[], int N)
{

    int longestConseqSubseq = 0;

    set<int> uniqueElementContainer;

    for (int i = 0; i < N; i++)
    {
        uniqueElementContainer.insert(arr[i]);
    }

    for (set<int>::iterator i = uniqueElementContainer.begin(); i != uniqueElementContainer.end();)
    {

        int currConseqSubseqSize = 1;

        int prevVal = *i;

        set<int>::iterator e = i;
        e++;

        while (e != uniqueElementContainer.end() && ((*e) - prevVal == 1))
        {
            prevVal = *e;
            e++;
            currConseqSubseqSize += 1;
        }

        longestConseqSubseq = max(currConseqSubseqSize, longestConseqSubseq);

        i = e;
    }

    return longestConseqSubseq;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;

        cin >> n;

        int A[n];

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        int ans = findLongestConseqSubseq(A, n);

        cout << ans << endl;
    }
    return 0;
}