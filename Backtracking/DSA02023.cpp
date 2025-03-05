#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k;
vector<string> v, tmp;
set<string> st;
vector<vector<string>> ans;

void Try(int i, int bd)
{
    if (i == k) {
        ans.push_back(tmp);
        return;
    }

    for (int j = bd; j < v.size(); j++) {
        tmp.push_back(v[j]);
        Try(i + 1, j + 1);
        tmp.pop_back();
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        st.insert(x);
    }
    v.assign(st.begin(), st.end());
    Try(0, 0);
    for (auto x : ans) {
        for (auto i : x)
            cout << i << ' ';
        cout << endl;
    }
}