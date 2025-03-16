#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

struct Node {
    string data;
    Node *left, *right;

    Node(string x)
    {
        data = x;
        left = right = nullptr;
    }
};

int cal(int a, int b, string x)
{
    if (x == "+")
        return a + b;
    else if (x == "-")
        return a - b;
    else if (x == "*")
        return a * b;
    return a / b;
}

int posOrder(Node* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return stoi(root->data);
    int l = posOrder(root->left);
    int r = posOrder(root->right);
    return cal(l, r, root->data);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (auto& i : v)
            cin >> i;

        queue<Node*> q;
        Node* root = new Node(v[0]);
        q.push(root);
        int i = 1;

        while (!q.empty() && i < n) {
            Node* top = q.front();
            q.pop();

            if (i < n) {
                top->left = new Node(v[i]);
                q.push(top->left);
            }
            i++;

            if (i < n) {
                top->right = new Node(v[i]);
                q.push(top->right);
            }
            i++;
        }
        cout << posOrder(root) << endl;
    }
}