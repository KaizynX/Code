/*
 * @Author: Kaizyn
 * @Date: 2020-09-02 20:29:22
 * @LastEditTime: 2020-09-03 11:38:46
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
const int M = 9592;

template <typename T> inline int miu(T x) {
  int t = 0;
  for (T i = 2; i*i <= x; ++i) if (x%i == 0) {
    ++t;
    x /= i;
    if (x%i == 0) return 0;
  }
  if (x > 1) ++t;
  return t&1 ? -1 : 1;
}

int n, q;
int a[N];
map<int, int> mp;

struct Euler {
  int tot = 0;
  int prime[N];
  bool check[N];
  bool& operator [] (const int i) { return check[i]; }
  void init(int sz) {
    tot = 0;
    for (int i = 1; i <= sz; ++i) check[i] = true;
    check[1] = false;
    for (int i = 2, j; i <= sz; ++i) {
      if (check[i]) mp[i] = tot, prime[++tot] = i;
      for (j = 1; j <= tot && i*prime[j] <= sz; ++j) {
        check[i*prime[j]] = false;
        if (i%prime[j] == 0) break;
      }
    }
  }
} E;

struct seg{
  typedef int ll;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
  static const int SZ = (1<<18);
  int n; //内存等于2^k且大于等于两倍inn
  long long sum[SZ];
  int id[SZ];
  bitset<M> b[SZ];
  int fuck(int x) {
    b[x].reset();
    int y = a[x];
    for (int i = 2; i*i <= y; ++i) {
      if (y%i) continue;
      y /= i;
      if (y%i == 0) return -1;
      b[x][mp[i]] = 1;
    }
    if (y > 1) b[x][mp[y]] = 1;
    return x;
  }
  void build(int inn){ //建树
    for(n=1;n<=inn;n<<=1);
    memset(id, -1, sizeof id);
    for (int i = 1; i <= inn; ++i) {
      id[n+i] = fuck(i);
      sum[n+i] = a[i];
    }
    for (int i = n-1; i; --i) up(i);
  }
  void U(int &x, int y, int z) {
    if (z == -1 || y == -1 || (b[y]&b[z]).any()) return x = -1, void();
    b[x] = b[y]|b[z];
  }
  void up(int x){
    sum[x] = sum[x<<1]+sum[x<<1|1];
    U(id[x] = x, id[x<<1], id[x<<1|1]);
  }
  void update(int x){ //位置x加上k
    id[x+n]=fuck(x); //也可以赋值等操作
    sum[x+n] = a[x];
    x += n;
    while(x>>=1)up(x);
  }
  long long query1(int l,int r){ //区间查询
    long long ans=0;
    for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1){
        if(~l & 1)ans += sum[l^1]; //l^1其实是l+1
        if(r & 1)ans += sum[r^1]; //r^1其实是r-1
    }
    return ans;
  }
  int query2(int l,int r){ //区间查询
    int ans=0;
    b[0].reset();
    for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1){
        if(~l & 1)U(ans, ans, id[l^1]); //l^1其实是l+1
        if(r & 1)U(ans, ans, id[r^1]); //r^1其实是r-1
    }
    return ans;
  }
#undef repeat
#undef repeat_back
}seg;


signed main() {
  E.init(100000);
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  seg.build(n);
  for (int i = 1, op, l, r; i <= q; ++i) {
    scanf("%d %d %d", &op, &l, &r);
    if (op == 1) {
      a[l] = r;
      seg.update(l);
    } else if (op == 2) {
      printf("%d\n", miu(seg.query1(l, r)));
    } else if (op == 3) {
      int res = seg.query2(l, r);
      if (res == -1) puts("0");
      else printf("%d\n", seg.b[res].count()&1 ? -1 : 1);
    }
  }
  return 0;
}