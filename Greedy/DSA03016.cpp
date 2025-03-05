#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string minNumber(int s, int n)
{
    string res = string(n, '0');
    if (n * 9 < s || (s == 0 && n > 1))
        return "-1";
    for (int i = n - 1; i >= 0; i--) {
        if (s > 9) {
            res[i] = '9';
            s -= 9;
        } else {
            if (i != 0) {
                res[0] = '1';
                res[i] = '0' + s - 1;
                break;
            } else
                res[i] += s;
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int s, n;
        cin >> s >> n;
        cout << minNumber(s, n) << endl;
    }
}