#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int search(int a[], int n, int x)
{
    int ans = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (a[m] == x)
            return 1;
        else if (a[m] > x)
            r = m - 1;
        else
            l = m + 1;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        if (search(a, n, x))
            cout << 1 << endl;
        else
            cout << "-1" << endl;
    }
}