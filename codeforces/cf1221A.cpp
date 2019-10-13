#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int q, n;
int s[N];

inline void Ope(stack<int> &st)
{
    while (st.size() >= 2) {
        int a = st.top();
        st.pop();
        int b = st.top();
        if (a == b && a < 2048) {
            st.pop();
            st.push(a+b);
        } else {
            break;
        }
    }
}

int main()
{
    cin >> q;
    while (q--) {
        cin >> n;
        int flag = 0;
        stack<int> st;
        for (int i = 1; i <= n; ++i) {
            cin >> s[i];
            st.push(s[i]);
            Ope(st);
            if (st.top() == 2048) flag = 1;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
