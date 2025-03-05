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
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int F[n];
        fill(F, F + n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[i] >= a[j])
                    F[i] = max(F[i], F[j] + 1);
            }
        }
        cout << n - *max_element(F, F + n) << endl;
    }
}