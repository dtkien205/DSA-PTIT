#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, s, a[100], x[100];
bool found;

void Try(int i, int bd, int sum)
{
    for (int j = bd; j <= n; j++) {
        if (a[j] >= x[i - 1]) {
            if (sum + a[j] <= s) {
                x[i] = a[j];
                if (sum + a[j] == s) {
                    found = true;
                    cout << "[";
                    for (int u = 1; u <= i; u++) {
                        cout << x[u];
                        if (u != i)
                            cout << ' ';
                    }
                    cout << "]";
                } else
                    Try(i + 1, bd, sum + a[j]);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        found = false;
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        x[0] = 0;
        // sort(a + 1, a + n + 1);
        Try(1, 1, 0);
        if (!found)
            cout << "-1";
        cout << endl;
    }
}