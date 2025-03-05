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
        int a[n];
        for (int& i : a)
            cin >> i;
        sort(a, a + n);
        int l = 0, r = n - 1;
        while (l < r) {
            cout << a[r] << ' ' << a[l] << ' ';
            l++;
            r--;
        }
        if(n % 2 != 0) cout << a[r];
        cout << endl;
    }
}