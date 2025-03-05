#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int check(vector<ll> v, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (binary_search(v.begin() + j + 1, v.end(), v[i] + v[j]))
                return true;
        }
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            v[i] *= v[i];
        }
        sort(v.begin(), v.end());
        if (check(v, n))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}