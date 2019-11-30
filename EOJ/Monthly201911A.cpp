#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;
const int K = 30;

int n, m, k;
long long x;
char str[N], s[N][K];

int main()
{
    scanf("%d %d %d %lld%s", &n, &m, &k, &x, str);
    --x;
    for (int i = 1; i <= m; ++i) {
        scanf("%s", s[i]);
        sort(s[i], s[i]+k);
    }
    int p = m;
    long long c = 1;
    for ( ; p; --p, c *= k) {
        if (x/k < c) break;
    }
    for (int i = 0, t = 0; i < n; ++i) {
        if (str[i] != '#') continue;
        if (++t < p) {
            str[i] = s[t][0];
            continue;
        }
        int l = 0, r = k-1;
        while (l < r) {
            int mid = (l+r+1)>>1;
            if (x/c < mid) r = mid-1;
            else l = mid;
        }
        str[i] = s[t][l];
        x -= l*c;
        c /= k;
    }
    puts(str);
    return 0;
}
