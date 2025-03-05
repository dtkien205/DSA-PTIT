#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    queue<int> q;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s == "PUSH") {
            int x;
            cin >> x;
            q.push(x);
        } else if (s == "PRINTFRONT") {
            if (!q.empty())
                cout << q.front() << endl;
            else
                cout << "NONE\n";
        } else {
            if (!q.empty())
                q.pop();
        }
    }
}