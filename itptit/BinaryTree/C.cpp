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

void duyet(Node* root)
{
    queue<Node*> q;
    q.push(root);
    cout << root->data << ' ';

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();

        if (tmp->right) {
            q.push(tmp->right);
            cout << tmp->right->data << ' ';
        }

        if (tmp->left) {
            q.push(tmp->left);
            cout << tmp->left->data << ' ';
        }
    }
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
        duyet(root);
        cout << endl;
    }
}