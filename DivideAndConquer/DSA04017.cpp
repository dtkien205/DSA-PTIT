#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int search(int a[], int b[], int n, int l, int r)
{
    if (l == r)
        return l;
    int m = (l + r) / 2;
    if (a[m] == b[m])
        return search(a, b, n, m + 1, r);
    else
        return search(a, b, n, l, m);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n - 1];
        for (auto& i : a)
            cin >> i;
        for (auto& i : b)
            cin >> i;
        cout << search(a, b, n, 0, n - 1) + 1 << endl;
    }
}