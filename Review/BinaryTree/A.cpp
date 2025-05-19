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

bool snt(int n)
{
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return n > 1;
}

int res;
void solve(Node* root, int cnt)
{
    if (!root)
        return;
    int x = snt(root->data);
    cnt += x;
    res = max(res, cnt);
    solve(root->left, cnt);
    solve(root->right, cnt);
    cnt -= x;
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
        res = 0;
        solve(root, 0);
        cout << res << endl;
    }
}