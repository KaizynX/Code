/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 16:51:41
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-11 21:08:22
 * @FilePath: \Code\test.cpp
 */
/* 4418 */
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <deque>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>
#include <functional>
#include <iterator>
#include <iomanip>
using namespace std;
//#pragma comment(linker,"/STACK:102400000,1024000")

#define sti                set<int>
#define stpii            set<pair<int, int> >
#define mpii            map<int,int>
#define vi                vector<int>
#define pii                pair<int,int>
#define vpii            vector<pair<int,int> >
#define rep(i, a, n)     for (int i=a;i<n;++i)
#define per(i, a, n)     for (int i=n-1;i>=a;--i)
#define clr                clear
#define pb                 push_back
#define mp                 make_pair
#define fir                first
#define sec                second
#define all(x)             (x).begin(),(x).end()
#define SZ(x)             ((int)(x).size())
#define lson            l, mid, rt<<1
#define rson            mid+1, r, rt<<1|1

const int maxn = 220;
typedef double mat[maxn][maxn];

const double eps = 1e-8;
int n, nn, m, x, y, d;
int visit[maxn];
int id[maxn];
double P[maxn];
mat g;

bool gauss_elimination(int n) {
    int r;
    
    rep(i, 0, n) {
        r = i;
        rep(j, i+1, n) {
            if (fabs(g[j][i]) > fabs(g[r][i]))
                r = j;
        }
        
        if (r != i) {
            rep(j, 0, n+1)
                swap(g[r][j], g[i][j]);
        }
        
        if (fabs(g[i][i]) < eps)
            return false;
        
        rep(k, i+1, n) {
            double t = g[k][i] / g[i][i];
            rep(j, i+1, n+1)
                g[k][j] -= t * g[i][j];
        }
    }
    
    per(i, 0, n) {
        rep(j, i+1, n)
            g[i][n] -= g[i][j] * g[j][n];
        g[i][n] /= g[i][i];
    }
    
    return true;
}

int bfs(int bx) {
    queue<int> Q;
    int p = 0;
    bool ret = false;
    
    memset(visit, -1, sizeof(visit));
    visit[bx] = p++;
    Q.push(bx);
    
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (id[u] == y)
            ret = true;
        rep(j, 1, m+1) {
            if (fabs(P[j]) < eps)
                continue;
            int v = (u + j) % nn;
            if (visit[v] == -1) {
                visit[v] = p++;
                Q.push(v);
            }
        }
    }
    
    return ret ? p : 0;
}

void solve() {
    if (x == y) {
        puts("0.00");
        return ;
    }
    
    nn = n*2-2;
    
    rep(i, 0, n)
        id[i] = i;
    for (int i=n,j=n-2; i<nn; ++i,--j)
        id[i] = j;
    
    int bx;
    
    if (d == 0)
        bx = x;
    else if (d == 1)
        bx = nn - x;
    else
        bx = x;
    
    int vn = bfs(bx);
    if (!vn) {
        puts("Impossible !");
        return ;
    }
    
    memset(g, 0, sizeof(g));
    rep(i, 0, nn) {
        if (visit[i] == -1)
            continue;
        
        int p = visit[i];
        g[p][p] = 1;
        
        if (id[i] == y)
            continue;
        
        rep(j, 1, m+1) {
            int k = visit[(i + j) % nn];
            if (k == -1)
                continue;
            
            g[p][k] -= P[j];
            g[p][vn] += j * P[j];
        }
    }
    for(int i = 0; i < vn; ++i) {
        for (int j = 0; j <= vn; ++j) {
            cout << g[i][j]*100 << " \n"[j==vn];
        }
    }
    bool flag = gauss_elimination(vn);
    
    if (!flag || fabs(g[0][vn])<eps) {
        puts("Impossible !");
        return ;
    }
    
    printf("%.2lf\n", g[0][vn]);
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d", &n,&m,&y,&x,&d);
        rep(i, 1, m+1) {
            scanf("%lf", &P[i]);
            P[i] /= 100.0;
        }
        solve();
    }
    
    return 0;
}