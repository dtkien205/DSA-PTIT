#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a, a + n);
        int l = 0, r = n - 1;
        while (a[l] == b[l])
            l++;
        while (a[r] == b[r])
            r--;
        cout << l + 1 << ' ' << r + 1 << endl;
    }
}