#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

struct TireTree
{
    static const int NN = 5e3+7;
    static const int SZ = 26;
    char beg;
    int nex[NN][SZ], num[NN], cnt, dep;
    bool exist[NN];
    TireTree(char _beg = 'a') : beg(_beg) {
        memset(nex, 0, sizeof nex);
        memset(num, 0, sizeof num);
        memset(exist, 0, sizeof exist);
        cnt = dep = 0;
    }
    void insert(const char *s) {
        int len = strlen(s), p = 0;
        for (int i = 0, c; i < len; ++i) {
            c = s[i]-beg;
            if (!nex[p][c]) nex[p][c] = ++cnt;
            p = nex[p][c];
            ++num[p];
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
    int count(const char *s) {
        int len = strlen(s), p = 0;
        for (int i = 0, c; i < len; ++i) {
            c = s[i]-beg;
            if (!nex[p][c]) return 0;
            p = nex[p][c];
        }
        return num[p];
    }
    void insert(const string &s) { insert(s.c_str()); }
    bool find(const string &s) { return find(s.c_str()); }
    int count(const string &s) { return count(s.c_str()); }
    void dfs(int u, int d) {
        dep = max(dep, d);
        for (int i = 0; i < 26; ++i) {
            if (!nex[u][i]) continue;
            dfs(nex[u][i], d+1);
        }
    }
};

int n;
string str;

signed main()
{
    while (cin >> n) {
        TireTree TT;
        for (int i = 1; i <= n; ++i) {
            cin >> str;
            TT.insert(str);
        }
        TT.dfs(0, 0);
        cout << TT.cnt*2+n-TT.dep << endl;
    }
    return 0;
}
