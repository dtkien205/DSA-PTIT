#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int F[1005][1005];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = s1.size(), n2 = s2.size();
        memset(F, 0, sizeof(F));
        s1 = " " + s1;
        s2 = " " + s2;
        
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (s1[i] != s2[j])
                    F[i][j] = max(F[i - 1][j], F[i][j - 1]);
                else
                    F[i][j] = F[i - 1][j - 1] + 1;
            }
        }
        cout << F[n1][n2] << endl;
    }
}