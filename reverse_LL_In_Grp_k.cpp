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
    Node *reverseInGroupK(Node *head, int k)
    {
        Node *last = head;
        Node *curr = head, *prev = NULL, *next = NULL;

        for (int i = 0; i < k; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;

        last->next = curr;

        return head;
    }

    int getLLSize(Node *head)
    {
        int cnt = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            cnt += 1;
            curr = curr->next;
        }
        return cnt;
    }

    void printLL(Node *head)
    {
        if (head == NULL)
        {
            cout << "ERROR\n";
            return;
        }
        Node *curr = head;

        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    struct Node *reverse(struct Node *head, int k)
    {
        int llSize = getLLSize(head);
        int grpCnt = llSize / k;

        Node *prevGrpLast = NULL;
        Node *curr = head;

        for (int i = 0; i < grpCnt; i++)
        {
            curr = reverseInGroupK(curr, k);
            if (prevGrpLast == NULL)
            {
                head = curr;
            }
            else
            {
                prevGrpLast->next = curr;
            }

            prevGrpLast = curr;

            for (int j = 0; j < k - 1; j++)
            {
                prevGrpLast = prevGrpLast->next;
            }

            curr = prevGrpLast->next;
        }

        int remSize = llSize % k;
        if (remSize != 0)
        {
            curr = reverseInGroupK(curr, remSize);
            if (prevGrpLast == NULL)
            {
                head = curr;
            }
            prevGrpLast->next = curr;
        }

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

        int k;
        cin >> k;

        Solution ob;
        Node *revLLHead = ob.reverse(head, k);

        printLL(revLLHead);

        deleteLL(revLLHead);
    }
}
