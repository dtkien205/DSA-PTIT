#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll toDecimal(string a)
{
    ll res = 0;
    for (int i = 0; i < a.size(); i++)
        res = res * 2 + (a[i] - '0');
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        cout << 1ll * toDecimal(a) * toDecimal(b) << endl;
    }
}