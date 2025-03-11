#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, total, res;
int a[20];

void Try(int i, int cnt, int sum)
{
    if (cnt == k) {
        if (i == n)
            res++;
        return;
    }
    for (int j = i; j < n; j++) {
        sum += a[j];
        if (sum == total)
            Try(j + 1, cnt + 1, 0);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
    }
    if (total % k)
        cout << 0;
    else {
        total /= k;
        Try(0, 0, 0);
        cout << res;
    }
}