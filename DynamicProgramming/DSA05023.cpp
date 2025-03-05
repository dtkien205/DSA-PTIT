#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        int n = s.size();
        ll sum = 0, F[n + 1];
        memset(F, 0, sizeof(F));
        s = "0" + s;

        for (int i = 1; i <= n; i++) {
            F[i] = F[i - 1] * 10 + (s[i] - '0') * i;
            sum += F[i];
        }
        cout << sum << endl;
    }
}