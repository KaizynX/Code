#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;
const int INF = 1e9;

int n, m, k, hbig, hsma, tbig, tsma;
int a[N][N];

struct Node
{
    int x, y, v;
    Node(){}
    Node(int _x, int _y, int _v) : x(_x), y(_y), v(_v) {}
} qbig[N*N], qsma[N*N];

inline bool check(const Node &node, int bx, int by, int ex, int ey) {
    return node.x >= bx && node.x <= ex && node.y >= by && node.y <= ey;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    int res = INF;
    for (int i = 1; i < k; ++i) {
        for (int j = 1; j < k; ++j) {
            while (hbig < tbig && qbig[tbig].v <= a[i][j]) --tbig;
            while (hsma < tsma && qsma[tsma].v >= a[i][j]) --tsma;
            qbig[++tbig] = Node(i, j, a[i][j]);
            qsma[++tsma] = Node(i, j, a[i][j]);
        }
    }
    for (int bx = 1, by, ex, ey; (ex = bx+k-1) <= n; ++bx) {
        if (bx&1) {
            for (int j = 1; j < k; ++j) {
                while (hbig < tbig && qbig[tbig].v <= a[ex][j]) --tbig;
                while (hsma < tsma && qsma[tsma].v >= a[ex][j]) --tsma;
                qbig[++tbig] = Node(ex, j, a[ex][j]);
                qsma[++tsma] = Node(ex, j, a[ex][j]);
            }
            for (by = 1; (ey = by+k-1) <= m; ++by) {
                while (hbig < tbig && !check(qbig[hbig+1], bx, by, ex, ey)) ++hbig;
                while (hsma < tsma && !check(qsma[hsma+1], bx, by, ex, ey)) ++hsma;
                for (int i = bx; i <= ex; ++i) {
                    while (hbig < tbig && qbig[tbig].v <= a[i][ey]) --tbig;
                    while (hsma < tsma && qsma[tsma].v >= a[i][ey]) --tsma;
                    qbig[++tbig] = Node(i, ey, a[i][ey]);
                    qsma[++tsma] = Node(i, ey, a[i][ey]);
                }
#ifdef DEBUG
                printf("[%d %d %d %d] %d %d\n", bx, by, ex, ey, qbig[hbig+1].v, qsma[hsma+1].v);
#endif
                res = min(res, qbig[hbig+1].v-qsma[hsma+1].v);
            }
        } else {
            for (int j = m; j > m-k+1; --j) {
                while (hbig < tbig && qbig[tbig].v <= a[ex][j]) --tbig;
                while (hsma < tsma && qsma[tsma].v >= a[ex][j]) --tsma;
                qbig[++tbig] = Node(ex, j, a[ex][j]);
                qsma[++tsma] = Node(ex, j, a[ex][j]);
            }
            for (ey = m; (by = ey-k+1); --ey) {
                while (hbig < tbig && !check(qbig[hbig+1], bx, by, ex, ey)) ++hbig;
                while (hsma < tsma && !check(qsma[hsma+1], bx, by, ex, ey)) ++hsma;
                for (int i = bx; i <= ex; ++i) {
                    while (hbig < tbig && qbig[tbig].v <= a[i][by]) --tbig;
                    while (hsma < tsma && qsma[tsma].v >= a[i][by]) --tsma;
                    qbig[++tbig] = Node(i, by, a[i][by]);
                    qsma[++tsma] = Node(i, by, a[i][by]);
                }
#ifdef DEBUG
                printf("[%d %d %d %d] %d %d\n", bx, by, ex, ey, qbig[hbig+1].v, qsma[hsma+1].v);
#endif
                res = min(res, qbig[hbig+1].v-qsma[hsma+1].v);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
