#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, x[10], used[10];

void Try(int i)
{
    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            used[j] = 1;
            x[i] = j;
            if (i == n) {
                if (x[1] > x[n]) {
                    for (int u = 1; u <= i; u++)
                        cout << x[u] << ' ';
                    cout << endl;
                }
            } else
                Try(i + 1);
            used[j] = 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    Try(1);
}