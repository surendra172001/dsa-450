#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

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

vector<int> levelOrder(Node *node)
{

    queue<Node *> q;

    q.push(node);

    vector<int> ans;

    while (!q.empty())
    {
        Node *currRoot = q.front();
        q.pop();

        ans.push_back(currRoot->data);

        if (currRoot->left != NULL)
        {
            q.push(currRoot->left);
        }

        if (currRoot->right != NULL)
        {
            q.push(currRoot->right);
        }
    }

    return ans;
}

void printVector(vector<int> &A)
{
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

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
        vector<int> ans = levelOrder(root);
        printVector(ans);
    }
}
