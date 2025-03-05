#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

string minNumber(int n, int s)
{
    if (n * 9 < s || (s == 0 && n > 1))
        return "-1";
    string res = string(n, '0');
    for (int i = n - 1; i >= 0; i--) {
        if (s > 9) {
            res[i] = '9';
            s -= 9;
        } else {
            if (i != 0) {
                res[0] = '1';
                res[i] += s - 1;
                break;
            } else
                res[i] += s;
        }
    }
    return res;
}

string maxNumber(int n, int s)
{
    if (n * 9 < s || (s == 0 && n > 1))
        return "-1";
    string res = string(n, '0');
    for (int i = 0; i < n; i++) {
        if (s > 9) {
            res[i] = '9';
            s -= 9;
        } else {
            res[i] += s;
            break;
        }
    }
    return res;
}

int main()
{
    int n, s;
    cin >> n >> s;
    cout << minNumber(n, s) << ' ' << maxNumber(n, s);
}