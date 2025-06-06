#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

int a[10005], n;

Node* build(int i)
{
    if (i >= n)
        return NULL;
    Node* root = new Node(a[i]);
    root->left = build(2 * i + 1);
    root->right = build(2 * i + 2);
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

void duyet(int i)
{
    if (i >= n)
        return;
    duyet(2 * i + 1);
    cout << a[i] << ' ';
    duyet(2 * i + 2);
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
        // Node* root = build(0);
        // inOrder(root);
        duyet(0);
        cout << endl;
    }
}