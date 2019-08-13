#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int T, n, m, p, mod, num_f, num_v;
int a[kN], b[kN], f[kN<<1];
int cnt_a[kN<<1], cnt_b[kN<<1];
pair<int, int> value[kN]; 
unsigned long long k1, k2;

unsigned long long rng() {
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
        scanf("%d%d%d", &n, &m, &p);
        if (p == 1) {
            for(int i = 1; i <= n; ++i) {
                scanf("%d", a+i);
                f[i] = a[i];
            }
            for(int i = 1; i <= m; ++i) {
                scanf("%d", b+i);
                f[n+i] = b[i];
            }
        } else {
            scanf("%lld%lld%d", &k1, &k2, &mod);
            for(int i = 1; i <= n; ++i) {
                a[i] = int(rng()%mod);
                f[i] = a[i];
            }
            scanf("%lld%lld%d", &k1, &k2, &mod);
            for(int i = 1; i <= m; ++i) {
                b[i] = int(rng()%mod);
                f[n+i] = b[i];
            }
        }
        // ÀëÉ¢
        sort(f+1, f+n+m+1);
        num_f = unique(f+1, f+n+m+1)-f;
        // printf("%d\n", num_f);
        for(int i = 1; i < num_f; ++i)
            cnt_a[i] = cnt_b[i] = 0;
        int id = 1;
        sort(a+1, a+n+1);
        for(int i = 1; i <= n; ++i) {
            while(id < num_f && f[id] < a[i]) ++id;
            ++cnt_a[id];
        }
        id = 1;
        sort(b+1, b+m+1);
        for(int i = 1; i <= m; ++i) {
            while(id < num_f && f[id] < b[i]) ++id;
            ++cnt_b[id];
        }
        int mark_a = 0, mark_b = 0;
        num_v = 0;
        for(int i = 1; i < num_f; ++i) {
            if(cnt_a[i] && cnt_b[i]) {
                value[++num_v] = { cnt_a[i]+cnt_b[i], i };
            } else {
                mark_a += cnt_a[i];
                mark_b += cnt_b[i];
            }
        }
        sort(value+1, value+num_v+1);
        reverse(value+1, value+num_v+1);
        for(int i = 1; i <= num_v; ++i) {
            if(i&1)
                mark_a += cnt_a[value[i].second];
            else
                mark_b += cnt_b[value[i].second];
        }
        printf("%s", (mark_a > mark_b ? "Cuber QQ\n" : "Quber CC\n"));
    }
    return 0;
}
