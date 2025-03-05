#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, a[20];

void in()
{
    for (int i = 1; i <= k; i++)
        cout << char(a[i] + 'A' - 1);
    cout << endl;
}

void gen()
{
    for (int i = 1; i <= k; i++)
        a[i] = i;

    while (true) {
        in();
        int i = k;
        while (i >= 1 && a[i] == n - k + i)
            i--;
        if (i == 0)
            return;

        a[i]++;
        for (int j = i + 1; j <= k; j++)
            a[j] = a[j - 1] + 1;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        gen();
    }
}
