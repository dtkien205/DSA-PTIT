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
    if (root == NULL)
        root = new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

void postOrder(Node* root)
{
    if (!root) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cout << "Test #" << t << ": ";
        int n;
        cin >> n;
        int a[n];
        for (int& i : a)
            cin >> i;
        Node* root = NULL;
        for (int x : a)
            root = insert(root, x);
        postOrder(root);
        cout << endl;
    }
}
