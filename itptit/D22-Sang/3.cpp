#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0)
                q.push(i);

            if (i >= k - 1) {
                while (!q.empty() && q.front() < i - k + 1)
                    q.pop();

                if (q.empty())
                    cout << 0 << ' ';
                else
                    cout << a[q.front()] << ' ';
            }
        }
        cout << endl;
    }
}