#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

map<int, int, greater<>> parse(string s)
{
    map<int, int, greater<>> res;
    stringstream ss(s);
    string w;
    while (ss >> w) {
        if (w == "+")
            continue;

        int i = w.find("*x^");
        int heSo = stoi(w.substr(0, i));
        int mu = stoi(w.substr(i + 3));
        res[mu] += heSo;
    }
    return res;
}

void add(string s1, string s2)
{
    map<int, int, greater<>> res = parse(s1);
    map<int, int, greater<>> tmp = parse(s2);
    for (auto [x, y] : tmp)
        res[x] += y;

    bool first = true;
    for (auto [x, y] : res) {
        if (!first)
            cout << " + ";
        first = false;
        cout << y << "*x^" << x;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        getline(cin >> ws, s1);
        getline(cin >> ws, s2);
        add(s1, s2);
    }
}