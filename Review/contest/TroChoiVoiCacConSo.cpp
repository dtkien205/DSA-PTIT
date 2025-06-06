// TN01019
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<int> v;
bool vs[20];

bool check(vector<int> a)
{
    for (int i = 0; i < a.size() - 1; i++) {
        if (abs(a[i] - a[i + 1]) == 1)
            return false;
    }
    return true;
}

void Try(int i)
{
    if (v.size() == n) {
        if (check(v)) {
            for (auto x : v)
                cout << x;
            cout << endl;
            return;
        }
    }
    for (int j = 1; j <= n; j++) {
        if (!vs[j]) {
            vs[j] = true;
            v.push_back(j);
            Try(i + 1);
            vs[j] = false;
            v.pop_back();
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        memset(vs, false, sizeof(vs));
        v.clear();
        cin >> n;
        Try(0);
    }
}