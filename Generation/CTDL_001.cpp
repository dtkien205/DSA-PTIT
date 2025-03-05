#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[1000];

void Try(int i)
{
    if (i > n / 2) {
        for (int j = 1; j <= n; j++)
            cout << a[j] << ' ';
        cout << endl;
        return;
    }
    a[i] = 0;
    a[n - i + 1] = 0;
    Try(i + 1);
    a[i] = 1;
    a[n - i + 1] = 1;
    Try(i + 1);
}

int main()
{
    cin >> n;
    Try(1);
}