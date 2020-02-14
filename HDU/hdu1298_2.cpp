#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 1e5+7;
const int L = 1e2+7;
const int number[] = {0,0,3,3,3,3,3,4,3,4,0,0,0};

int T, n, m;
char word[N][L], str[L], cc[M];
int w[N], mp[26];
int pre[M], nex[M][26], num[M], cnt;
int tag[M], son[M][10], tot;

inline void init()
{
    memset(pre, 0, sizeof(int)*(cnt+3));
    memset(nex, 0, sizeof(nex[0])*(cnt+3));
    memset(num, 0, sizeof(int)*(cnt+3));
    memset(tag, 0, sizeof(int)*(tot+3));
    memset(son, 0, sizeof(son[0])*(tot+3));
    cnt = tot = 0;
}

inline void my_add(const char *s, const int t)
{
    for (int i = 0, p = 0, c; s[i] != '\0'; ++i) {
        c = s[i]-'a';
        if (!nex[p][c]) {
            nex[p][c] = ++cnt;
            pre[cnt] = p;
            cc[cnt] = s[i];
        }
        p = nex[p][c];
        num[p] += t;
    }
}

void dfs(int x, int y)
{
    for (int i = 0, c, xx, yy; i < 26; ++i) {
        if (!nex[x][i]) continue;
        c = mp[i];
        if (!son[y][c])
            son[y][c] = ++tot;
        xx = nex[x][i];
        yy = son[y][c];
        if (!tag[yy] || num[tag[yy]] < num[xx])
            tag[yy] = xx;
        dfs(xx, yy);
    }
}

inline void my_print(int p)
{
    static char buf[L];
    if (!p) puts("MANUALLY");
    else {
        int i = 0;
        for ( ; p; ++i, p = pre[p])
            buf[i] = cc[p];
        for (--i; i >= 0; --i)
            putchar(buf[i]);
        putchar('\n');
    }
}

inline void my_find(const char *s)
{
    int p = 0;
    for (int i = 0, c, flag = 1; s[i] != '1'; ++i) {
        c = s[i]-'0';
        if (!flag || !son[p][c]) {
            my_print(0);
            flag = 0;
            continue;
        }
        p = son[p][c];
        my_print(tag[p]);
    }
}

int main()
{
    for (int i = 0, sum = 0, id = 1; i < 26; ++i) {
        if (sum <= i) sum += number[++id];
        mp[i] = id;
    }
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        init();
        printf("Scenario #%d:\n", t);
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%s%d", word[i], w+i);
            my_add(word[i], w[i]);
        }
        dfs(0, 0);
        scanf("%d", &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%s", str);
            my_find(str);
            putchar('\n');
        }
        putchar('\n');
    }
    return 0;
}
