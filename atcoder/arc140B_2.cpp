/*
 * @Author: Kaizyn
 * @Date: 2022-05-15 20:26:21
 * @LastEditTime: 2022-05-15 21:45:56
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

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

int n;
int l[N], r[N];
char s[N];
deque<int> q;

inline void solve() {
  cin >> n >> (s + 1);
  r[0] = 1;
  l[n + 1] = n;
  for (int i = 1; i <= n; ++i) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  int ans = 0;
  for (int i = n - 2; i; --i) {
    int j = r[i], k = r[j];
    if (j > n || k > n) continue;
    if (s[i] == 'A' && s[j] == 'R' && s[k] == 'C') {
      if (i & 1) {
        q.push_front(i);
      } else {
        s[i] = 'R';
        // del j,k
        r[i] = r[k];
        l[r[k]] = i;
        ++ans;
      }
    }
  }
  while (q.size()) {
    ++ans;
    q.pop_front();
    deque<int> qq;
    while (q.size()) {
      int i = q.back();
      q.pop_back();
      int j = r[i], k = r[j];
      s[i] = 'R';
      r[i] = r[k];
      l[r[k]] = i;
      ++ans;
      if (l[i] >= 1 && s[l[i]] == 'A' && r[i] <= n && s[r[i]] == 'C') {
        qq.push_front(l[i]);
      } 
    }
    swap(q, qq);
  }
  cout << ans << '\n';
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
9
ARCCAARCC
13
ARCCAAAARCCCC
11
AAAAARCCCCC
9
AAAARCCCC
*/