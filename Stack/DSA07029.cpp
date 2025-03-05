#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        getline(cin >> ws, s);
        stack<int> st1;
        stack<string> st2;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                st1.push(num);
            } else if (s[i] == ']') {
                string tmp = "";
                while (!st2.empty() && st2.top() != "[") {
                    tmp = st2.top() + tmp;
                    st2.pop();
                }
                st2.pop();
                string tmp1 = "";
                int lap = st1.top();
                st1.pop();
                while (lap--)
                    tmp1 += tmp;
                st2.push(tmp1);
            } else {
                st2.push(string(1, s[i]));
                if (s[i] == '[' && (!isdigit(s[i - 1]) || i == 0))
                    st1.push(1);
            }
        }
        string ans = "";
        while (!st2.empty()) {
            ans = st2.top() + ans;
            st2.pop();
        }
        cout << ans << endl;
    }
}