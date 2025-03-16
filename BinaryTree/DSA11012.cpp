#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct node {
    int data;
    node *l, *r;
    node(int x)
    {
        data = x;
        l = r = nullptr;
    }
};

void makeRoot(node* root, int par, int child, char dir)
{
    if (dir == 'L')
        root->l = new node(child);
    if (dir == 'R')
        root->r = new node(child);
}

void insertNode(node* root, int par, int child, char dir)
{
    if (!root)
        return;
    if (root->data == par)
        makeRoot(root, par, child, dir);
    else {
        insertNode(root->l, par, child, dir);
        insertNode(root->r, par, child, dir);
    }
}

int compare(node* root1, node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return 1;
    if (root1 == NULL || root2 == NULL)
        return 0;
    return root1->data == root2->data && compare(root1->l, root2->l) && compare(root2->r, root1->r);
}

void input(node*& root)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int par, child;
        char dir;
        cin >> par >> child >> dir;
        if (root == NULL) {
            root = new node(par);
            makeRoot(root, par, child, dir);
        } else
            insertNode(root, par, child, dir);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        node *root1 = nullptr, *root2 = nullptr;
        input(root1);
        input(root2);
        cout << compare(root1, root2) << endl;
    }
}