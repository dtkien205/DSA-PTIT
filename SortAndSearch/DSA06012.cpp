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
        for (int& i : a)
            cin >> i;
        sort(a, a + n);
        int i = n - 1;
        while (k--) {
            cout << a[i] << ' ';
            i--;
        }
        cout << endl;
    }
}