#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void Try(int a[], int n)
{
    int tmp[n];
    if (n < 1)
        return;
    for (int i = 0; i < n - 1; i++)
        tmp[i] = a[i] + a[i + 1];
    Try(tmp, n - 1);
    cout << "[" << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    cout << "] ";
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int& i : a)
            cin >> i;
        Try(a, n);
        cout << "\n";
    }
}