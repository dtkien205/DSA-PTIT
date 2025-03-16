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

set<int> se;
void leafNodeLevel(Node* root, int cnt)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        se.insert(cnt);
    leafNodeLevel(root->left, cnt + 1);
    leafNodeLevel(root->right, cnt + 1);
}

bool fullBinaryTree(Node* root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;
    if (root->left == NULL || root->right == NULL)
        return false;
    return fullBinaryTree(root->left) && fullBinaryTree(root->right);
}

bool perfectBinaryTree(Node* root)
{
    leafNodeLevel(root, 0);
    return (se.size() == 1 && fullBinaryTree(root));
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        Node* root = NULL;
        int n;
        cin >> n;
        se.clear();
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
        cout << (perfectBinaryTree(root) ? "Yes" : "No") << endl;
    }
}