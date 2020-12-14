#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int zeroCnt = 0;
    int oneCnt = 0;
    int twoCnt = 0;
    for (int i = 0; i < n; i++)
    {
        zeroCnt += int(a[i] == 0);
        oneCnt += int(a[i] == 1);
        twoCnt += int(a[i] == 2);
    }
    int i = 0;
    for (; i < zeroCnt; i++)
    {
        a[i] = 0;
    }
    for (; i < zeroCnt + oneCnt; i++)
    {
        a[i] = 1;
    }
    for (; i < zeroCnt + oneCnt + twoCnt; i++)
    {
        a[i] = 2;
    }
}

int main()
{
    return 0;
}