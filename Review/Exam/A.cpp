#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void gen(int n)
{
    queue<string> q;
    vector<string> res;
    q.push("6");
    q.push("8");

    while (true) {
        string top = q.front();
        q.pop();

        if (top.size() > n)
            break;

        res.push_back(top);
        q.push(top + "6");
        q.push(top + "8");
    }

    cout << res.size() << endl;
    for (auto x : res)
        cout << x << ' ';
    cout << endl;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        gen(n);
    }
}