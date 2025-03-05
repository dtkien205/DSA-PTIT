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
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int res = 0;
        for (int i = 0; i < n - k + 1; i++)
            cout << *max_element(a + i, a + k + i) << ' ';
        cout << endl;
    }
}