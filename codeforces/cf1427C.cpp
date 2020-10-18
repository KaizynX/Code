/*
 * @Author: Kaizyn
 * @Date: 2020-10-10 22:48:36
 * @LastEditTime: 2020-10-10 23:35:08
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int M = 5e2+7;

namespace TTT {
const int INF = 0x3f3f3f3f;
const int N = 1024 + 5;
ll MAX[N << 2][N << 2], minV, maxV,MIN[N<<2][N<<2];//维护最值
ll a[N<<2][N<<2];//初始矩阵
ll SUM[N<<2][N<<2],sumV;//维护求和
int n;
void pushupX(int deep, int rt)
{
    MAX[deep][rt] = max(MAX[deep << 1][rt], MAX[deep << 1 | 1][rt]);
    MIN[deep][rt] = min(MIN[deep << 1][rt], MIN[deep << 1 | 1][rt]);
    SUM[deep][rt] = SUM[deep<<1][rt]+SUM[deep<<1|1][rt];
}
void pushupY(int deep, int rt)
{
    MAX[deep][rt] = max(MAX[deep][rt << 1], MAX[deep][rt << 1 | 1]);
    MIN[deep][rt] = min(MIN[deep][rt << 1], MIN[deep][rt << 1 | 1]);
    SUM[deep][rt]=SUM[deep][rt<<1]+SUM[deep][rt<<1|1];
}
void buildY(int ly, int ry, int deep, int rt, int flag)
{
    //y轴范围ly,ry;deep,rt;标记flag
    if (ly == ry){
        if (flag!=-1)
            MAX[deep][rt] = MIN[deep][rt] = SUM[deep][rt] = a[flag][ly];
        else
            pushupX(deep, rt);
        return;
    }
    int m = (ly + ry) >> 1;
    buildY(ly, m, deep, rt << 1, flag);
    buildY(m + 1, ry, deep, rt << 1 | 1, flag);
    pushupY(deep, rt);
}
void buildX(int lx, int rx, int deep)
{
    //建树x轴范围lx,rx;deep
    if (lx == rx){
        buildY(1, n, deep, 1, lx);
        return;
    }
    int m = (lx + rx) >> 1;
    buildX(lx, m, deep << 1);
    buildX(m + 1, rx, deep << 1 | 1);
    buildY(1, n, deep, 1, -1);
}
void updateY(int Y, int val, int ly, int ry, int deep, int rt, int flag)
{
    //单点更新y坐标;更新值val;当前操作y的范围ly,ry;deep,rt;标记flag
    if (ly == ry){
        if (flag) //注意读清楚题意，看是单点修改值还是单点加值
            MAX[deep][rt] = MIN[deep][rt] = SUM[deep][rt] = val;
        else pushupX(deep, rt);
        return;
    }
    int m = (ly + ry) >> 1;
    if (Y <= m)
        updateY(Y, val, ly, m, deep, rt << 1, flag);
    else
        updateY(Y, val, m + 1, ry, deep, rt << 1 | 1, flag);
    pushupY(deep, rt);
}
void updateX(int X, int Y, int val, int lx, int rx, int deep)
{
    //单点更新范围x,y;更新值val;当前操作x的范围lx,rx;deep
    if (lx == rx){
        updateY(Y, val, 1, n, deep, 1, 1);
        return;
    }
    int m = (lx + rx) >> 1;
    if (X <= m)
        updateX(X, Y, val, lx, m, deep << 1);
    else
        updateX(X, Y, val, m + 1, rx, deep << 1 | 1);
    updateY(Y, val, 1, n, deep, 1, 0);
}
void queryY(int Yl, int Yr, int ly, int ry, int deep, int rt)
{
    //询问区间y轴范围y1,y2;当前操作y的范围ly,ry;deep,rt
    if (Yl <= ly && ry <= Yr)
    {
        minV = min(MIN[deep][rt], minV);
        maxV = max(MAX[deep][rt], maxV);
        sumV += SUM[deep][rt];
        return;
    }
    int m = (ly + ry) >> 1;
    if (Yl <= m)
        queryY(Yl, Yr, ly, m, deep, rt << 1);
    if (m < Yr)
        queryY(Yl, Yr, m + 1, ry, deep, rt << 1 | 1);
}
void queryX(int Xl, int Xr, int Yl, int Yr, int lx, int rx, int rt)
{
    //询问区间范围x1,x2,y1,y2;当前操作x的范围lx,rx;rt
    if (Xl <= lx && rx <= Xr){
        queryY(Yl, Yr, 1, n, rt, 1);
        return;
    }
    int m = (lx + rx) >> 1;
    if (Xl <= m)
        queryX(Xl, Xr, Yl, Yr, lx, m, rt << 1);
    if (m < Xr)
        queryX(Xl, Xr, Yl, Yr, m + 1, rx, rt << 1 | 1);
}
}

int R, n;
int t[N], x[N], y[N], dp[N];

inline void solve() {
  cin >> R >> n;
  // (x, y) -> (x+y, x-y)
  // (R, R) -> (2R, -R,R)
  for (int i = 1; i <= n; ++i) {
    cin >> t[i] >> x[i] >> y[i];
    x[i] += y[i];
    y[i] = x[i]-y[i]-y[i]+R;
  }
  for (int i = 1; i <= 2*R; ++i) {
    for (int j = 1; j <= 2*R; ++j) {
      TTT::a[i][j] = -INF;
    }
  }
  TTT::a[1][1] = 0;
  TTT::buildX(1, 2*R, 1);
  for (int i = 1; i <= n; ++i) {
    int dt = t[i]-t[i-1],
        lx = max(x[i]-dt, 1),
        rx = min(x[i]+dt, 2*R),
        ly = max(y[i]-dt, 1),
        ry = min(y[i]+dt, 2*R);
     TTT::queryX(x1,x2,y1,y2,1,n,1);
     cout << TTT::maxv << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}