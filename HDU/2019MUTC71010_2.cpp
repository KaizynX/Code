#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int T, n, m, p, mod, num_f, num_v;
int a[kN], b[kN], cnt_a[kN<<1], cnt_b[kN<<1];
unsigned long long k1, k2;
unordered_map<int, int> f;
vector<int> value[kN<<1];

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

int main()
{
    scanf("%d", &T);
    while(T--) {
        f.clear(); num_f = 0;
        // scanf("%d%d%d", &n, &m, &p);
        read(n); read(m); read(p);
        if (p == 1) {
            for(int i = 1; i <= n; ++i) {
                // scanf("%d", a+i);
                read(a[i]);
                if (f[a[i]] == 0)
                    f[a[i]] = ++num_f;
            }
            for(int i = 1; i <= m; ++i) {
                // scanf("%d", b+i);
                read(b[i]);
                if (f[b[i]] == 0)
                    f[b[i]] = ++num_f;
            }
        } else {
            // scanf("%lld%lld%d", &k1, &k2, &mod);
            read(k1); read(k2); read(mod);
            for(int i = 1; i <= n; ++i) {
                a[i] = int(rng()%mod);
                if (f[a[i]] == 0)
                    f[a[i]] = ++num_f;
            }
            for(int i = 1; i <= m; ++i) {
                b[i] = int(rng()%mod);
                if (f[b[i]] == 0)
                    f[b[i]] = ++num_f;
            }
        }

        for(int i = 1; i <= num_f; ++i)
            cnt_a[i] = cnt_b[i] = 0;
        for(int i = 1; i <= n; ++i)
            ++cnt_a[f[a[i]]];
        for(int i = 1; i <= m; ++i)
            ++cnt_b[f[b[i]]];

        for(int i = 1; i <= n+m; ++i) value[i].clear();
        int mark_a = 0, mark_b = 0;
        num_v = 0;
        for(int i = 1; i <= num_f; ++i) {
            if (cnt_a[i] && cnt_b[i]) {
                value[cnt_a[i]+cnt_b[i]].emplace_back(i);
            } else {
                mark_a += cnt_a[i];
                mark_b += cnt_b[i];
            }
        }

        int person = 1;
        for(int i = n+m; i; --i) {
            if (!value[i].size()) continue;
            for(int j = 0; j < value[i].size(); ++j) {
                if (person) mark_a += cnt_a[value[i][j]];
                else mark_b += cnt_b[value[i][j]];
                person ^= 1;
            }
        }
        printf("%s", (mark_a > mark_b ? "Cuber QQ\n" : "Quber CC\n"));
    }
    return 0;
}
