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

void makeRoot(Node* root, int child, char dir)
{
    if (dir == 'L')
        root->left = new Node(child);
    else
        root->right = new Node(child);
}

void insert(Node* root, int par, int child, char dir)
{
    if (!root)
        return;
    if (root->data == par)
        makeRoot(root, child, dir);
    insert(root->left, par, child, dir);
    insert(root->right, par, child, dir);
}

void duyet(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        auto top = q.front();
        q.pop();

        cout << top->data << ' ';

        if (top->left)
            q.push(top->left);
        if (top->right)
            q.push(top->right);
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
        Node* root = NULL;
        for (int i = 0; i < n; i++) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!root) {
                root = new Node(x);
                makeRoot(root, y, z);
            } else
                insert(root, x, y, z);
        }
        duyet(root);
        cout << endl;
    }
}