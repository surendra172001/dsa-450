
#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int splitBinary(string const &input)
{

    stack<char> st;

    int ans = 0;

    char charInStack = '\0';

    for (char ch : input)
    {

        if (st.empty())
        {
            charInStack = ch;
            st.push(ch);
        }
        else
        {
            if (ch == charInStack)
            {
                st.push(ch);
            }
            else
            {

                st.pop();

                if (st.empty())
                {
                    ans += 1;
                }
            }
        }
    }

    if (!st.empty())
    {
        return -1;
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string input;
        cin >> input;

        int ans = splitBinary(input);

        cout << ans << endl;
    }
    return 0;
}
