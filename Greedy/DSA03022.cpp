#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (auto& i : a)
        cin >> i;
    sort(a, a + n);
    cout << max({ a[0] * a[1], a[n - 1] * a[n - 2], a[0] * a[1] * a[n - 1], a[n - 1] * a[n - 2] * a[n - 3] });
}