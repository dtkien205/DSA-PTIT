#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
// #define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

// s = x + y - 1
//  a(x, y) = s * (s - 1) / 2 + y

// s*(s-1)/2 < z <= s*(s+1)/2 -> tim s min >= z (binaryserach)
// y = z - s*(s-1)/2
// x = s + 1 - y

int main()
{
    ll x, y, z;
    cin >> x >> y >> z;
    ll S = x + y - 1;
    cout << S * (S - 1) / 2 + y << endl;

    ll l = 0, r = 1e9, s = 0;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (mid * (mid + 1) / 2 >= z) {
            s = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    y = z - s * (s - 1) / 2;
    x = s + 1 - y;
    cout << x << ' ' << y << endl;
}