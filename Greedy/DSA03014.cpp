#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'


bool check(string b, string a) {
    int p = 0;
    for (char c : a) {
        if (p < b.size() && b[p] == c) p++;
    }
    return p == b.size();
}


int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        ll y = cbrt(x), z;
        bool found = false;
        for (int i = y; i >= 1; i--) {
            z = 1ll * i * i * i;
            string sx = to_string(x), sz = to_string(z);
            if (check(sz, sx)) {
                cout << z << endl;
                found = true;
                break;
            }
        }
        if (!found)
            cout << "-1" << endl;
    }
}