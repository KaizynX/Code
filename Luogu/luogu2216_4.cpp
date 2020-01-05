#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;
const int INF = 1e9;

int n, m, k, hbig, hsma, tbig, tsma;
int a[N][N], big[N][N], sma[N][N];
pair<int, int> qbig[N], qsma[N];

inline void push(int i, int v) {
    while (hbig < tbig && qbig[tbig].second <= v) --tbig;
    while (hsma < tsma && qsma[tsma].second >= v) --tsma;
    qbig[++tbig] = {i, v};
    qsma[++tsma] = {i, v};
}

inline void pop(int i) {
    while (hbig < tbig && qbig[hbig+1].first < i-k+1) ++hbig;
    while (hsma < tsma && qsma[hsma+1].first < i-k+1) ++hsma;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    for (int j = 1; j <= m; ++j) {
        hbig = hsma = tbig = tsma = 0;
        for (int i = 1; i < k; ++i)
            push(i, a[i][j]);
        for (int i = k; i <= n; ++i) {
            pop(i);
            push(i, a[i][j]);
            big[i][j] = qbig[hbig+1].second;
            sma[i][j] = qsma[hsma+1].second;
#ifdef DEBUG
            printf("[%d, %d] %d %d\n", i, j, big[i][j], sma[i][j]);
#endif
        }
    }

    int res = INF;
    for (int i = k; i <= n; ++i) {
        hbig = hsma = tbig = tsma = 0;
        for (int j = 1; j < k; ++j)
            push(j, big[i][j]), push(j, sma[i][j]);
        for (int j = k; j <= m; ++j) {
            pop(j);
            push(j, big[i][j]);
            push(j, sma[i][j]);
            res = min(res, qbig[hbig+1].second-qsma[hsma+1].second);
#ifdef DEBUG
            printf("[%d, %d] %d %d\n", i, j, qbig[hbig+1].second, qsma[hsma+1].second);
#endif
        }
    }
    printf("%d\n", res);
    return 0;
}

