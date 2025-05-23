#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void bubbleSort(int a[], int n)
{
    vector<string> v;
    for (int i = 0; i < n - 1; i++) {
        int check = 1;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                check = 0;
            }
        }

        if (!check) {
            string tmp = "Buoc " + to_string(i + 1) + ": ";
            for (int j = 0; j < n; j++)
                tmp += to_string(a[j]) + " ";
            v.push_back(tmp);
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bubbleSort(a, n);
    }
}