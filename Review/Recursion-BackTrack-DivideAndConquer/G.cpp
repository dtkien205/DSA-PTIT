#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void Try(int n)
{
    if (!n)
        return;
    Try(n / 2);
    cout << n % 2;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        if (!n)
            cout << 0;
        Try(n);
        cout << endl;
    }
}