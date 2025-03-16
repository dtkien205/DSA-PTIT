#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct node {
    int data;
    node *left, *right;
    node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

node* insert(node* root, int x)
{
    if (root == nullptr)
        return new node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

void posOrder(node* root)
{
    if (root == nullptr)
        return;
    posOrder(root->left);
    posOrder(root->right);
    cout << root->data << ' ';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        node* root = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        posOrder(root);
        cout << endl;
    }
}