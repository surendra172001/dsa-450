#include <algorithm>
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

class Solution
{
public:
    int findDiameter(Node *root, int &maxNodeCntInAPath)
    {

        if (root == NULL)
        {
            return 0;
        }

        int leftSubtreeHeight = findDiameter(root->left, maxNodeCntInAPath);
        int rightSubtreeHeight = findDiameter(root->right, maxNodeCntInAPath);

        int currPathNodeCnt = 1 + leftSubtreeHeight + rightSubtreeHeight;

        maxNodeCntInAPath = max(maxNodeCntInAPath, currPathNodeCnt);

        return 1 + max(leftSubtreeHeight, rightSubtreeHeight);
    }

    int diameter(Node *root)
    {
        int maxNodeCntInAPath = 0;
        findDiameter(root, maxNodeCntInAPath);
        return maxNodeCntInAPath;
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

        int ans = ob.diameter(root);

        cout << ans << endl;
    }

    return 0;
}