#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, a[100];

int check(int a[], int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1)
            cnt++;
    }
    return cnt == k;
}

void Try(int i)
{
    if (i > n) {
        if (check(a, n)) {
            for (int j = 1; j <= n; j++)
                cout << a[j];
            cout << endl;
        }
        return;
    }
    a[i] = 0;
    Try(i + 1);
    a[i] = 1;
    Try(i + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        Try(1);
    }
}