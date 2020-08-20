/*
 * @Author: Kaizyn
 * @Date: 2020-08-13 14:27:01
 * @LastEditTime: 2020-08-13 20:44:17
 */
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n, m, L, R;
int a[N], sum[N], dp[N];
int head[N];
vector<pii> q[N];

struct seg{
  typedef int ll;
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
	#define U(a,b) max(a,b) //查询操作
	ll a0=-INF; //查询操作的零元
	int n; ll a[1024*1024*3]; //内存等于2^k且大于等于两倍inn
	void init(int inn){ //建树
		for(n=1;n<=inn;n<<=1);
		repeat(i,0,n)a[n+i]=-INF;
		repeat_back(i,1,n)up(i);
	}
	void up(int x){
		a[x]=U(a[x<<1],a[(x<<1)^1]);
	}
	void update(int x,ll k){ //位置x加上k
		a[x+=n]=k; //也可以赋值等操作
		while(x>>=1)up(x);
	}
	ll query(int l,int r){ //区间查询
		ll ans=a0;
		for(l+=n-1,r+=n+1;l^r^1;l>>=1,r>>=1){
			if(~l & 1)ans=U(ans,a[l^1]); //l^1其实是l+1
			if(r & 1)ans=U(ans,a[r^1]); //r^1其实是r-1
		}
		return ans;
	}
}tr;

void my_add(const int &x, const int &val, const int &t) {
  while (head[x] < (int)q[x].size() && q[x].back().first <= val) q[x].pop_back();
  q[x].push_back({val, t});
  if (q[x].size()-head[x] == 1) tr.update(x, val);
}

void my_del(const int &x, const int &t) {
  while (head[x] < (int)q[x].size() && q[x][head[x]].second <= t) ++head[x];
  tr.update(x, (head[x] < (int)q[x].size() ? q[x][head[x]].first : -INF));
}

inline int solve() {
#define magic(x) (1+x-l)
  scanf("%d %d %d", &n, &L, &R);
  int l = 0, r = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a+i);
    sum[i] = sum[i-1]+a[i];
    l = min(l, sum[i]);
    r = max(r, sum[i]);
    dp[i] = -INF;
  }
  // if (L == 1 && R == 1) return sum[n];

  // [l, r] ==> [1, 1+r-l]
  m = 1+r-l;
  tr.init(m);
  dp[0] = 0;
  // add sum=0, dp=0
  for (int i = 1; i <= n; ++i) {
    if (i-L >= 0) my_add(magic(sum[i-L]), dp[i-L], i-L);
    if (i-R-1 >= 0) my_del(magic(sum[i-R-1]), i-R-1);
    dp[i] = max(dp[i], tr.query(magic(sum[i]), magic(sum[i])));
    if (sum[i] > l) dp[i] = max(dp[i], tr.query(1, magic(sum[i])-1)+1);
    if (sum[i] < r) dp[i] = max(dp[i], tr.query(magic(sum[i])+1, m)-1);
  }
  return dp[n];
#undef magic
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("%d\n", solve());
    for (int i = 1; i <= m; ++i) {
      vector<pii>().swap(q[i]);
      head[i] = 0;
    }
  }
  return 0;
}