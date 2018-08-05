#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cmath>
#define DEBUG

using namespace std;

const int Maxs = 107;

int n, s, t, A, B;
double vis[Maxs][4];
double v[Maxs][Maxs][4][4];
// v[i][j][a][b] city[i].point[a] --> city[j].point[b]
struct Node
{
    int x[4], y[4], oppo[4], t;
    double d[4][4];

    Node(){}

    inline double dis(int i, int j)
    {
        return t*sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
    }

    inline void init()
    {
        for(int i = 0; i < 2; ++i)
            for(int j = i+1; j < 3; ++j)
                d[i][j] = d[j][i] = dis(i, j);
        double maxd = max( max(d[0][1], d[1][2]), d[0][2]);
        if(maxd == d[0][1])
        {
            oppo[0] = 1;
            oppo[1] = 0;
            oppo[2] = 3;
            oppo[3] = 2;
            x[3] = x[0]+x[1]-x[2];
            y[3] = y[0]+y[1]-y[2];
        }
        else if(maxd == d[1][2])
        {
            oppo[0] = 3;
            oppo[1] = 2;
            oppo[2] = 1;
            oppo[3] = 0;
            x[3] = x[1]+x[2]-x[0];
            y[3] = y[1]+y[2]-y[0];
        } 
        else if(maxd == d[0][2])
        {
            oppo[0] = 2;
            oppo[1] = 3;
            oppo[2] = 0;
            oppo[3] = 1;
            x[3] = x[0]+x[2]-x[1];
            y[3] = y[0]+y[2]-y[1];
        }
        for(int i = 0; i < 3; ++i)
            d[i][3] = d[3][i] = dis(i, 3);
    }
#ifdef DEBUG
    inline void print()
    {
        printf("%d %d\n", x[3], y[3]);
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
                printf("%.1f ", d[i][j]);
            putchar('\n');
        }
    }
#endif
} a[Maxs];

struct Nodeq
{
    double d;
    int ci, pi;

    Nodeq(){}
    Nodeq(double d, int ci, int pi) : d(d), ci(ci), pi(pi) {}

    bool operator < (const Nodeq &b) const
    {
        return d > b.d;
    }
} cur;

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        memset(vis, 0, sizeof vis);
        scanf("%d%d%d%d", &s, &t, &A, &B);
        for(int i = 1; i <= s; ++i)
        {
            for(int j = 0; j < 3; ++j)
                scanf("%d%d", &a[i].x[j], &a[i].y[j]);
            scanf("%d", &a[i].t);
            a[i].init();
#ifdef DEBUG
            // a[i].print();
#endif
            for(int j = 1; j < i; ++j)
                for(int ci = 0; ci < 4; ++ci)
                    for(int cj = 0; cj < 4; ++cj)
                        v[i][j][ci][cj] = v[j][i][cj][ci] = 
                            t*sqrt((a[i].x[ci]-a[j].x[cj])*(a[i].x[ci]-a[j].x[cj]) 
                                  +(a[i].y[ci]-a[j].y[cj])*(a[i].y[ci]-a[j].y[cj]));
        }
        if(A == B)
        {
            printf("0.0\n");
            continue;
        }
        // dijiskar
        priority_queue<Nodeq> q;
        for(int i = 1; i <= s; ++i)
        {
            if(i == A) continue;
            for(int j = 0; j < 4; ++j)
                for(int k = 0; k < 4; ++k)
                {
                    q.push(Nodeq(v[A][i][j][k], i, k));
                    vis[i][k] = v[A][i][j][k];
                }
        }
        while(!q.empty())
        {
            cur = q.top();
            q.pop();
#ifdef DEBUG
            printf("%.1f %d %d\n", cur.d, cur.ci, cur.pi);
#endif
            if(cur.ci == B)
            {
                printf("%.1f\n", cur.d);
                break;
            }
            if(cur.d > vis[cur.ci][cur.pi]) continue;
            for(int i = 1; i <= s; ++i)
            {
                if(i == A || i == cur.ci) continue;
                for(int j = 0; j < 4; ++j)
                {
                    double tmp = cur.d+v[cur.ci][i][cur.pi][j];
                    if(vis[i][j] && vis[i][j] <= tmp) continue;
                    q.push(Nodeq(tmp, i, j));
                    vis[i][j] = tmp;
                }
            }
            for(int i = 0; i < 4; ++i)
            {
                if(i == cur.pi || i == a[cur.ci].oppo[cur.pi]) continue;
                double tmp = cur.d+a[cur.ci].d[cur.pi][i];
                if(vis[cur.ci][i] && vis[cur.ci][i] <= tmp) continue;
                q.push(Nodeq(tmp, cur.ci, i));
                vis[cur.ci][i] = tmp;
            }
        }
    }
    return 0;
}
