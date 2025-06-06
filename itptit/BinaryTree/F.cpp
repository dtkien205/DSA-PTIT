#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[100005];

void duyet(int i)
{
    if (i >= n)
        return;
    duyet(2 * i + 1);
    duyet(2 * i + 2);
    cout << a[i] << ' ';
}

struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node* build(int i)
{
    if (i >= n)
        return NULL;
    Node* root = new Node(a[i]);
    root->left = build(2 * i + 1);
    root->right = build(2 * i + 2);
    cout << a[i] << ' ';
    return root;
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
        // duyet(0);
        Node* root = NULL;
        root = build(0);
        cout << endl;
    }
}