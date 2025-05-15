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

Node* buildBalanceBST(int a[], int l, int r)
{
    if (l > r)
        return NULL;
    int m = (l + r + 1) / 2;
    Node* root = new Node(a[m]);
    root->left = buildBalanceBST(a, l, m - 1);
    root->right = buildBalanceBST(a, m + 1, r);
    return root;
}

int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        Node* root = buildBalanceBST(a, 0, n - 1);
        cout << countLeaves(root) << endl;
    }
}
