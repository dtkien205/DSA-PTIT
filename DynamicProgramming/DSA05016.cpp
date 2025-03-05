#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

ll F[10006];

void init()
{
    F[1] = 1;
    int i1 = 1, i2 = 1, i3 = 1;
    for (int i = 2; i <= 10000; i++) {
        F[i] = min({ F[i1] * 2, F[i2] * 3, F[i3] * 5 });
        if (F[i] == F[i1] * 2)
            i1++;
        if (F[i] == F[i2] * 3)
            i2++;
        if (F[i] == F[i3] * 5)
            i3++;
    }
}

int main()
{
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        cin >> n;
        cout << F[n] << endl;
    }
}