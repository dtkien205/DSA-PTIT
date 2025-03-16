#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n, m, inDeg[1005], outDeg[1005];

void reset()
{
    memset(inDeg, 0, sizeof(inDeg));
    memset(outDeg, 0, sizeof(outDeg));
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        reset();
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            outDeg[x]++;
            inDeg[y]++;
        }
        int ok = 1;
        for (int i = 1; i <= n; i++) {
            if (inDeg[i] != outDeg[i]) {
                ok = 0;
                break;
            }
        }
        cout << ok << endl;
    }
}