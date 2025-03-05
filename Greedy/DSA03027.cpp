#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0)
            sum += x;
    }
    cout << 1ll * sum * 2 << endl;
}