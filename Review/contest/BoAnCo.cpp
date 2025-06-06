#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll D;
    cin >> N >> D;

    vector<pair<ll, ll>> cows(N);
    for (int i = 0; i < N; ++i)
        cin >> cows[i].first >> cows[i].second;
    sort(cows.begin(), cows.end());

    vector<ll> x(N), h(N);
    for (int i = 0; i < N; ++i) {
        x[i] = cows[i].first;
        h[i] = cows[i].second;
    }

    vector<int> leftCount(N, 0), rightCount(N, 0);

    // Trái -> phải
    multiset<ll> S;
    int l = 0;
    for (int i = 0; i < N; ++i) {
        while (x[i] - x[l] > D) {
            S.erase(S.find(h[l]));
            ++l;
        }
        leftCount[i] = S.lower_bound(2 * h[i]) != S.end() ? distance(S.lower_bound(2 * h[i]), S.end()) : 0;
        S.insert(h[i]);
    }

    // Phải -> trái
    S.clear();
    int r = N - 1;
    for (int i = N - 1; i >= 0; --i) {
        while (x[r] - x[i] > D) {
            S.erase(S.find(h[r]));
            --r;
        }
        rightCount[i] = S.lower_bound(2 * h[i]) != S.end() ? distance(S.lower_bound(2 * h[i]), S.end()) : 0;
        S.insert(h[i]);
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int total = leftCount[i] + rightCount[i];
        if (total == 1)
            ++cnt;
    }

    cout << cnt;
    return 0;
}
