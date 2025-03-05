#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, x[100], used[100] = {};

int check(int x[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        if (abs(x[i] - x[i + 1]) == 1)
            return 0;
    }
    return 1;
}

void Try(int i)
{
    if (i == n) {
        if (check(x, n)) {
            for (int u = 0; u < i; u++)
                cout << x[u];
            cout << endl;
        }
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            x[i] = j;
            used[j] = 1;
            Try(i + 1);
            used[j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        Try(0);
    }
}