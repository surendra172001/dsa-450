#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void printLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void deleteLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        delete curr;
        curr = temp;
    }
}

Node *inputLL(Node *head, int n)
{
    Node *curr = head;

    for (int i = 0; i < n; i++)
    {
        cin >> (curr->data);
        if (i != n - 1)
        {
            curr->next = new Node();
        }
        curr = curr->next;
    }

    return head;
}

class Solution
{
public:
    Node *reverseListUtil(Node *prev, Node *curr)
    {
        if (curr == NULL)
        {
            return prev;
        }
        Node *next = curr->next;
        curr->next = prev;
        return reverseListUtil(curr, next);
    }

    Node *reverseListRec(Node *head)
    {
        return reverseListUtil(NULL, head);
    }

    struct Node *reverseListItr(struct Node *head)
    {
        Node *prev = NULL,
             *curr = head,
             *next = NULL;

        // printLL(head);

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        // printLL(head);
        return head;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        Node *head = new Node();

        head = inputLL(head, n);

        Solution ob;
        Node *revLLHead = ob.reverseListItr(head);

        printLL(revLLHead);

        deleteLL(revLLHead);
    }
}
