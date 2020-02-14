#include <bits/stdc++.h>

using namespace std;

struct TireTree
{
    static const int NN = 2e5+7;
    static const int SZ = 26;
    char beg;
    int nex[NN][SZ], cnt;
    bool exist[NN];
    TireTree(char _beg = 'a') : beg(_beg) {
        memset(nex, 0, sizeof nex);
        memset(exist, 0, sizeof exist);
        cnt = 0;
    }
    void insert(const char *s) {
        int len = strlen(s), p = 0;
        for (int i = 0, c; i < len; ++i) {
            c = s[i]-beg;
            if (!nex[p][c]) nex[p][c] = ++cnt;
            p = nex[p][c];
        }
        exist[p] = true;
    }
    bool find(const char *s) {
        int len = strlen(s), p = 0;
        for (int i = 0, c; i < len; ++i) {
            c = s[i]-beg;
            if (!nex[p][c]) return false;
            p = nex[p][c];
        }
        return exist[p];
    }
    bool check(const char *s) {
        int len = strlen(s), p = 0;
        for (int i = 0, c; i < len; ++i) {
            c = s[i]-beg;
            if (!nex[p][c]) return false;
            p = nex[p][c];
            if (exist[p] && find(s+i+1)) return true;
        }
        return false;
    }
    void insert(const string &s) { insert(s.c_str()); }
    bool find(const string &s) { return find(s.c_str()); }
    bool check(const string &s) { return check(s.c_str()); }
} TT;

string str;
vector<string> v, res;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> str) {
        v.emplace_back(str);
    }
    sort(v.begin(), v.end(),
        [](const string &s1, const string &s2)
        { return s1.length() < s2.length(); });
    for (string s : v) {
        if (TT.check(s)) res.emplace_back(s);
        TT.insert(s);
    }
    sort(res.begin(), res.end());
    for (string s : res)
        cout << s << endl;
    return 0;
}
