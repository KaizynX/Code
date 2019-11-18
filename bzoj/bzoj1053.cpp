#include <bits/stdc++.h>

using namespace std;

const int p[20] = { 0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

int n;
long long resv, rest;
int k[20];

void dfs(int cur, long long now, long long cnt)
{
    if (cur > 11 || now*p[cur] > n) {
        if (cnt > rest) {
            rest = cnt;
            resv = now;
        } else if (cnt == rest) {
            resv = min(resv, now);
        }
        return;
    }
    long long powx = p[cur];
    for (k[cur] = 1; k[cur] <= k[cur-1] && powx*now <= n; ++k[cur], powx *= p[cur]) {
        dfs(cur+1, now*powx, cnt*(k[cur]+1));
    }
    k[cur] = 0;
}

int main()
{
    scanf("%d", &n);
    k[0] = 31;
    dfs(1, 1, 1);
    printf("%lld\n", resv);
    return 0;
}
