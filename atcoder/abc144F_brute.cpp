#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 600+7;
const int M = N*N/2;

int n, m;
int a[N][N];
int s[M], t[M];
int len[N], num[N];
double res;

inline double calc()
{
    for (int i = 1; i <= n; ++i) len[i] = num[i] = 0;
    num[n] = 1;
    for (int i = n-1; i; --i) {
        for (int j = i+1; j <= n; ++j) {
            if (!a[i][j]) continue;
            len[i] += len[j]+num[j];
            num[i] += num[j];
        }
    }
    return 1.0*len[1]/num[1];
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d %d", s+i, t+i);
        a[s[i]][t[i]] = 1;
    }
    res = calc();
    for (int i = 1; i <= m; ++i) {
        a[s[i]][t[i]] = 0;
        res = min(res, calc());
        a[s[i]][t[i]] = 1;
    }
    printf("%.10lf\n", res);
    return 0;
}
