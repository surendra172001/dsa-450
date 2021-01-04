
#include <iostream>
#include <string>

using namespace std;

bool compareString(string &str1, string &str2, int offSet)
{
    int n = str1.length();
    for (int i = 0; i < str1.length(); i++)
    {
        int j = (i + offSet) % n;
        if (str1[i] != str2[j])
        {
            return false;
        }
    }
    return true;
}

bool checkRotation1(string &str1, string &str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    int n = str1.length();
    for (int i = 0; i < n; i++)
    {
        if (compareString(str1, str2, i))
        {
            return true;
        }
    }
    return false;
}

bool checkRotation2(string &str1, string &str2)
{
    if (str1.length() != str2.length())
    {
        return false;
    }
    int n = str1.length();
    string temp = str1 + str1;
    return (temp.find(str2) != temp.npos);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1, str2;

        cin >> str1;

        cin >> str2;

        bool isRotation = checkRotation2(str1, str2);

        std::cout << isRotation << std::endl;
    }
    return 0;
}