#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt[100005] = {0};
        int a[n];
        set<int> st;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            st.insert(a[i]);
        }
        int ans = 0;
        for (int i = *st.begin(); i <= *st.rbegin(); i++){
            if(!cnt[i]) ans++;
        }
        cout << ans << endl;
    }
}