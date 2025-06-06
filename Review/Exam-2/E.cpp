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
    Node* root = new Node(v[0]);
    int i = 1, n = v.size();
    queue<Node*> q;
    q.push(root);

    while (!q.empty() && i < n) {
        auto tmp = q.front();
        q.pop();

        if (i < n && v[i] != "N") {
            tmp->left = new Node(v[i]);
            q.push(tmp->left);
        }
        i++;

        if (i < n && v[i] != "N") {
            tmp->right = new Node(v[i]);
            q.push(tmp->right);
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
        vector<string> v;
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        string w;
        while (ss >> w)
            v.push_back(w);

        Node* root = build(v);
        duyet(root);
        cout << endl;
    }
}