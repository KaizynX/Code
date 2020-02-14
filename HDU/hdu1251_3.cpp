#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

char str[20];

struct TrieTree
{
    static const int SZ = 26;
    char beg;
    int nex[N][SZ], num[N], cnt;
    TrieTree(char _beg = 'a') : beg(_beg) {
        memset(nex, 0, sizeof nex);
        memset(num, 0, sizeof num);
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
    int count(const string &s) { return count(s.c_str()); }
} TT;

int main()
{
    while (gets(str) && str[0] != '\0')
        TT.insert(str);
    while (~scanf("%s", str))
        printf("%d\n", TT.count(str));
    return 0;
}
