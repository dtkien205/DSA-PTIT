#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int F[105][105][105];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        memset(F, 0, sizeof(F));
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;

        for (int i = 1; i <= a; i++) {
            for (int j = 1; j <= b; j++) {
                for (int k = 1; k <= c; k++) {
                    if (s1[i] == s2[j] && s2[j] == s3[k])
                        F[i][j][k] = F[i - 1][j - 1][k - 1] + 1;
                    else
                        F[i][j][k] = max({ F[i - 1][j][k], F[i][j - 1][k], F[i][j][k - 1] });
                }
            }
        }
        cout << F[a][b][c] << endl;
    }
}