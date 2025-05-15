#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int x)
{
    if (root == nullptr)
        return new Node(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);
    return root;
}

int maxHeight(Node* root)
{
    if (root == NULL)
        return -1;
    return max(maxHeight(root->left), maxHeight(root->right)) + 1;
}

int main()
{
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        Node* root = nullptr;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            root = insert(root, x);
        }
        cout << maxHeight(root) << endl;
    }
}