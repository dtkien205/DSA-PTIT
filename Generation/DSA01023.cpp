#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, res, a[20], tmp[20];
bool ok;

void check()
{
    res++;
    for (int i = 1; i <= k; i++) {
        if (a[i] != tmp[i])
            return;
    }
    ok = true;
}

void gen()
{
    for (int i = 1; i <= k; i++)
        a[i] = i;
    while (1) {
        check();
        if (ok)
            return;
        int i = k;
        while (i >= 1 && a[i] == n - k + i)
            i--;
        if (i == 0)
            return;
        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        res = 0, ok = false;
        for (int i = 1; i <= k; i++)
            cin >> tmp[i];
        gen();
        cout << res << endl;
    }
}