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

void levelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* top = q.front();
        q.pop();
        cout << top->data << ' ';
        if (top->left != NULL)
            q.push(top->left);
        if (top->right != NULL)
            q.push(top->right);
    }
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
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (root == NULL) {
                root = new Node(x);
                makeRoot(root, x, y, z);
            } else
                insertNode(root, x, y, z);
        }
        levelOrder(root);
        cout << endl;
    }
}