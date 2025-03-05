#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[20], x[20];
vector<vector<int>> v;
vector<int> tmp;

void Try(int i, int bd, int sum)
{
    for (int j = bd; j <= n; j++) {
        tmp.push_back(a[j]);
        if ((sum + a[j]) % 2)
            v.push_back(tmp);
        Try(i + 1, j + 1, sum + a[j]);
        tmp.pop_back();
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        v.clear();
        Try(1, 1, 0);
        sort(v.begin(), v.end());
        for (auto x : v) {
            for (auto i : x)
                cout << i << ' ';
            cout << endl;
        }
    }
}