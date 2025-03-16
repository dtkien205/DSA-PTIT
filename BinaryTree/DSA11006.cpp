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

void spiralOrder(Node* root)
{
    stack<Node*> st1, st2;
    st1.push(root);
    while (!st1.empty() || !st2.empty()) {
        while (!st1.empty()) {
            Node* tmp = st1.top();
            cout << tmp->data << ' ';
            st1.pop();
            if (tmp->right != NULL)
                st2.push(tmp->right);
            if (tmp->left != NULL)
                st2.push(tmp->left);
        }
        while (!st2.empty()) {
            Node* tmp = st2.top();
            cout << tmp->data << ' ';
            st2.pop();
            if (tmp->left != NULL)
                st1.push(tmp->left);
            if (tmp->right != NULL)
                st1.push(tmp->right);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        Node *root = NULL;
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
        spiralOrder(root);
        cout << endl;
    }
}