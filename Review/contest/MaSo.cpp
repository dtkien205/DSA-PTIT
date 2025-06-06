// TN01015
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int n;
string tmp1, tmp2;
vector<string> Num, Alpha;

bool vs[10], vs1[10];

void Try(int i)
{
    if (i == n) {
        Alpha.push_back(tmp2);
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!vs[j]) {
            vs[j] = true;
            tmp2 += char('A' + j - 1);
            Try(i + 1);
            tmp2.pop_back();
            vs[j] = false;
        }
    }
}

void Try1(int i, int bd)
{
    if (i == n) {
        Num.push_back(tmp1);
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!vs[j]) {
            vs1[j] = true;
            tmp1 += to_string(j);
            Try1(i + 1, j);
            tmp1.pop_back();
            vs1[j] = false;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    Try(0);
    Try1(0, 0);
    for (int i = 0; i < Alpha.size(); i++) {
        for (int j = 0; j < Num.size(); j++) {
            cout << Alpha[i] << Num[j] << endl;
        }
    }
}