#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int n = 1e6 + 5;
ll F[n];
int p[n];

void init()
{
    for (int i = 2; i <= n; i++) {
        if (!p[i]) {
            for (int j = i; j <= n; j += i)
                p[j] = i;
        }
    }

    for (int i = 2; i <= n; i++) {
        F[i] = F[i - 1] + p[i];
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    init();
    while (test--) {
        int l, r;
        cin >> l >> r;
        cout << F[r] - F[l - 1] << endl;
    }
}