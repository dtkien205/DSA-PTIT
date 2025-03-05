#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void gen(int n)
{
    queue<string> q;
    q.push("1");
    while (n--) {
        string s = q.front();
        cout << s << ' ';
        q.pop();
        q.push(s + "0");
        q.push(s + "1");
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        gen(n);
        cout << endl;
    }
}