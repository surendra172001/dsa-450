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

void append(vector<int> &a, vector<int> &b)
{
    a.insert(a.end(), b.begin(), b.end());
}

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

void printArr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    return 0;
}