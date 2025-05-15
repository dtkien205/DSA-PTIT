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

int findIndex(vector<int> in, int x, int l, int r)
{
    for (int i = l; i <= r; i++) {
        if (in[i] == x)
            return i;
    }
    return -1;
}

Node* buildTree(vector<int> in, vector<int> level, int l, int r)
{
    if (r < l)
        return NULL;

    int rootVal = -1, rootIndex = -1;
    for (int x : level) {
        int index = findIndex(in, x, l, r);
        if (index != -1) {
            rootVal = x;
            rootIndex = index;
            break;
        }
    }

    Node* root = new Node(rootVal);

    set<int> leftIn(in.begin() + l, in.begin() + rootIndex);
    vector<int> leftLevel, rightLevel;

    for (int i = 1; i < level.size(); i++) {
        if (leftIn.count(level[i]))
            leftLevel.push_back(level[i]);
        else
            rightLevel.push_back(level[i]);
    }

    root->left = buildTree(in, leftLevel, l, rootIndex - 1);
    root->right = buildTree(in, rightLevel, rootIndex + 1, r);

    return root;
}

void postOrder(Node* root)
{
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << ' ';
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
        vector<int> in(n), level(n);
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> level[i];

        Node* root = buildTree(in, level, 0, n - 1);

        postOrder(root);
        cout << endl;
    }
}