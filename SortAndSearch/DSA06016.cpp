#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int& i : a)
            cin >> i;
        for (int& i : b)
            cin >> i;
        cout << 1ll * *max_element(a, a + n) * *min_element(b, b + n) << endl;
    }
}