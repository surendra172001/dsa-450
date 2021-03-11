#include <bits/stdc++.h>

using namespace std;

template <typename T>
class MyCmp
{
public:
    bool operator()(T &a, T &b)
    {
        return a < b;
        // or a > g
        // or some custom condition evaluation
    }
};

void priority_queue_initialization()
{
    // max priority queue
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
}

void printVector(vector<int> &A)
{
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> &mat, int r, int c)
{

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
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

void printArr(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int mainMultiCase()
{
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}

string listToString(list<char> &charList)
{
    string ans;

    for (char ch : charList)
    {
        ans.push_back(ch);
    }

    return ans;
}

void matrixInput()
{
    int r, c;

    cin >> r >> c;

    vector<vector<int>> mat(r, vector<int>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
    }
}

double ternary_search(double l, double r)
{
    double eps = 1e-9; //set the error limit here
    while (r - l > eps)
    {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1); //evaluates the function at m1
        double f2 = f(m2); //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l); //return the maximum of f(x) in [l, r]
}

// Linked List
void printLL(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
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

void clearBuffer()
{
    while ((getchar()) != '\n')
        ;
}

int main()
{
    int x;
    // get type of a variable
    typeid(x).name();
    return 0;
}
