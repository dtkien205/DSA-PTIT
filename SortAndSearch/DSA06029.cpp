#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void insertionSort(int a[], int n)
{
    vector<string> v;
    for (int i = 0; i < n; i++) {
        int pos = i;
        while (pos > 0 && a[pos] < a[pos - 1]) {
            swap(a[pos], a[pos - 1]);
            pos--;
        }

        string tmp = "Buoc " + to_string(i) + ": ";
        for (int j = 0; j <= i; j++)
            tmp += to_string(a[j]) + " ";
        v.push_back(tmp);
    }
    for (int i = v.size() - 1; i >= 0; i--)
        cout << v[i] << endl;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertionSort(a, n);
}