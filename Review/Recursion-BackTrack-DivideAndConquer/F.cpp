#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, total, a[25], used[25], x[25];
bool ok = false;

void Try(int i, int sum, int id)
{
    if (id > k) {
        ok = true;
        return;
    }
    for (int j = i; j <= n; j++) {
        if (!used[j]) {
            used[j] = 1;
            x[j] = id;
            sum += a[j];
            if (sum < total)
                Try(i + 1, sum, id);
            else if (sum == total)
                Try(1, 0, id + 1);
            if (ok)
                return;
            used[j] = 0;
            sum -= a[j];
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        total += a[i];
    }
    if (total % k) {
        cout << -1;
        return 0;
    }
    total /= k;
    Try(1, 0, 1);
    if (ok) {
        for (int i = 1; i <= n; i++)
            cout << x[i] << ' ';
    } else
        cout << -1;
}