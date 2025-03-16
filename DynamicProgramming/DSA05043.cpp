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
        cin >> s;
        int n = s.size();
        bool F[n + 1][n + 1];
        memset(F, false, sizeof(F));
        s = " " + s;

        for (int i = 1; i <= n; i++)
            F[i][i] = true;
        int res = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 1; i <= n - len + 1; i++) { // chi so bat dau
                int j = i + len - 1; // chi so ket thuc
                if (len == 2)
                    F[i][j] = (s[i] == s[j]);
                else
                    F[i][j] = (s[i] == s[j] && F[i + 1][j - 1]);
                if (F[i][j])
                    res = max(res, len);
            }
        }
        cout << res << endl;
    }
}