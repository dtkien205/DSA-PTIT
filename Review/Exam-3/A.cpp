#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
string a[12], last;
vector<string> v;
vector<vector<string>> res;
bool vs[12];

void Try(int i)
{
    if (i == n) {
        if (v[n - 1] == last)
            res.push_back(v);
        return;
    }

    for (int j = 1; j <= n; j++) {
        if (!vs[j]) {
            vs[j] = true;
            v.push_back(a[j]);
            Try(i + 1);
            v.pop_back();
            vs[j] = false;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> last;
    Try(0);
    sort(res.begin(), res.end());
    for (auto x : res) {
        for (auto y : x)
            cout << y << ' ';
        cout << endl;
    }
}