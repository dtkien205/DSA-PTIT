#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, k, x[100];
set<int> st;

void Try(int i, int bd, vector<int> v)
{
    for (int j = bd; j < v.size(); j++) {
        x[i] = v[j];
        if (i == k) {
            for (int u = 1; u <= i; u++)
                cout << x[u] << ' ';
            cout << endl;
        } else
            Try(i + 1, j + 1, v);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }
    vector<int> v(st.begin(), st.end());
    Try(1, 0, v);
}
