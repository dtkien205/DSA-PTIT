#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, p;
        cin >> n >> m >> p;
        vector<ll> a(n), b(m), c(p), res;
        for (auto& i : a)
            cin >> i;
        for (auto& i : b)
            cin >> i;
        for (auto& i : c)
            cin >> i;
        int i = 0, j = 0, k = 0;
        while (i < n && j < m && k < p) {
            if (a[i] == b[j] && b[j] == c[k]) {
                res.push_back(a[i]);
                i++;
                j++;
                k++;
            } else if (a[i] < b[j])
                i++;
            else if (b[j] < c[k])
                j++;
            else
                k++;
        }
        if (res.empty())
            cout << "-1\n";
        else {
            for (auto x : res)
                cout << x << ' ';
            cout << endl;
        }
    }
}