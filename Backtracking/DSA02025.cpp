#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int count(string a, string b)
{
    int repeats = 0;
    for (char c : a) {
        if (b.find(c) != string::npos)
            repeats++;
    }
    return repeats;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int b[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = count(v[i], v[j]);

    int idx[n];
    for (int i = 0; i < n; i++)
        idx[i] = i;
    int ans = INT_MAX;
    do {
        int res = 0;
        for (int i = 0; i < n - 1; i++)
            res += b[idx[i]][idx[i + 1]];
        ans = min(ans, res);

    } while (next_permutation(idx, idx + n));
    cout << ans << endl;
}