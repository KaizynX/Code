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
} qbig[N<<2], qsma[N<<2], rbig[N][N], rsma[N][N], cbig[N][N], csma[N][N];

inline bool check(const Node &node, int bx, int by, int ex, int ey) {
    return node.x >= bx && node.x <= ex && node.y >= by && node.y <= ey;
}

inline void push(const Node &node) {
    while (hbig < tbig && qbig[tbig].v <= node.v) --tbig;
    while (hsma < tsma && qsma[tsma].v >= node.v) --tsma;
    qbig[++tbig] = node;
    qsma[++tsma] = node;
}

inline void pop(int bx, int by, int ex, int ey) {
    while (hbig < tbig && !check(qbig[hbig+1], bx, by, ex, ey)) ++hbig;
    while (hsma < tsma && !check(qsma[hsma+1], bx, by, ex, ey)) ++hsma;
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);

    for (int i = 1; i <= n; ++i) {
        hbig = hsma = tbig = tsma = 0;
        for (int j = 1; j < k; ++j) push(Node(i, j, a[i][j]));
        for (int j = k; j <= m; ++j) {
            pop(i, j-k+1, i, j);
            push(Node(i, j, a[i][j]));
            rbig[i][j] = qbig[hbig+1];
            rsma[i][j] = qsma[hsma+1];
        }
    }
    for (int j = 1; j <= m; ++j) {
        hbig = hsma = tbig = tsma = 0;
        for (int i = 1; i < k; ++i) push(Node(i, j, a[i][j]));
        for (int i = k; i <= n; ++i) {
            pop(i-k+1, j, i, j);
            push(Node(i, j, a[i][j]));
            cbig[i][j] = qbig[hbig+1];
            csma[i][j] = qsma[hsma+1];
        }
    }

    int res = INF;
    for (int i = 1; i <= k; ++i) push(rbig[i][k]), push(rsma[i][k]);
    for (int bx = 1, by, ex, ey; (ex = bx+k-1) <= n; ++bx) {
        if (bx&1) {
            push(rbig[ex][k]); push(rsma[ex][k]);
            for (by = 1; (ey = by+k-1) <= m; ++by) {
                pop(bx, by, ex, ey);
                push(cbig[ex][ey]);
                push(csma[ex][ey]);
                res = min(res, qbig[hbig+1].v-qsma[hsma+1].v);
            }
        } else {
            push(rbig[ex][m]); push(rsma[ex][m]);
            for (ey = m; (by = ey-k+1) >= 1; --ey) {
                pop(bx, by, ex, ey);
                push(cbig[ex][by]);
                push(csma[ex][by]);
                res = min(res, qbig[hbig+1].v-qsma[hsma+1].v);
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
