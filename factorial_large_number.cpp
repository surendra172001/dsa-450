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

void reverseVec(vector<int> &vec)
{

    int mid = vec.size() / 2;

    for (int i = 0; i < mid; i++)
    {
        swap(vec[i], vec[vec.size() - i - 1]);
    }
}

vector<int> intToVector(int num)
{

    vector<int> ans;

    while (num > 0)
    {

        ans.push_back(num % 10);
        num /= 10;
    }

    reverseVec(ans);

    return ans;
}

vector<int> multiply(vector<int> &multiplicand, int multiplier)
{

    int carry = 0;

    vector<int> ans;

    for (int i = multiplicand.size() - 1; i >= 0; i--)
    {

        int totalSum = multiplicand[i] * multiplier + carry;

        carry = totalSum / 10;

        ans.push_back(totalSum % 10);
    }

    if (carry > 0)
    {

        vector<int> carryVec = intToVector(carry);

        reverseVec(carryVec);

        ans.insert(ans.end(), carryVec.begin(), carryVec.end());
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

vector<int> calculateFactorial(int num)
{

    vector<int> factorial = intToVector(num);

    for (int i = num - 1; i > 1; i--)
    {
        factorial = multiply(factorial, i);
    }

    return factorial;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int num;

        cin >> num;

        vector<int> factorial = calculateFactorial(num);

        for (int i = 0; i < factorial.size(); i++)
        {
            cout << factorial[i];
        }

        cout << endl;
    }

    return 0;
}