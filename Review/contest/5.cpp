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
        left = right = NULL;
    }
};

Node* build(vector<string> v)
{
    int i = 1, n = v.size();
    Node* root = new Node(v[0]);
    queue<Node*> q;
    q.push(root);

    while (!q.empty() && i < n) {
        auto top = q.front();
        q.pop();

        if (i < n && v[i] != "N") {
            top->left = new Node(v[i]);
            q.push(top->left);
        }
        i++;

        if (i < n && v[i] != "N") {
            top->right = new Node(v[i]);
            q.push(top->right);
        }
        i++;
    }

    return root;
}

void duyet(Node* root)
{
    if (!root)
        return;
    duyet(root->right);
    cout << root->data << ' ';
    duyet(root->left);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        string s, w;
        getline(cin >> ws, s);
        stringstream ss(s);
        vector<string> v;
        while (ss >> w)
            v.push_back(w);

        Node* root = NULL;
        root = build(v);
        duyet(root);
        cout << endl;
    }
}