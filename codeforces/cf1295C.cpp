#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int T;
string s, t;
int nex[N][26], last[26];

inline bool check()
{
    static int vis[26];
    memset(vis, 0, sizeof vis);
    for (char c : s) vis[c-'a'] = 1;
    for (char c : t) if (!vis[c-'a']) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> s >> t;
        if (!check()) {
            cout << -1 << endl;
            continue;
        }
        // memset(last, 0, sizeof last);
        for (int i = 0; i <= (int)s.length()+1; ++i) {
            memset(nex[i], 0, sizeof nex[i]);
        }
        /*
        for (int i = 1, c; i <= (int)s.length(); ++i) {
            c = s[i-1]-'a';
            for (int j = 0; j < 26; ++j) {
                if (!nex[last[j]][c]) nex[last[j]][c] = i;
            }
            last[c] = i;
        }
        */
        for (int i = (int)s.length(), c; i; --i) {
            c = s[i-1]-'a';
            for (int j = 0; j < 26; ++j)
                nex[i-1][j] = nex[i][j];
            nex[i-1][c] = i;
        }
        int res = 1;
        for (int i = 0, p = 0, c; i < (int)t.length(); ++i) {
            c = t[i]-'a';
            p = nex[p][c];
            if (!p) {
                p = nex[p][c];
                ++res;
            }
        }
        cout << res << endl;
    }
    return 0;
}
