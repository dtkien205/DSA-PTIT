#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    int b[m + 1];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    vector<int> v;
    string s = "";

    int i = 1, j = 1;
    while (i <= n && j <= m) {
        if (a[i] <= b[j]) {
            v.push_back(a[i]);
            s += "a";
            i++;
        } else {
            v.push_back(b[j]);
            s += "b";
            j++;
        }
    }
    while (i <= n) {
        v.push_back(a[i]);
        s += "a";
        i++;
    }
    while (j <= m) {
        v.push_back(b[j]);
        s += "b";
        j++;
    }
    for (auto x : v)
        cout << x << ' ';
    cout << endl;
    cout << s << endl;
}