#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int F[n + 1];
    fill(F, F + n + 1, 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j])
                F[i] = max(F[i], F[j] + 1);
        }
    }
    cout << *max_element(F + 1, F + n + 1);
}