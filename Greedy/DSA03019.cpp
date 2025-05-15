#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll t, m;
        cin >> t >> m;
        while (1) {
            if (m % t == 0) {
                cout << 1 << '/' << m / t << endl;
                break;
            }
            ll res = m / t + 1;
            cout << 1 << '/' << res << " + ";
            t = t * res - m;
            m = m * res;
        }
    }
}