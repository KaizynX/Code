#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int MAXN = 1e6+7;
const int INF = 1e9;

int n, w, l, head, tail;
int qv[MAXN], qi[MAXN];
long long col[MAXN];

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void write(T x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

int main()
{
    // scanf("%d%d", &n, &w);
    read(n); read(w);
    for (int i = 1; i <= n; ++i) {
        head = tail = 0;
        // scanf("%d", &l);
        read(l);
        for (int j = 1, a; j <= w; ++j) {
            if (j <= l) {
                read(a);
                while (head < tail && qv[tail] <= a) --tail;
                ++tail;
                qv[tail] = a;
                qi[tail] = j;
            }
            int st = j-(w-l), tmp = -INF;
            if (st < 1) st = 1, tmp = 0;
            if (j > l) tmp = 0;
            while (qi[head+1] < st) ++head;
            if (qv[head+1] > tmp) tmp = qv[head+1];
            col[j] += tmp;
        }
    }
    for (int i = 1; i <= w; ++i) {
        // printf("%lld%c", col[i], " \n"[i == w]);
        write(col[i]);
        putchar((i == w ? '\n' : ' '));
    }
    return 0;
}
