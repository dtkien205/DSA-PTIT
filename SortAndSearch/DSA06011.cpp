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
        int res = INT_MAX, Min = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (abs(a[i] + a[j]) < Min) {
                    Min = abs(a[i] + a[j]);
                    res = a[i] + a[j];
                }
            }
        }
        cout << res << endl;
    }
}