#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;
const int kM = 388211;

int T, n, m, p, mod;
int a[kN], b[kN], cnt_a[kM], cnt_b[kM], value[kN<<1];
int que[kN<<1], tail;
unsigned long long k1, k2;
int fir[kM+7], nex[kM+7], val[kM+7], tot;

inline unsigned long long rng() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

inline void add_hash(int x)
{
    int now = x%kM;
    val[++tot] = x;
    nex[tot] = fir[now];
    fir[now] = tot;
}

inline int find_hash(int x)
{
    int now = x%kM;
    for(int i = fir[now]; i; i = nex[i])
        if (val[i] == x) return i;
    return 0;
}

inline void make_hash(int &x)
{
    int tmp = find_hash(x);
    if (tmp) {
        x = tmp;
    } else {
        add_hash(x);
        x = tot;
    }
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        tail = 0;
        tot = 0;
        scanf("%d%d%d", &n, &m, &p);
        if (p == 1) {
            for(int i = 1; i <= n; ++i) {
                scanf("%d", a+i);
                que[++tail] = a[i];
                make_hash(a[i]);
                ++cnt_a[a[i]];
            }
            for(int i = 1; i <= m; ++i) {
                scanf("%d", b+i);
                que[++tail] = b[i];
                make_hash(b[i]);
                ++cnt_b[b[i]];
            }
        } else {
            scanf("%lld%lld%d", &k1, &k2, &mod);
            for(int i = 1; i <= n; ++i) {
                a[i] = int(rng()%mod);
                que[++tail] = a[i];
                make_hash(a[i]);
                ++cnt_a[a[i]];
            }
            scanf("%lld%lld%d", &k1, &k2, &mod);
            for(int i = 1; i <= m; ++i) {
                b[i] = int(rng()%mod);
                que[++tail] = b[i];
                make_hash(b[i]);
                ++cnt_b[b[i]];
            }
        }

        for(int i = 1; i <= n+m; ++i) value[i] = 0;
        int mark_a = 0, mark_b = 0;
        for(int i = 1; i <= tot; ++i) {
            if (cnt_a[i] && cnt_b[i]) {
                int tmp = cnt_a[i]+cnt_b[i];
                if (value[tmp]) {
                    mark_a += cnt_a[value[tmp]];
                    mark_b += cnt_b[i];
                    value[tmp] = 0;
                } else {
                    value[tmp] = i;
                }
            } else {
                mark_a += cnt_a[i];
                mark_b += cnt_b[i];
            }
        }

        int person = 1;
        for(int i = n+m; i; --i) {
            if (!value[i]) continue;
            if (person) mark_a += cnt_a[value[i]];
            else mark_b += cnt_b[value[i]];
            person ^= 1;
        }
        printf("%s", (mark_a > mark_b ? "Cuber QQ\n" : "Quber CC\n"));

        for(int i = 1; i <= tail; ++i)
            fir[que[i]%kM] = 0;
        for(int i = 1; i <= tot; ++i)
            cnt_a[i] = cnt_b[i] = 0;
    }
    return 0;
}
