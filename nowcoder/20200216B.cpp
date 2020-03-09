#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

struct TireTree
{
    static const int NN = 5e5+7;
    static const int SZ = 10;
    char beg;
    int nex[NN][SZ], cnt;
    bool exist[NN];
    TireTree(char _beg = 'a') : beg(_beg) { clear(); }
    void clear() {
        memset(nex, 0, sizeof nex);
        memset(exist, 0, sizeof exist);
        cnt = 0;
    }
    bool insert(const char *s) {
        int len = strlen(s), p = 0;
        for (int i = 0, c; i < len; ++i) {
            c = s[i]-beg;
            if (!nex[p][c]) nex[p][c] = ++cnt;
            p = nex[p][c];
            if (exist[p]) return false;
        }
        exist[p] = true;
        return true;
    }
    bool insert(const string &s) { return insert(s.c_str()); }
} TT('0');

int T, n;
string str[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        TT.clear();
        int flag = 1;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> str[i];
        sort(str+1, str+n+1,
            [](const string &s1, const string &s2) { return s1.length() < s2.length(); });
        for (int i = 1; i <= n; ++i) {
            if (!TT.insert(str[i])) {
                flag = 0;
                break;
            }
        }
        cout << "Case #" << t << ": " << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
