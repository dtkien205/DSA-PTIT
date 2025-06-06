#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<ll> v;

void gen()
{
    queue<pair<ll, ll>> q;
    for (int i = 1; i <= 9; i++)
        q.push({ i, i });

    while (!q.empty()) {
        auto [x, sum] = q.front();
        q.pop();

        if (sum == 10) {
            v.push_back(x);
            if (v.size() == 2e5)
                return;
        }

        for (int i = 0; i <= 9; i++) {
            if (sum + i <= 10)
                q.push({ x * 10 + i, sum + i });
            else
                break;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    gen();
    int test;
    cin >> test;
    while (test--) {

        int n;
        cin >> n;
        cout << v[n - 1] << endl;
    }
}