#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n + 1];
        for (int i = 1; i <= k; i++)
            cin >> a[i];
        int i = k;
        while (a[i] == n - k + i)
            i--;
        if (i == 0)
            a[i] = 0;
        else
            a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
        for (int j = 1; j <= k; j++)
            cout << a[j] << ' ';
        cout << endl;
    }
}