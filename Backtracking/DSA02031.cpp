#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, used[10] = {};
int x[100];

int check(int x[], int n)
{
    for (int i = 0; i < n; i++) {
        if (x[i] == 0 || x[i] == 4) {
            if (x[i - 1] != 0 && x[i + 1] != 0 && x[i - 1] != 4 && x[i + 1] != 4)
                return 0;
        }
    }
    return 1;
}

void Try(int i)
{
    if (i == n) {
        if (check(x, n)) {
            for (int u = 0; u < i; u++)
                cout << char(x[u] + 'A');
            cout << endl;
        }
    }
    for (int j = 0; j < n; j++) {
        if (!used[j]) {
            x[i] = j;
            used[j] = 1;
            Try(i + 1);
            used[j] = 0;
        }
    }
}

int main()
{
    char c;
    cin >> c;
    n = c - 'A' + 1;
    Try(0);
}