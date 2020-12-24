#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> &A)
{
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

void reverseVec(vector<int> &vec)
{

    int mid = vec.size() / 2;

    for (int i = 0; i < mid; i++)
    {
        swap(vec[i], vec[vec.size() - i - 1]);
    }
}

int main()
{
    return 0;
}