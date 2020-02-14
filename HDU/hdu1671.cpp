#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

struct TireTree
{
    static const int SZ = 10;
    char beg;
    int nex[N][SZ], num[N], cnt;
    bool exist[N];
    TireTree(char _beg = 'a') : beg(_beg) {
        memset(nex, 0, sizeof nex);
        memset(num, 0, sizeof num);
        memset(exist, 0, sizeof exist);
        cnt = 0;
    }
    bool insert(const char *s) {
        int len = strlen(s), p = 0, flag = 0;
        for (int i = 0, c; i < len; ++i) {
            c = s[i]-beg;
            if (!nex[p][c]) {
                nex[p][c] = ++cnt;
                flag = 1;
            }
            p = nex[p][c];
            if (exist[p]) return false;
            ++num[p];
        }
        exist[p] = true;
        return flag;
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
    bool insert(const string &s) { return insert(s.c_str()); }
    bool find(const string &s) { return find(s.c_str()); }
    int count(const string &s) { return count(s.c_str()); }
};

int T, n;
string str;

int main()
{
    cin >> T;
    while (T--) {
        TireTree TT('0');
        int flag = 1;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> str;
            flag &= TT.insert(str);
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
