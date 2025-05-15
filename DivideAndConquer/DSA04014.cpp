#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

const int MAX = 1e6 + 5;
ll a[MAX], temp[MAX];

ll merge_sort_and_count(int l, int r)
{
    if (l >= r)
        return 0;
    int m = (l + r) / 2;
    ll count = 0;

    count += merge_sort_and_count(l, m);
    count += merge_sort_and_count(m + 1, r);
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] > a[j]) {
            temp[k++] = a[j++];
            count += (m - i + 1); // Tất cả phần tử còn lại bên trái > a[j]
        } else {
            temp[k++] = a[i++];
        }
    }

    while (i <= m)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = temp[i];
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << merge_sort_and_count(0, n - 1) << endl;
    }
}
