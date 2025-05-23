#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main()
{
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        ll a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        ll cur = 0, maxSum = 0;
        for (int i = 1; i <= n; i++) {
            cur = max(a[i], cur + a[i]);
            maxSum = max(maxSum, cur);
        }
        cout << maxSum << endl;
    }
}