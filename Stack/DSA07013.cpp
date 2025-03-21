#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int cal(int a, int b, char x){
    if(x == '+') return a + b;
    else if(x == '-') return a - b;
    else if(x == '*') return a * b;
    return a / b;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        stack<int> st;
        for (int i = 0; i < s.size(); i++){
            if(isdigit(s[i]))
                st.push(s[i] - '0');
            else {
                int o1 = st.top(); st.pop();
                int o2 = st.top(); st.pop();
                st.push(cal(o2, o1, s[i]));
            }
        }
        cout << st.top() << endl;
    }
}