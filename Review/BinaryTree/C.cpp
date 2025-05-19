#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[100005];

void inorder(int i)
{
    if (i >= n)
        return;
    inorder(2 * i + 1);
    cout << a[i] << ' ';
    inorder(2 * i + 2);
}

struct Node {
    int data;
    Node *left, *right;
    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

Node* build(int i, int n, int a[])
{
    if (i >= n)
        return NULL;
    Node* root = new Node(a[i]);
    root->left = build(2 * i + 1, n, a);
    root->right = build(2 * i + 2, n, a);
    return root;
}

void inOrder(Node* root)
{
    if (!root)
        return;
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Node* root = build(0, n, a);
        inOrder(root);
        // inorder(0);
        cout << endl;
    }
}