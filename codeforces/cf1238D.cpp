#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 3e5+7;

int n, res;
int r[N<<1];
char s[N], ss[N<<1];

struct BinaryIndexedTree
{
    // set your type
    typedef int T;
    T tr[N<<1];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

inline void manacher(const char *str, char *buf, int *p)
{
    int str_len = strlen(str), buf_len = 2;
    buf[0] = buf[1] = '#';
    for(int i = 0; i < str_len; ++i)
        buf[buf_len++] = str[i], buf[buf_len++] = '#';
    // 012345...XXbuf_len
    // ##s#s#...s#
    int mx = 0, id;
    for(int i = 1; i < buf_len; ++i)
    {
        if(i <= mx) p[i] = min(p[id*2-i], mx-i);
        else p[i] = 1;
        while(buf[i-p[i]] == buf[i+p[i]]) p[i]++;
        if(i+p[i] > mx) mx = i+p[i], id = i;

        if (p[i]-1 > 1) {
            res += (p[i]-1)/2;
            // res += BIT.query(i-p[i]+1, i);
            // BIT.update(i, i+p[i]-1, 1);
        }
    }
}

int main()
{
    scanf("%d%s", &n, s);
    manacher(s, ss, r);
    cout << res << endl;
#ifdef DEBUG
    for (int i = 1; i <= n*2; ++i) {
        printf("%d%c", r[i], " \n"[i==n*2]);
    }
#endif
    return 0;
}
