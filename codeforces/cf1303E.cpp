#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 4e2+7;

int T;
int vis[N];
string s, t, ss;

inline void del(string &str)
{
    string tmp;
    for (int i = 0; i < (int)str.length(); ++i)
        if (!vis[i]) tmp += str[i];
    str = tmp;
}

inline bool f(string &str, int l, int r)
{
    memset(vis, 0, sizeof vis);
    for (int i = 0; i < (int)str.length() && l <= r; ++i) {
        if (str[i] == t[l]) {
            vis[i] = 1;
            ++l;
        }
    }
    del(str);
    return l > r;
}

int main()
{
    cin >> T;
    while (T--) {
        cin >> s >> t;
        ss = s;
        if (f(ss, 0, t.length()-1)) { cout << "YES" << endl; continue; }
        int flag = 0;
        for (int i = 0; i < (int)t.length()-1; ++i) {
            ss = s;
            if (!f(ss, 0, i)) continue;
#ifdef DEBUG
            cout << i << " " << ss << endl;
#endif
            if (!f(ss, i+1, t.length()-1)) continue;
            flag = 1;
            break;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
