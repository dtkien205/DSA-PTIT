#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[10005];

void inorder(int i)
{
    if (i >= n)
        return;
    inorder(2 * i + 1);
    cout << a[i] << ' ';
    inorder(2 * i + 2);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        inorder(0);
        cout << endl;
    }
}