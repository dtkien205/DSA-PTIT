#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<vector<int>> v;
vector<int> tmp;

void Try(int bd, int sum)
{
    for (int j = bd; j >= 1; j--) {
        tmp.push_back(j);
        if (sum + j == n)
            v.push_back(tmp);
        else if (sum + j <= n)
            Try(j, sum + j);
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
        Try(n, 0);
        // sort(v.begin(), v.end());
        cout << v.size() << endl;
        for (auto x : v) {
            cout << "(";
            for (int i = 0; i < x.size(); i++) {
                cout << x[i];
                if (i != x.size() - 1)
                    cout << ' ';
            }
            cout << ") ";
        }
        cout << endl;
    }
}