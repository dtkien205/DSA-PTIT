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
void checkLeafNodeLevel(Node* root, int cnt)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        se.insert(cnt);
    checkLeafNodeLevel(root->left, cnt + 1);
    checkLeafNodeLevel(root->right, cnt + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        se.clear();
        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (root == NULL) {
                root = new Node(x);
                makeRoot(root, x, y, z);
            } else
                insertNode(root, x, y, z);
        }
        checkLeafNodeLevel(root, 0);
        cout << (se.size() == 1 ? 1 : 0) << endl;
    }
}