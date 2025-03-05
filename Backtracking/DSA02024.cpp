#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, a[50], x[50];
string tmp;
vector<string> ans;

void Try(int i, int bd)
{
    for (int j = bd; j <= n; j++) {
        if (a[j] > x[i - 1]) {
            x[i] = a[j];
            if (i >= 2) {
                tmp = "";
                for (int u = 1; u <= i; u++)
                    tmp += to_string(x[u]) + " ";
                ans.push_back(tmp);
            }
            Try(i + 1, j + 1);
        }
    }
}

int main()
{
    cin >> n;
    x[0] = INT_MIN;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Try(1, 1);
    sort(ans.begin(), ans.end());
    for (auto x : ans)
        cout << x << endl;
}