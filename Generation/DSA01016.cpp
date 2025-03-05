#include <bits/stdc++.h>
using namespace std;

int n, x[100];

void Try(int i, int bd, int sum)
{
    for (int j = bd; j >= 1; j--) {
        if (sum + j <= n) {
            x[i] = j;
            if (sum + j == n) {
                cout << "(";
                for (int u = 1; u <= i; u++) {
                    cout << x[u];
                    if (u != i)
                        cout << ' ';
                }
                cout << ") ";
            } else {
                Try(i + 1, j, sum + j);
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        Try(1, n, 0);
        cout << endl;
    }
}
