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

void makeRoot(Node* root, int par, int child, char dir)
{
    if (dir == 'L')
        root->left = new Node(child);
    if (dir == 'R')
        root->right = new Node(child);
}

void insertNode(Node* root, int par, int child, char dir)
{
    if (root == NULL)
        return;
    if (root->data == par)
        makeRoot(root, par, child, dir);
    else {
        insertNode(root->left, par, child, dir);
        insertNode(root->right, par, child, dir);
    }
}

Node* insert(vector<int>& v, int l, int r)
{
    if (l > r)
        return NULL;
    int m = (l + r) / 2;
    Node* root = new Node(v[m]);
    root->left = insert(v, l, m - 1);
    root->right = insert(v, m + 1, r);
    return root;
}

void inOrder1(Node* root, vector<int>& v)
{
    if (root == nullptr)
        return;
    inOrder1(root->left, v);
    v.push_back(root->data);
    inOrder1(root->right, v);
}

void inOrder2(Node* root)
{
    if (root == nullptr)
        return;
    inOrder2(root->left);
    cout << root->data << ' ';
    inOrder2(root->right);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int par, child;
            char dir;
            cin >> par >> child >> dir;
            if (root == NULL) {
                root = new Node(par);
                makeRoot(root, par, child, dir);
            } else
                insertNode(root, par, child, dir);
        }
        vector<int> v;
        inOrder1(root, v);
        sort(v.begin(), v.end());
        root = insert(v, 0, v.size() - 1);
        inOrder2(root);
        cout << endl;
    }
}