#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[20], used[10005] = { 0 }, x[20];

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            x[i] = a[j];
            used[j] = 1;
            if (i == n) {
                for (int u = 1; u <= n; u++)
                    cout << x[u] << ' ';
                cout << endl;
            } else
                Try(i + 1);
            used[j] = 0;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    Try(1);
}