#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    int test;
    cin >> test;
    while (test--) {
        string s;
        getline(cin >> ws, s);
        int n = s.size();
        s = " " + s;
        ll sum = 0, F[n + 1];
        memset(F, 0, sizeof(F));

        for (int i = 1; i <= n; i++) {
            F[i] = F[i - 1] * 10 + (s[i] - '0') * i;
            sum += F[i];
        }
        cout << sum << endl;
    }
}