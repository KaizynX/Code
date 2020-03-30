/*********************************************
    Problem : UVALive 5070
    Author  : NMfloat
    InkTime (c) NM . All Rights Reserved .
********************************************/

#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define rep(i,a,b)  for(int i = (a) ; i <= (b) ; i ++) //遍历
#define rrep(i,a,b) for(int i = (b) ; i >= (a) ; i --) //反向遍历
#define repS(it,p) for(auto it = p.begin() ; it != p.end() ; it ++) //遍历一个STL容器
#define repE(p,u) for(Edge * p = G[u].first ; p ; p = p -> next) //遍历u所连接的点
#define cls(a,x)   memset(a,x,sizeof(a))
#define eps 1e-8

using namespace std;

const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5+5;
const int MAXE = 2e5+5;

typedef long long LL;
typedef unsigned long long ULL;

int T,n,m,d;

int fx[] = {0,1,-1,0,0};
int fy[] = {0,0,0,-1,1};

int a[700][700]; 
int x[700];
int ans[700]; int equ;
bool vis[26][26];

int tr(int x,int y) {
    return (x-1) * m + y;
}

bool gauss() {// 0代表无解，1代表有解
    rep(i,1,equ) {
        int maxd = 0; 
        rep(j,i,equ) if(a[j][i]) { maxd = j; break;}
        if(!maxd) continue;
        if(maxd != i) {
            rep(j,i,equ) swap(a[maxd][j],a[i][j]);
            swap(x[maxd],x[i]);
        }
        rep(j,1,equ) { 
            if(j == i) continue;
            if(!a[j][i]) continue;
            rep(k,i,equ) {
                a[j][k] ^= a[i][k];
            }
            x[j] ^= x[i];
        }
    }
    rep(i,1,equ) {
        if(a[i][i] == 0 && x[i]) return false;
    }
    // debug();
    return true;
}

void input() {
    rep(i,1,n) rep(j,1,m) scanf("%d",&x[tr(i,j)]);
}

void solve() {
    //列方程
    cls(a,0);

    rep(i,1,n) rep(j,1,m) {
        //曼哈顿距离为d的都会对(i,j)造成影响
        a[tr(i,j)][tr(i,j)] = 1;
        rep(ia,1,n) rep(ib,1,m) {
            if(abs(i-ia)+abs(j-ib) == d) a[tr(i,j)][tr(ia,ib)] = 1; 
        }
    }
    equ = tr(n,m);
    for (int i = 1; i <= n*m; ++i) {
        for (int j = 1; j <= n*m; ++j) {
            cout << a[i][j] << " ";
        }
        cout << x[i] << endl;
    }
    printf("%d\n",gauss());
    // render();
}

int main(void) {
    //freopen("a.in","r",stdin);
    while(scanf("%d %d %d",&m,&n,&d),n+m+d) {
        input();
        solve();
    }
    return 0;
}