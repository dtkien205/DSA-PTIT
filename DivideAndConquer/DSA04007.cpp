#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        int k;
        cin >> k >> a >> b;
        while (a.size() < b.size())
            a = "0" + a;
        while (b.size() < a.size())
            b = "0" + b;
        string res = "";
        int remember = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            int tmp = (a[i] - '0') + (b[i] - '0') + remember;
            res += (tmp % k + '0');
            remember = tmp / k;
        }
        if (remember > 0)
            res += (remember + '0');
        reverse(res.begin(), res.end());
        cout << res << endl;
    }
}