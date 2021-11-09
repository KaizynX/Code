/*
 * @Author: Kaizyn
 * @Date: 2021-10-17 15:33:54
 * @LastEditTime: 2021-11-07 15:42:06
 */
#include <bits/stdc++.h>
 
// #define DEBUG
 
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
 
typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;
 
int n;
pii a[N];
 
bool check(int k) {
  priority_queue<pii, vector<pii>, greater<pii>> q;
  // priority_queue<pii> q;
  multiset<int> st;
  ll sumq = 0, sums = 0, flag = 0;
  for (int i = 1; i <= k; ++i) {
    q.push({a[i].first+a[i].second, i});
    sumq += a[i].first;
  }
  for (int i = k+1; i <= n; ++i) {
    st.insert(a[i].second);
    sums += a[i].second;
    if ((int)st.size() > k) {
      sums -= *--st.end();
      st.erase(--st.end());
    }
  }
  flag |= sumq >= sums;
  for (int i = k+1, j; i <= 2*k; ++i) {
    q.push({a[i].first+a[i].second, i});
    sumq += a[i].first;
    j = q.top().second;
    q.pop();
    sumq -= a[j].first;
    sums += a[j].second;
    auto it = st.find(a[i].second);
    if (it == st.end()) --it;
    sums -= *it;
    st.erase(it);
    flag |= sumq >= sums;
  }
  return flag;
}
 
inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].first;
  for (int i = 1; i <= n; ++i) cin >> a[i].second;
  sort(a+1, a+n+1);
  reverse(a+1, a+n+1);
  int l = 0, r = n/2, mid;
  #ifdef DEBUG
  for (int i=1;i<=n;i++)cout<<a[i]<<'\n';
  cout<<check(6)<<endl;
  #endif
  
  while (l < r) {
    mid = (l+r+1)/2;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << '\n';
}
 
signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
8
4 4 9 10 3 12 8 3
17 17 15 10 17 14 2 13
*/
/*
16
26 13 30 66 25 40 38 49 26 50 26 16 37 32 20 50
94 89 72 56 100 72 31 23 60 65 87 86 56 35 84 35
*/