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
            int n;
            cin >> n;
            priority_queue<int, vector<int>, greater<int>> q;
            for (int i = 1; i <= n; i++) {
                int x;
                cin >> x;
                q.push(x);
            }
            ll res = 0;
            while (q.size() >= 2) {
                int x = q.top();
                q.pop();
                int y = q.top();
                q.pop();
                res += x + y;
                q.push(x + y);
            }
            cout << res << endl;
        }
    }