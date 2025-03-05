#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, ok;
char a[100];

int check(char a[], int n)
{
    if (a[1] != 'H' || a[n] != 'A')
        return 0;
    for (int i = 1; i < n - 1; i++) {
        if (a[i] == 'H' && a[i + 1] == 'H')
            return 0;
    }
    return 1;
}

void gen()
{
    for (int i = 1; i <= n; i++)
        a[i] = 'A';
    while (ok) {
        if (check(a, n)) {
            for (int i = 1; i <= n; i++)
                cout << a[i];
            cout << endl;
        }
        int i = n;
        while (i >= 1 && a[i] == 'H') {
            a[i] = 'A';
            i--;
        }
        a[i] = 'H';
        if (i == 0)
            ok = 0;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ok = 1;
        gen();
    }
}