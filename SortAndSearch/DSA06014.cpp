#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<bool> p(1e6 + 1, true);

void sieve()
{
    p[0] = p[1] = false;
    for (int i = 2; i <= 1e3; i++) {
        if (p[i]) {
            for (int j = i * i; j <= 1e6; j += i) {
                p[j] = false;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    sieve();
    while (t--) {
        int n;
        cin >> n;
        int ok = 0;
        for (int i = 1; i <= n / 2; i++) {
            if (p[i] && p[n - i]) {
                cout << i << ' ' << n - i << endl;
                ok = 1;
                break;
            }
        }
        if (!ok)
            cout << "-1" << endl;
    }
}