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

Node* insert(Node* root, int x)
{
    if (root == NULL)
        return new Node(x);
    if (x > root->data)
        root->right = insert(root->right, x);
    else
        root->left = insert(root->left, x);
    return root;
}

void findLeaves(Node* root, vector<int>& leaves)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        leaves.push_back(root->data);
    findLeaves(root->left, leaves);
    findLeaves(root->right, leaves);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int pre[n];
        for (int i = 0; i < n; i++)
            cin >> pre[i];
        Node* root = NULL;
        for (int i = 0; i < n; i++)
            root = insert(root, pre[i]);
        vector<int> leaves;
        findLeaves(root, leaves);
        for (auto x : leaves)
            cout << x << ' ';
        cout << endl;
    }
}