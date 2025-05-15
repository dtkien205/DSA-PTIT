#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
vector<string> v;
bool check(string s)
{
    stack<char> st;
    for (char c : s) {
        if (c == '(')
            st.push(c);
        else if (!st.empty())
            st.pop();
        else
            return false;
    }
    return st.empty();
}

void Try(int i, string s)
{
    if (i == 2 * n) {
        if (check(s))
            v.push_back(s);
        return;
    }
    Try(i + 1, s + "(");
    Try(i + 1, s + ")");
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    // Try(0, "");

    queue<string> q;
    q.push("(");
    while (!q.empty()) {
        string s = q.front();
        q.pop();

        if (s.size() == 2 * n && check(s))
            v.push_back(s);
        if (s.size() < 2 * n) {
            q.push(s + "(");
            q.push(s + ")");
        }
    }

    cout << v.size() << endl;
    for (auto x : v)
        cout << x << endl;
}