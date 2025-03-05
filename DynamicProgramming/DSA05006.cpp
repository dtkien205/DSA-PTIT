#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll F[1005];

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(F, 0, sizeof(F));

        for (int i = 1; i <= n; i++) {
            F[i] = a[i];
            for (int j = 1; j < i; j++) {
                if (a[i] > a[j])
                    F[i] = max(F[i], F[j] + a[i]);
            }
        }
        cout << *max_element(F + 1, F + n + 1) << endl;
    }
}