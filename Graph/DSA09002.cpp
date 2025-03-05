#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

vector<pair<int, int>> canh;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        getline(cin >> ws, s);
        stringstream ss(s);
        string tmp;
        while (ss >> tmp) {
            if (i < stoi(tmp))
                canh.push_back({ i, stoi(tmp) });
        }
    }
    for (auto x : canh)
        cout << x.first << ' ' << x.second << endl;
}