#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, s, p;
vector<int> tmp, prime, a;
vector<vector<int>> res;

int snt(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return 0;
    return n > 1;
}

void Try(int idx, int sum)
{
    if (tmp.size() == n && sum == s) {
        res.push_back(tmp);
        return;
    }

    for (int j = idx; j < a.size(); j++) {
        if (sum + a[j] <= s) {
            tmp.push_back(a[j]);
            Try(j + 1, sum + a[j]);
            tmp.pop_back();
        } else
            return;
    }
}

int main()
{
    for (int i = 2; i <= 200; i++) {
        if (snt(i))
            prime.push_back(i);
    }
    int t;
    cin >> t;
    while (t--) {
        res.clear();
        a.clear();
        cin >> n >> p >> s;

        for (auto x : prime) {
            if (x > p)
                a.push_back(x);
        }

        Try(0, 0);

        cout << res.size() << endl;
        for (auto& x : res) {
            for (int i = 0; i < x.size(); i++)
                cout << x[i] << ' ';
            cout << endl;
        }
    }
}
