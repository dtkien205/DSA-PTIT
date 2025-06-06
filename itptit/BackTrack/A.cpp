#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll F[100];
int n;
vector<string> v;
set<ll> se;

void init()
{
    F[1] = 1, F[2] = 2;
    se.insert(1);
    se.insert(2);
    for (int i = 3; i <= 93; i++) {
        F[i] = F[i - 1] + F[i - 2];
        se.insert(F[i]);
    }
}

void Try(int i, string s)
{
    if (s.size() == n) {
        v.push_back(s);
        return;
    }
    Try(i + 1, s + "0");
    Try(i + 1, s + "1");
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    init();
    Try(1, "");
    for (int i = 0; i < v.size(); i++) {
        if (se.count(i + 1)) {
            cout << i + 1 << ": ";
            for (auto x : v[i])
                cout << x << ' ';
            cout << endl;
        }
    }
}