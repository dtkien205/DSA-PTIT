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
        int a[n];
        int s = 0;
        vector<int> res;
        priority_queue<int, vector<int>, greater<>> mod1, mod2;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
            if (a[i] % 3 == 1)
                mod1.push(a[i]);
            else if (a[i] % 3 == 2)
                mod2.push(a[i]);
            else
                res.push_back(a[i]);
        }
        bool check = true;
        if (s % 3 == 1) {
            if (!mod1.empty())
                mod1.pop();
            else if (mod2.size() >= 2) {
                mod2.pop();
                mod2.pop();
            } else
                check = false;
        } else if (s % 3 == 2) {
            if (!mod2.empty())
                mod2.pop();
            else if (mod1.size() >= 2) {
                mod1.pop();
                mod1.pop();
            } else
                check = false;
        }
        while (!mod1.empty()) {
            res.push_back(mod1.top());
            mod1.pop();
        }
        while (!mod2.empty()) {
            res.push_back(mod2.top());
            mod2.pop();
        }
        sort(res.rbegin(), res.rend());
        if (!check || res.empty() || (!res[0]))
            cout << -1 << endl;
        else {
            for (auto x : res)
                cout << x;
            cout << endl;
        }
    }
}