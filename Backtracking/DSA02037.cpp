#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int snt(int n)
{
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return n > 1;
}

int n, a[100];
vector<vector<int>> v;
vector<int> tmp;

void Try(int i, int bd, int sum)
{
    for (int j = bd; j <= n; j++) {
        tmp.push_back(a[j]);
        if (snt(sum + a[j]))
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
        v.clear();
        tmp.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        Try(1, 1, 0);
        sort(v.begin(), v.end());
        for (auto x : v) {
            for (auto i : x)
                cout << i << ' ';
            cout << endl;
        }
    }
}