/*
 * @Author: Kaizyn
 * @Date: 2022-05-31 23:38:06
 * @LastEditTime: 2022-06-01 00:01:12
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e5 + 7;
const int M = 4e5 + 7;

int n, m;
int sigle_red[M], sigle_blue[M];
vector<int> L[2], R[2], dis;
int add[2][M], del[2][M];

inline void solve() {
  cin >> n;
  for (int i = 1, c, l, r; i <= n; ++i) {
    cin >> c >> l >> r;
    dis.emplace_back(l);
    dis.emplace_back(r);
    L[c].emplace_back(l);
    r[c].emplace_back(r);
  }
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  m = dis.size();
  for (int _ : {0, 1}) {
    for (int &x : l[i]) {
      x = lower_bound(dis.begin(), dis.end(), x) - dis.begin() + 1;
      ++add[_][x];
    }
    for (int &x : r[i]) {
      x = lower_bound(dis.begin(), dis.end(), x) - dis.begin() + 1;
      --del[_][x + 1];
    }
  }
  int ans = l[1].size();
  for (uint i = 0; i < l[1].size(); ++i) {
    ++sigle_red[l[1][i]];
    --sigle_red[r[1][i] + 1];
  }
  for (int i = 1; i <= m; ++i) {
    sigle_red[i] += sigle_red[i - 1];
  }
  for (uint i = 0; i < l[0].size(); ++i) {
    if (sigle_red[r[0][i]] - sigle_red[l[0][i] - 1] == 0) {
      ++ans;
    }
  }
  for (int cnt0 = 0, cnt1 = 0, i = 1; i <= m; ++i) {
    cnt0 += add[0][i] - del[0][i];
    cnt1 += add[1][i] - del[1][i];
    if (cnt1 > 1 && cnt0 > 0) sigle_blue[i] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    sigle_blue[i] += sigle_blue[i - 1];
  }
  for (uint i = 0; i < l[1].size(); ++i) {
    if (sigle_red[r[0][i]] - sigle_red[l[0][i] - 1] == 0) {
      --ans;
    }
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i : {0, 1}) {
      L[i].clear();
      R[i].clear();
      for (int j = 1; j <= m + 1; ++j) {
        add[i][j] = 0;
        del[i][j] = 0;
      }
    }
    dis.clear();
  }
  return 0;
}