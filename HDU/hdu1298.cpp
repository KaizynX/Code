#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int L = 1e2+7;
const int num[] = {0,0,3,3,3,3,3,4,3,4,0,0,0};

int T, n, m;
char word[N][L], w[L], str[L], mp[26];

struct TireTree
{
    static const int NN = 1e5+7;
    static const int SZ = 10;
    char beg;
    int nex[NN][SZ], tag[NN], cnt;
    TireTree(char _beg = 'a') : beg(_beg) {
        memset(nex, 0, sizeof nex);
        memset(tag, 0, sizeof tag);
        cnt = 0;
    }
    void insert(const int id) {
        const char *s = str;
        int len = strlen(s), p = 0;
        for (int i = 0, c; i < len; ++i) {
            c = s[i]-beg;
            if (!nex[p][c]) nex[p][c] = ++cnt;
            p = nex[p][c];
            if (!tag[p] || w[tag[p]] < w[id]) tag[p] = id;
        }
    }
    void find(const char *s) {
        int len = strlen(s), p = 0, flag = 0;
        for (int i = 0, c; i < len-1; ++i) {
            c = s[i]-beg;
            p = nex[p][c];
            if (flag || !p || !tag[p]) {
                puts("MANUALLY");
                flag = 1;
                continue;
            }
            for (int j = 0; j <= i; ++j)
                putchar(word[tag[p]][j]);
            putchar('\n');
        }
        putchar('\n');
    }
};

inline void init()
{
    for (int i = 0, sum = 0, id = 1; i < 26; ++i) {
        if (sum <= i) sum += num[++id];
        mp[i] = id+'0';
    }
}

inline void change(char *s)
{
    for (int i = 0; s[i] != '\0'; ++i)
        str[i] = mp[s[i]-'a'];
    str[strlen(s)] = '\0';
}

int main()
{
    init();
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        TireTree TT('0');
        printf("Scenario #%d:\n", t);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%s%d", word[i], w+i);
            change(word[i]);
            TT.insert(i);
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%s", str);
            TT.find(str);
        }
        putchar('\n');
    }
    return 0;
}
