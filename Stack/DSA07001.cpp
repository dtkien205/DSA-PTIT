#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    string s;
    vector<int> v;
    while (cin >> s) {
        // cout << s << endl;
        if (s == "push") {
            int x;
            cin >> x;
            v.push_back(x);
        } else if (s == "pop") {
            if (!v.empty())
                v.pop_back();
        } else {
            if (!v.empty()) {
                for (int x : v)
                    cout << x << ' ';
                cout << endl;
            } else
                cout << "empty\n";
        }
    }
}