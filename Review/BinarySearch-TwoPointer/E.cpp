#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    ll n, s;
    cin >> n >> s;
    ll a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    ll sum = 0, res = 0;
    deque<ll> dq;
    for (int i = 1; i <= n; i++) {
        if (sum <= s) {
            sum += a[i];
            dq.push_back(a[i]);
        }
        while (sum > s && !dq.empty()) {
            sum -= dq.front();
            dq.pop_front();
        }
        res = fmax(res, dq.size());
    }
    cout << res;
}
