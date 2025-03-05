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
        vector<int> a(n);
        for (int& i : a)
            cin >> i;
        sort(a.begin(), a.end());

        int l = 0, r = n / 2, cnt = 0;
        while (r < n) {
            if (a[r] >= 2 * a[l]) {
                cnt++;
                l++;
            }
            r++;
        }
        cout << n - cnt << endl;
    }
}