#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int x[20], used[20], n, m;

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            x[i] = j;
            used[j] = 1;
            if (i == n) {
                for (int u = 1; u <= i; u++)
                    cout << x[u] << ' ';
                cout << endl;
            } else if (x[1] == m)
                Try(i + 1);
            used[j] = 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    Try(1);
}