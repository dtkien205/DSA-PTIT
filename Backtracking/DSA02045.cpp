#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
char x[100];
string s;

void Try(int i, int bd)
{
    for (int j = bd; j <= n; j++) {
        x[i] = s[j];
        if (i >= 1) {
            for (int u = 1; u <= i; u++)
                cout << x[u];
            cout << ' ';
        }
        Try(i + 1, j + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        s = "0" + s;
        Try(1, 1);
        cout << endl;
    }
}