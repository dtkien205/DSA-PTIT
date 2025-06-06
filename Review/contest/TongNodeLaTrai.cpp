#include <iostream>
#include <map>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void addNode(int n, Node*& root)
{
    map<int, Node*> nodes;
    for (int i = 0; i < n; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (!nodes[u])
            nodes[u] = new Node(u);
        if (!root)
            root = nodes[u];
        Node* child = new Node(v);
        (c == 'L' ? nodes[u]->left : nodes[u]->right) = child;
        nodes[v] = child;
    }
}

bool isLeaf(Node* node)
{
    return node && !node->left && !node->right;
}

int sumLeftLeaves(Node* root)
{
    if (!root)
        return 0;
    int sum = 0;
    if (root->left) {
        if (isLeaf(root->left))
            sum += root->left->data;
        else
            sum += sumLeftLeaves(root->left);
    }
    sum += sumLeftLeaves(root->right);
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Node* root = NULL;
        addNode(n, root);
        cout << sumLeftLeaves(root) << endl;
    }
}