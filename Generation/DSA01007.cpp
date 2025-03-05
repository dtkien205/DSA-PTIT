#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char a[n + 1];
        for (int i = 1; i <= n; i++)
            a[i] = 'A';
        int ok = 1;
        while (ok) {
            for (int i = 1; i <= n; i++)
                cout << a[i];
            cout << ' ';
            int i = n;
            while (i >= 1 && a[i] == 'B') {
                a[i] = 'A';
                i--;
            }
            a[i] = 'B';
            if (i == 0)
                ok = 0;
        }
        cout << endl;
    }
}