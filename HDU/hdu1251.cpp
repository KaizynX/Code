#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

struct TireTree
{
    static const int SZ = 26;
    char beg;
    int nex[N][SZ], num[N], cnt;
    bool exist[N];
    TireTree(char _beg = 'a') : beg(_beg) {
        memset(nex, 0, sizeof nex);
        memset(num, 0, sizeof num);
        memset(exist, 0, sizeof exist);
        cnt = 0;
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
} TT;

int main()
{
    int mode = 0;
    string str;
    while (getline(cin, str)) {
        if (!str.length()) mode = 1;
        else if (!mode) {
            TT.insert(str);
        } else {
            cout << TT.count(str) << endl;
        }
    }
    return 0;
}
