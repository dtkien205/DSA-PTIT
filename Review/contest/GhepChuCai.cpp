// TN01018
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

char c;
int n;
vector<char> v, tmp;
bool vs[10];

bool nguyenAm(char ch)
{
    return ch == 'A' || ch == 'E';
}

int check(vector<char> a)
{
    for (int i = 1; i <= a.size() - 2; i++) {
        if (nguyenAm(a[i]) && !nguyenAm(a[i - 1]) && !nguyenAm(a[i + 1]))
            return 0;
    }
    return 1;
}

void Try(int i)
{
    if (tmp.size() == n) {
        if (check(tmp)) {
            for (auto x : tmp)
                cout << x;
            cout << endl;
            return;
        }
    }
    for (int j = 0; j < v.size(); j++) {
        if (!vs[j]) {
            vs[j] = true;
            tmp.push_back(v[j]);
            Try(i + 1);
            vs[j] = false;
            tmp.pop_back();
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    cin >> c;
    n = c - 'A' + 1;
    for (char x = 'A'; x <= c; x++)
        v.push_back(x);
    Try(0);
}