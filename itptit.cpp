#include <bits/stdc++.h>
using namespace std;
int a[5], f;
void Try(int i, int sum)
{
    if (f)
        return;
    if (i > 4) {
        if (sum == 23)
            f = 1; 
        return;
    }
    Try(i + 1, sum + a[i]);
    Try(i + 1, sum - a[i]);
    Try(i + 1, sum * a[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int& x : a)
            cin >> x;
        sort(a, a + 5);
        f = 0;
        do {
            Try(1, a[0]);
        } while (next_permutation(a, a + 5) && !f);
        cout << (f ? "YES\n" : "NO\n");
    }
    return 0;
}