#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, a[100], x[100], cnt = 0;

void Try(int i, int bd)
{
    for (int j = bd; j <= n; j++) {
        if (a[j] > x[i - 1]) {
            x[i] = a[j];
            if (i == k)
                cnt++;
            else
                Try(i + 1, j + 1);
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    x[0] = -1e9;
    Try(1, 1);
    cout << cnt << endl;
}