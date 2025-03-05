#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, s, check;
int a[100];

void Try(int bd, int sum, int cnt)
{
    if (check)
        return;
    if (cnt == k) {
        check = 1;
        return;
    }
    for (int j = bd; j < n; j++) {
        if (sum + a[j] <= s) {
            if (sum + a[j] == s)
                Try(0, 0, cnt + 1);
            else
                Try(j + 1, sum + a[j], cnt);
        } else
            return;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        s = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s % k)
            cout << 0 << endl;
        else {
            s /= k;
            check = 0;
            Try(0, 0, 0);
            cout << ((check == 1) ? 1 : 0) << endl;
        }
    }
}