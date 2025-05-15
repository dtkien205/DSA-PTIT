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

int maxPath = INT_MIN;

int dfs(Node* root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return root->data;

    int left = dfs(root->left);
    int right = dfs(root->right);

    if (root->left && root->right) {
        maxPath = max(maxPath, left + right + root->data);
        return max(left, right) + root->data;
    }
    return (root->left ? left : right) + root->data;
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

int main()
{
    int test;
    cin >> test;
    while (test--) {
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
        maxPath = INT_MIN;
        dfs(root);
        cout << maxPath << endl;
    }
}