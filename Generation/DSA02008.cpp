#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, s;
int a[100][100], used[100] = { 0 };
vector<vector<int>> v;
vector<int> tmp;

void Try(int i, int sum)
{
    if (i == n) {
        if (sum == s)
            v.push_back(tmp);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            if (sum + a[i][j] <= s) {
                tmp.push_back(j + 1);
                used[j] = 1;
                Try(i + 1, sum + a[i][j]);
                tmp.pop_back();
                used[j] = 0;
            }
        }
    }
}

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    Try(0, 0);
    cout << v.size() << endl;
    for (auto x : v) {
        for (auto i : x)
            cout << i << ' ';
        cout << endl;
    }
}