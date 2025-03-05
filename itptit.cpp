#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

map<int, int, greater<>> parse(string s)
{
    map<int, int, greater<>> mp;
    stringstream ss(s);
    string tmp;
    while (ss >> tmp) {
        if (tmp == "+")
            continue;

        int pos = tmp.find("*x^");
        int heSo = stoi(tmp.substr(0, pos));
        int mu = stoi(tmp.substr(pos + 3));
        mp[mu] += heSo;
    }
    return mp;
}

void add(string s1, string s2)
{
    map<int, int, greater<>> res = parse(s1);
    map<int, int, greater<>> tmp = parse(s2);
    for (auto x : tmp)
        res[x.first] += x.second;

    bool first = true;
    for (auto x : res) {
        if (first)
            first = false;
        else
            cout << " + ";
        cout << x.second << "*x^" << x.first;
    }
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
        cout << endl;
    }
}