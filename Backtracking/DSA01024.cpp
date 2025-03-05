#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k;
vector<string> v, x;

void Try(int i, int bd)
{
    if (i == k) {
        for (auto l : x)
            cout << l << ' ';
        cout << endl;
        return;
    }
    for (int j = bd; j < v.size(); j++) {
        x.push_back(v[j]);
        Try(i + 1, j + 1);
        x.pop_back();
    }
}

int main()
{
    cin >> n >> k;
    set<string> st;
    while (n--) {
        string s;
        cin >> s;
        st.insert(s);
    }
    v.assign(st.begin(), st.end());
    Try(0, 0);
}