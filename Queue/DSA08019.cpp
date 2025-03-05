#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void gen(int n)
{
    vector<string> res;
    queue<string> q;
    q.push("6");
    q.push("8");
    while (true) {
        string tmp = q.front();
        q.pop();
        if (tmp.size() > n)
            break;
        res.push_back(tmp);
        q.push(tmp + "6");
        q.push(tmp + "8");
    }
    cout << res.size() << endl;
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << ' ';
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        gen(n);
    }
}