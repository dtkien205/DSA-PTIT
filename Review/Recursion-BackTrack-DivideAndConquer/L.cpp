#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

double a, b, c;
double cal(double x)
{
    return a * pow(x, 3) + b * x - c;
}

void search()
{
    double l = 0, r = 100.0, res = 0;
    while (r - l >= 1e-9) {
        double m = (l + r) / 2;
        if (cal(m) <= 1e-9) {
            res = m;
            l = m;
        } else
            r = m;
    }
    cout << fixed << setprecision(4) << res << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int test;
    cin >> test;
    while (test--) {
        cin >> a >> b >> c;
        search();
    }
}