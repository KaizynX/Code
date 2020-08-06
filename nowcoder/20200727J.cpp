/*
 * @Author: Kaizyn
 * @Date: 2020-07-27 15:13:57
 * @LastEditTime: 2020-07-27 15:50:38
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
  void add(const int &x, const T &v) { for (int i = x ; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, m;
int a[N], trans[N];
BinaryIndexedTree<int> BIT;

inline void get_trans(int n, int k, int *trans) {
  BIT.init(n*2);
  trans[0] = k-1;
  BIT.add(k, 1); BIT.add(k+n, 1);
  for (int i = 1, cur = k-1; i < n; ++i) {
    int l = cur, r = cur+n-1, mid, step = k%(n-i) == 0 ? n-i : k%(n-i);
    while (l < r) {
      mid = (l+r)>>1;
      if (mid-cur+1-BIT.query(cur+1, mid+1) >= step) r = mid;
      else l = mid+1;
    }
    trans[i] = cur = l%n;
    BIT.add(cur+1, 1); BIT.add(cur+n+1, 1);
  }
  #ifdef DEBUG
  // for (int i = 0; i < n; ++i) printf("%d%c", trans[i]+1," \n"[i==n-1]);
  #endif
}

void qpow(int a[],int n,int x){
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
	static int rec[N],c[N];
	static bool vis[N];
	fill(vis,vis+n,0); 
	repeat(i,0,n)if(!vis[i]){
		int cnt=0; rec[cnt++]=i;
		for(int p=a[i];p!=i;p=a[p])
			rec[cnt++]=p,vis[p]=1;
		repeat(J,0,cnt)
			c[rec[J]]=a[rec[(J+x-1)%cnt]];
		repeat(J,0,cnt)
			a[rec[J]]=c[rec[J]];
	}
}

void fuck(int *a, int *trans) {
  static int b[N];
  for (int i = 0; i < n; ++i) b[i] = a[i];
  for (int i = 0; i < n; ++i) a[i] = b[trans[i]];
}

inline void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) a[i] = i;
  for (int mm = 1, k, x; mm <= m; ++mm) {
    cin >> k >> x;
    get_trans(n, k, trans);
    qpow(trans, n, x);
    fuck(a, trans);
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i]+1 << " \n"[i==n-1];
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