#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char c;
int k, n;
char a[100], x[100];

void Try(int i, int bd)
{
    if (i == k) {
        for (int u = 0; u < k; u++) 
            cout << x[u];
        cout << endl;
        return;
    }
    for (int j = bd; j < n; j++) { 
        x[i] = a[j];
        Try(i + 1, j);
    }
}

int main()
{
    cin >> c >> k;
    n = c - 'A' + 1;
    for (int i = 0; i < n; i++)
        a[i] = 'A' + i;
    Try(0, 0);
}
