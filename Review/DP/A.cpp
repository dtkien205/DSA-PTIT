#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

unsigned long long F[100];
void init()
{
    F[0] = F[1] = 1;
    for (int i = 2; i <= 93; i++)
        F[i] = F[i - 1] + F[i - 2];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    init();
    while (test--) {
        int n;
        cin >> n;
        cout << F[n] << endl;
    }
}