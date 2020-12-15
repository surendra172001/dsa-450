#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void removeDuplicate(vector<int> &A)
{

    int aLen = A.size();

    vector<int> aUnique;

    for (int i = 0; i < aLen;)
    {
        int e = i;
        while (e < aLen && (A[i] == A[e]))
        {
            e += 1;
        }
        aUnique.push_back(A[i]);
        i = e;
    }

    A = aUnique;

    // for(int x : aUnique) {
    //     cout << x << " ";
    // }
    // cout << endl;
}

int findUnionLength(vector<int> &A, vector<int> &B)
{

    removeDuplicate(A);
    removeDuplicate(B);

    int aLen = A.size();
    int bLen = B.size();

    int i = 0; // iterator for A array
    int j = 0; // iterator for B array
    int unionLength = 0;

    while (i < aLen && j < bLen)
    {
        if (A[i] > B[j])
        {
            j += 1;
        }
        else if (A[i] < B[j])
        {
            i += 1;
        }
        else
        {
            i += 1;
            j += 1;
        }
        unionLength += 1;
    }

    while (i < aLen)
    {
        unionLength += 1;
        i += 1;
    }

    while (j < bLen)
    {
        unionLength += 1;
        j += 1;
    }

    return unionLength;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, m;

        cin >> n >> m;

        vector<int> A(n), B(m);

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        for (int j = 0; j < m; j++)
        {
            cin >> B[j];
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int unionLength = findUnionLength(A, B);

        cout << unionLength << endl;
    }
    return 0;
}