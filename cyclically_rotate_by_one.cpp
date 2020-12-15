#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &A)
{
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

void cyclicallyRotateByN(vector<int> &A, int offset)
{
    int aLen = A.size();
    vector<int> B(aLen);
    for (int i = 0; i < aLen; i++)
    {
        int newPosition = (offset + i) % aLen;
        B[newPosition] = A[i];
    }
    A = B;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;

        cin >> n;

        vector<int> A(n);

        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }

        int offset;

        cin >> offset;

        cyclicallyRotateByN(A, offset);

        printVector(A);
    }
    return 0;
}