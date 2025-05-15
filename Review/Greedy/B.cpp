#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    string a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        cout << a[i];
}