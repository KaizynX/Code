/*
 * @Author: Kaizyn
 * @Date: 2021-01-06 20:48:01
 * @LastEditTime: 2021-04-15 20:49:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int n,m,rt[maxn],trnum;
ll g,L;
struct node{
  int d,p,l;
  bool operator<(const node b)const{
    return d<b.d;
  }
}a[maxn];
struct PST{
  int ls,rs;
  ll num,sum;
}tree[maxn<<5];
void update(int &now,int lst,int x,int Num,int l=1,int r=100000){
  now=++trnum;
  tree[now]=tree[lst];tree[now].num+=Num;tree[now].sum+=1ll*Num*x;
  if (l==r)return;
  int mid=(l+r)>>1;
  if (x<=mid)update(tree[now].ls,tree[lst].ls,x,Num,l,mid);
  else update(tree[now].rs,tree[lst].rs,x,Num,mid+1,r);
}
ll query(int L,int R,ll k,int l=1,int r=100000){
  if (l==r)return 1ll*k*(tree[R].sum-tree[L].sum)/(tree[R].num-tree[L].num);
  int mid=(l+r)>>1;
  ll res=tree[tree[R].ls].num-tree[tree[L].ls].num;
  if (res<k)return tree[tree[R].ls].sum-tree[tree[L].ls].sum+query(tree[L].rs,tree[R].rs,k-res,mid+1,r);
  else if (res==k) return tree[tree[R].ls].sum-tree[tree[L].ls].sum;
  else return query(tree[L].ls,tree[R].ls,k,l,mid);
}
bool check(int x){
  return query(x-1,n,L)<=g;
}
int main(){
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
      scanf("%d%d%d",&a[i].d,&a[i].p,&a[i].l);
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)update(rt[i],rt[i-1],a[i].p,a[i].l);
    while (m--){
      scanf("%lld%lld",&g,&L);
      int l=1,r=n;
      while (l<=r){
        int mid=(l+r)>>1;
        if (check(mid))l=mid+1;
        else r=mid-1;
      }
      if (r==0)puts("-1");
      else printf("%d\n",a[r].d);
    }
  return 0;
}
/*
3 4
1 3 5
2 1 3
3 2 5
6 3
5 3
10 10
20 10
*/