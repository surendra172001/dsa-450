#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
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

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int data = -1, Node *left = NULL, Node *right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

void deleteTree(Node *head)
{
    if (head == NULL)
        return;
    deleteTree(head->left);
    deleteTree(head->right);
    delete head;
    head = NULL;
}

Node *buildTree(string str)
{

    if (str.length() == 0 || str[0] == 'N')
    {
        return NULL;
    }

    stringstream ss(str);

    vector<string> ip;

    for (string num; ss >> num;)
    {
        ip.push_back(num);
    }

    Node *root = new Node(stoi(ip[0]));

    queue<Node *> q;

    q.push(root);

    int i = 1;

    while (i < ip.size())
    {
        Node *currRoot = q.front();
        q.pop();

        if (ip[i] != "N")
        {
            currRoot->left = new Node(stoi(ip[i]));
            q.push(currRoot->left);
        }
        i++;

        if (i >= ip.size())
        {
            break;
        }

        if (ip[i] != "N")
        {
            currRoot->right = new Node(stoi(ip[i]));
            q.push(currRoot->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        if (root == NULL)
        {
            return vector<int>();
        }

        stack<Node *> st;
        vector<int> ans;
        Node *curr = root;

        while (!st.empty() || curr != NULL)
        {
            if (curr != NULL)
            {
                ans.push_back(curr->data);
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = st.top()->right;
                st.pop();
            }
        }

        return ans;
    }

    vector<int> inOrder(Node *root)
    {
        stack<Node *> st;
        vector<int> ans;

        Node *curr = root;

        while (!st.empty() || curr != NULL)
        {
            if (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                ans.push_back(st.top()->data);
                curr = st.top()->right;
                st.pop();
            }
        }

        return ans;
    }

    vector<int> postOrder(Node *root)
    {
        // boolean part tells whether right subtree explored or not
        stack<pair<Node *, bool>> st;
        vector<int> ans;

        Node *curr = root;

        while (!st.empty() || curr != NULL)
        {
            if (curr != NULL)
            {
                st.push({curr, false});
                curr = curr->left;
            }
            else
            {
                if (st.top().second == false)
                { // right subtree unexplored
                    st.top().second = true;
                    curr = st.top().first->right;
                }
                else
                {
                    ans.push_back(st.top().first->data);
                    st.pop();
                }
            }
        }

        return ans;
    }
};

void clearBuffer()
{
    while ((getchar()) != '\n')
        ;
}

int main()
{
    int t;
    cin >> t;

    clearBuffer();

    while (t--)
    {
        string str;

        getline(cin, str);

        Node *root = buildTree(str);

        Solution ob;

        vector<int> preOrderTraversal = ob.preorder(root);

        printVector(preOrderTraversal);

        deleteTree(root);
    }

    return 0;
}