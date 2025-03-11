#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int a[5];
char ope[] = { '+', '-', '*' };
vector<vector<char>> signs;
vector<char> tmp;

int cal(int a, int b, char tmp)
{
    if (tmp == '+')
        return a + b;
    else if (tmp == '-')
        return a - b;
    return a * b;
}

bool check(vector<char> v)
{
    return cal(cal(cal(cal(a[0], a[1], v[0]), a[2], v[1]), a[3], v[2]), a[4], v[3]) == 23;
}

void gen(int i)
{
    if (tmp.size() == 4) {
        signs.push_back(tmp);
        return;
    }
    for (int j = 0; j < 3; j++) {
        tmp.push_back(ope[j]);
        gen(i + 1);
        tmp.pop_back();
    }
}

bool permute()
{
    sort(a, a + 5);
    do {
        for (auto sign : signs) {
            if (check(sign))
                return true;
        }
    } while (next_permutation(a, a + 5));
    return false;
}

int main()
{
    int t;
    cin >> t;
    gen(0);
    while (t--) {
        for (int i = 0; i < 5; i++)
            cin >> a[i];
        cout << (permute() ? "YES" : "NO") << endl;
    }
}