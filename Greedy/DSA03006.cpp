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
        int ok = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i] && b[i] != a[n - i - 1])
                ok = 1;
        }
        if (ok)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}