#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, s, cnt, x[100];

void Try(int i, int bd, int sum)
{
    for (int j = bd; j <= n; j++) {
        if (i == k) {
            if (sum + j == s)
                cnt++;
        } else
            Try(i + 1, j + 1, sum + j);
    }
}

int main()
{
    while (1) {
        cnt = 0;
        cin >> n >> k >> s;
        if (!n && !k && !s)
            return 0;
        Try(1, 1, 0);
        cout << cnt << endl;
    }
}