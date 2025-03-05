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
            a[i] = i;
        int ok = 1;
        while (ok) {
            for (int i = 1; i <= k; i++)
                cout << a[i];
            cout << ' ';

            int i = k;
            while (a[i] == n - k + i && i >= 1)
                i--;
            if (i == 0)
                ok = 0;
            a[i]++;
            for (int j = i + 1; j <= k; j++)
                a[j] = a[j - 1] + 1;
        }
        cout << endl;
    }
}