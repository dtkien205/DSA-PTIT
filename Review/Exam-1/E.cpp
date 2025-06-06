#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[100005];

void inOrder(int i)
{
    if (i >= n)
        return;
    inOrder(2 * i + 1);
    cout << a[i] << ' ';
    inOrder(2 * i + 2);
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
        inOrder(0);
        cout << endl;
    }
}