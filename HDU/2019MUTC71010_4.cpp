#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;
const int kM = 388211;

int T, n, m, p, mod;
int a[kN], b[kN], cnt_a[kM], cnt_b[kM], value[kN<<1];
unsigned long long k1, k2;
int fir[kM+7], nex[kM+7], val[kM+7], tot;

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
    // scanf("%d", &T);
    read(T);
    while(T--) {
        tot = 0;
        for(int i = 1; i <= kM; ++i)
            fir[i] = 0;
        for(int i = 1; i <= kM; ++i)
            cnt_a[i] = cnt_b[i] = 0;
        // scanf("%d%d%d", &n, &m, &p);
        read(n); read(m); read(p);
        if (p == 1) {
            for(int i = 1; i <= n; ++i) {
                // scanf("%d", a+i);
                read(a[i]);
                make_hash(a[i]);
                ++cnt_a[a[i]];
            }
            for(int i = 1; i <= m; ++i) {
                // scanf("%d", b+i);
                read(b[i]);
                make_hash(b[i]);
                ++cnt_b[b[i]];
            }
        } else {
            // scanf("%lld%lld%d", &k1, &k2, &mod);
            read(k1); read(k2); read(mod);
            for(int i = 1; i <= n; ++i) {
                a[i] = int(rng()%mod);
                make_hash(a[i]);
                ++cnt_a[a[i]];
            }
            for(int i = 1; i <= m; ++i) {
                b[i] = int(rng()%mod);
                make_hash(b[i]);
                ++cnt_b[b[i]];
            }
        }

        for(int i = 1; i <= n+m; ++i) value[i] = 0;
        int mark_a = 0, mark_b = 0;
        for(int i = 1; i <= tot; ++i) {
            if (cnt_a[i] && cnt_b[i]) {
                // value[cnt_a[i]+cnt_b[i]].emplace_back(i);
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
            if(!value[i]) continue;
            if (person) mark_a += cnt_a[value[i]];
            else mark_b += cnt_b[value[i]];
            person ^= 1;
        }
        printf("%s", (mark_a > mark_b ? "Cuber QQ\n" : "Quber CC\n"));
    }
    return 0;
}
