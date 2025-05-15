#include <iostream>
using namespace std;

int findIndex(int* arr, int size, int x)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

void traverse(int* inorder, int size, int* preorder)
{
    int i = findIndex(inorder, size, preorder[0]);
    if (i != 0)
        traverse(inorder, i, preorder + 1);
    if (i != size - 1)
        traverse(inorder + i + 1, size - i - 1, preorder + i + 1);
    cout << preorder[0] << " ";
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int inorder[1000], preorder[1000], n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        traverse(inorder, n, preorder);
        cout << endl;
    }
}
