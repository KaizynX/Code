/*
 * @Author: Kaizyn
 * @Date: 2021-02-25 15:09:24
 * @LastEditTime: 2021-02-25 16:39:56
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

int n;

struct node{
  int x,y,v;
}s[N];
bool cmp1(int a,int b){return s[a].x<s[b].x;}
bool cmp2(int a,int b){return s[a].y<s[b].y;}

struct KDTree{
  int rt,cur; //rt根结点
  int d[N],sz[N],lc[N],rc[N]; //d=1竖着砍，sz子树大小
  int L[N],R[N],D[N],U[N]; //该子树的界线
  int sum[N]; //维护的二维区间信息（二维区间和）
  int g[N],gt;
  void push_up(int x){ //更新信息
    sz[x]=sz[lc[x]]+sz[rc[x]]+1;
    sum[x]=sum[lc[x]]+sum[rc[x]]+s[x].v;
    L[x]=R[x]=s[x].x;
    D[x]=U[x]=s[x].y;
    if(lc[x]){
      L[x]=min(L[x],L[lc[x]]);
      R[x]=max(R[x],R[lc[x]]);
      D[x]=min(D[x],D[lc[x]]);
      U[x]=max(U[x],U[lc[x]]);
    }
    if(rc[x]){
      L[x]=min(L[x],L[rc[x]]);
      R[x]=max(R[x],R[rc[x]]);
      D[x]=min(D[x],D[rc[x]]);
      U[x]=max(U[x],U[rc[x]]);
    }
  }
  int build(int l,int r){ //以序列g[l..r]为模板重建树，返回根结点
    if(l>r)return 0;
    int mid=(l+r)>>1;
    double ax=0,ay=0,sx=0,sy=0;
    for(int i=l;i<=r;i++)ax+=s[g[i]].x,ay+=s[g[i]].y;
    ax/=(r-l+1);
    ay/=(r-l+1);
    for(int i=l;i<=r;i++){
      sx+=(ax-s[g[i]].x)*(ax-s[g[i]].x);
      sy+=(ay-s[g[i]].y)*(ay-s[g[i]].y);
    }
    if(sx>sy)
      nth_element(g+l,g+mid,g+r+1,cmp1),d[g[mid]]=1;
    else
      nth_element(g+l,g+mid,g+r+1,cmp2),d[g[mid]]=2;
    lc[g[mid]]=build(l,mid-1);
    rc[g[mid]]=build(mid+1,r);
    push_up(g[mid]);
    return g[mid];
  }
  void pia(int x){ //将树还原成序列g
    if(!x)return;
    pia(lc[x]);
    g[++gt]=x;
    pia(rc[x]);
  }
  void ins(int &x,int v){
    if (!x) return push_up(x = v);
    d[x] ? ins(s[v].x <= s[x].x ? lc[x] : rc[x], v)
         : ins(s[v].y <= s[x].y ? lc[x] : rc[x], v);
    push_up(x);
    if(0.725*sz[x]<=max(sz[lc[x]],sz[rc[x]])){
      gt=0;
      pia(x);
      x=build(1,gt);
    }
  }
  void insert(int x,int y,int v){ //在(x,y)处插入元素
    s[++cur]={x,y,v};
    ins(rt,cur);
  }
  int x1,x2,y1,y2;
  int qry(int x){
    if(!x || x2<L[x] || x1>R[x] || y2<D[x] || y1>U[x])return 0;
    if(x1<=L[x] && R[x]<=x2 && y1<=D[x] && U[x]<=y2)return sum[x];
    int ret=0;
    if(x1<=s[x].x && s[x].x<=x2 && y1<=s[x].y && s[x].y<=y2)
      ret+=s[x].v;
    return qry(lc[x])+qry(rc[x])+ret;
  }
  int query(int _x1,int _x2,int _y1,int _y2){ //查询[x1,x2]×[y1,y2]的区间和
    x1=_x1; x2=_x2; y1=_y1; y2=_y2;
    return qry(rt);
  }
  void init(){
    rt=cur=0;
  }
};

KDTree kdt;

signed main() {
  scanf("%d", &n);
  kdt.init();
  for (int op, a, b, c, d, ans = 0; ; ) {
    scanf("%d", &op);
    if (op == 3) break;
    if (op == 1) {
      scanf("%d%d%d", &a, &b, &c);
      kdt.insert(a^ans, b^ans, c^ans);
    } else {
      scanf("%d%d%d%d", &a, &b, &c, &d);
      printf("%d\n", ans = kdt.query(a^ans, b^ans, c^ans, d^ans));
    }
  }
  return 0;
}