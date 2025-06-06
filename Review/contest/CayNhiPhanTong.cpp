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

int isSumTree(Node* root)
{
    if (!root)
        return 0;

    int left_val = (root->left) ? root->left->data : 0;
    int right_val = (root->right) ? root->right->data : 0;

    if (root->data == left_val + right_val)
        return 1;

    return isSumTree(root->left) && isSumTree(root->right);
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
        cout << isSumTree(root) << endl;
    }
}