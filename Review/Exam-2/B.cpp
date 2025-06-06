#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

const int n = 1e6 + 5;

ll p[n], F[n];

void init()
{
    for (int i = 2; i <= 1e6; i++) {
        if (!p[i]) {
            for (int j = i; j <= 1e6; j += i)
                p[j] = i;
        }
    }

    for (int i = 2; i <= 1e6; i++) {
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