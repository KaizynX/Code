/*
 * @Author: Kaizyn
 * @Date: 2022-06-04 19:31:25
 * @LastEditTime: 2022-06-05 00:42:13
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
// template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e5 + 7;
const int S = 20220605;

int n, m, Q, block;
int A[N], B[N], a[N], b[N], c[N], d[N];
vector<pii> q;
unordered_map<int, int> cntA, cntB;
map<pii, ll> num;

inline unsigned long long xorshift128(){
  static unsigned __int128 SX=335634763,SY=873658265,SZ=192849106,SW=746126501;
  unsigned __int128 t=SX^(SX<<11);
  SX=SY;
  SY=SZ;
  SZ=SW;
  return SW=SW^(SW>>19)^t^(t>>8);
}
inline unsigned long long myrand(){return (xorshift128()<<32)^xorshift128();}
int f(int n){
  return myrand()%(myrand()%n+1)+1;
}
void gen(){
  for(int i=1;i<=Q;i++){
    a[i]=f(n),b[i]=n+1-f(n);
    c[i]=f(m),d[i]=m+1-f(m);
    if(a[i]>b[i])swap(a[i],b[i]);
    if(c[i]>d[i])swap(c[i],d[i]);
  }
}

bool cmp(const pii &q1, const pii &q2) {
  return q1.first/block != q2.first/block ? q1.first < q2.first :
      (q1.first/block)&1 ? q1.second < q2.second : q1.second > q2.second;
}

int my_query(const unordered_map<int, int> &cnt, int val) {
  auto it = cnt.find(val);
  return it == cnt.end() ? 0 : it->second;
}

inline void solve() {
  cin >> n >> m >> Q;
  q.clear();
  num.clear();
  cntA.clear();
  cntB.clear();
  // block = sqrt(Q) + 1;
  block = 333;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  for (int i = 1; i <= m; ++i) cin >> B[i];
  gen();
  for (int i = 1; i <= Q; ++i) {
    // cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i];
    --c[i];
    q.emplace_back(pii{a[i], c[i]});
    q.emplace_back(pii{a[i], d[i]});
    q.emplace_back(pii{b[i], c[i]});
    q.emplace_back(pii{b[i], d[i]});
  }
  sort(q.begin(), q.end(), cmp);
  int ai = 0, bi = 0;
  ll sum = 0;
  for (auto &pr : q) {
    int l = pr.first;
    int r = pr.second;
    while (ai < l) {
      ++ai;
      // sum += cntB[S - A[ai]];
      sum += my_query(cntB, S - A[ai]);
      cntA[A[ai]]++;
    }
    while (ai > l) {
      // sum -= cntB[S - A[ai]];
      sum -= my_query(cntB, S - A[ai]);
      cntA[A[ai]]--;
      --ai;
    }
    while (bi < r) {
      ++bi;
      // sum += cntA[S - B[bi]];
      sum += my_query(cntA, S - B[bi]);
      cntB[B[bi]]++;
    }
    while (bi > r) {
      // sum -= cntA[S - B[bi]];
      sum -= my_query(cntA, S - B[bi]);
      cntB[B[bi]]--;
      --bi;
    }
    num[{l, r}] = sum;
  }
  for (int i = 1; i <= Q; ++i) {
    cout << num[{b[i], d[i]}] - num[{a[i], d[i]}] - num[{b[i], c[i]}] + num[{a[i], c[i]}] << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}