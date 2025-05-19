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

void insertNode(Node* root, int par, int child, char dir)
{
    if (!root)
        return;
    if (par == root->data)
        makeRoot(root, child, dir);
    else {
        insertNode(root->left, par, child, dir);
        insertNode(root->right, par, child, dir);
    }
}

void levelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* top = q.front();
        q.pop();
        cout << top->data << ' ';
        if (top->left)
            q.push(top->left);
        if (top->right)
            q.push(top->right);
    }
}

void spiralOrder(Node* root)
{
    stack<Node*> st1, st2;
    st1.push(root);

    while (!st1.empty() || !st2.empty()) {
        while (!st1.empty()) {
            Node* top = st1.top();
            st1.pop();
            cout << top->data << ' ';
            if (top->right)
                st2.push(top->right);
            if (top->left)
                st2.push(top->left);
        }
        while (!st2.empty()) {
            Node* top = st2.top();
            st2.pop();
            cout << top->data << ' ';
            if (top->left)
                st1.push(top->left);
            if (top->right)
                st1.push(top->right);
        }
    }
}

set<int> se;
void checkLeaves(Node* root, int cnt)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        se.insert(cnt);
    checkLeaves(root->left, cnt + 1);
    checkLeaves(root->right, cnt + 1);
}

bool isLeaf(Node* root)
{
    return root && !root->left && !root->right;
}

bool fullBinaryTree(Node* root)
{
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;
    if (!root->left || !root->right)
        return false;
    return fullBinaryTree(root->left) && fullBinaryTree(root->right);
}

bool perfectBinaryTree(Node* root)
{
    checkLeaves(root, 0);
    return (se.size() == 1 && fullBinaryTree(root));
}

bool equalBinaryTree(Node* root1, Node* root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    return root1->data == root2->data && equalBinaryTree(root1->left, root2->left) && equalBinaryTree(root1->right, root2->right);
}

int sumRightLeaves(Node* root)
{
    if (!root)
        return 0;
    int sum = 0;
    if (root->right) {
        if (isLeaf(root->right))
            sum += root->right->data;
        else
            sum += sumRightLeaves(root->right);
    }
    sum += sumRightLeaves(root->left);
    return sum;
}

void input(Node*& root)
{
    int n;
    cin >> n;
    se.clear();
    for (int i = 0; i < n; i++) {
        int par, child;
        char dir;
        cin >> par >> child >> dir;
        if (root == NULL) {
            root = new Node(par);
            makeRoot(root, child, dir);
        } else
            insertNode(root, par, child, dir);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        Node *root = NULL, *root2 = NULL;
        input(root);
        cout << sumRightLeaves(root) << endl;
    }
}