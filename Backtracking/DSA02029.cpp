#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void Try(int n, char a, char b, char c)
{
    if (n == 0)
        return;
    Try(n - 1, a, c, b);
    cout << a << " -> " << c << endl;
    Try(n - 1, b, a, c);
}

int main()
{
    int n;
    cin >> n;
    Try(n, 'A', 'B', 'C');
}