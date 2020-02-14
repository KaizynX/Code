#include <bits/stdc++.h>

using namespace std;

const int N = 25;

struct TireTree
{
    static const int NN = 5e5+7;
    static const int SZ = 26;
    char beg;
    int nex[NN][SZ], num[NN], tag[NN], cnt;
    bool exist[NN];
    TireTree(char _beg = 'a') : beg(_beg) {
        memset(nex, 0, sizeof nex);
        memset(num, 0, sizeof num);
        memset(tag, 0, sizeof tag);
        memset(exist, 0, sizeof exist);
        cnt = 0;
    }
    void insert(const char *s, const int id) {
        int len = strlen(s);
        for (int j = 0; j < len; ++j) {
            for (int i = j, c, p = 0; i < len; ++i) {
                c = s[i]-beg;
                if (!nex[p][c]) nex[p][c] = ++cnt;
                p = nex[p][c];
                if (tag[p] == id) continue;
                tag[p] = id;
                ++num[p];
            }
        }
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
    void insert(const string &s, const int id) { insert(s.c_str(), id); }
    int count(const string &s) { return count(s.c_str()); }
} TT;

int n;
char str[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", str);
        TT.insert(str, i);
    }
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", str);
        printf("%d\n", TT.count(str));
    }
    return 0;
}
