#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;
const int S = 5e2+7;
const int MOD = 1e9+7;

int T, x;
int a[N];
char s[S];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &x, s+1);
        int n = strlen(s+1);
        for (int i = 1; i <= n; ++i)
            a[i] = s[i]-'0';
        for (int i = 1, flag = 0, sz = n; i <= x; ++i) {
            if (!flag) {
                sz = (n+(n-i)*(a[i]-1)%MOD)%MOD;
                for (int j = n+1, k = i+1; j <= min(x, sz); ++j, ++k) {
                    if (k > n) k = i+1;
                    a[j] = a[k];
                }
            }
            if (sz >= x) flag = 1;
            (n += (n-i)*(a[i]-1)%MOD) %= MOD;
        }
        printf("%d\n", n);
    }
    return 0;
}
