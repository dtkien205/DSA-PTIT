// A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, a[105];
vector<int> res;
vector<pair<int, vector<int>>> result;

void Try(int i, int bd, int sum)
{
    if (sum >= k)
        return;
    if (sum > 0)
        result.push_back({ sum, res });
    for (int j = bd; j < n; j++) {
        res.push_back(j + 1); 
        Try(i + 1, j + 1, sum + a[j]);
        res.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Try(0, 0, 0);

    if (result.empty()) {
        cout << -1 << endl;
        return 0;
    }

    sort(result.begin(), result.end(), [](auto& a, auto& b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second;
    });

    for (auto& [sum, v] : result) {
        for (int x : v)
            cout << x << ' ';
        cout << endl;
        cout << "Sum = " << sum << endl;
    }
}
