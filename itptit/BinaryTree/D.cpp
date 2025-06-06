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

Node* insert(Node* root, int key)
{
    if (!root)
        root = new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

void RNL(Node* root)
{
    if (!root)
        return;
    RNL(root->right);
    cout << root->data << ' ';
    RNL(root->left);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int a[n];
        for (int& i : a)
            cin >> i;
        Node* root = NULL;
        for (int x : a)
            root = insert(root, x);

        RNL(root);
        cout << endl;
    }
}