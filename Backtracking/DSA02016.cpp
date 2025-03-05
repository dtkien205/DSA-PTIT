#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, c[100], c1[100], c2[100], ans;

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (!c[j] && !c1[i + j - 1] && !c2[i - j + n]) {
            c[j] = c1[i + j - 1] = c2[i - j + n] = 1;
            if (i == n)
                ans++;
            else
                Try(i + 1);
            c[j] = c1[i + j - 1] = c2[i - j + n] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans = 0;
        Try(1);
        cout << ans << endl;
    }
}