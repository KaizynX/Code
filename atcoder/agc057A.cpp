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
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
// const int N = ;


inline ll solve(ll L, ll R) {
  ll b = 1;
  // if (R <= 10) return R - L + 1;
  while (b * 10 <= R) b *= 10;
  ll c = b / 10;
  if (R / b == 1) {
    // if (b == 10) return min(10ll, R - L + 1);
    return R - max({L, R - b + 1, c + 1, R / 10 + 1}) + 1;
  } else {
    return R - max(b, L) + 1;
  }
}

int brute(int L, int R) {
  vector<string> vec;
  for (int i = R; i >= L; --i) {
    string s = to_string(i);
    int flag = 1;
    for (auto &t : vec) {
      if (t.find(s) != t.npos) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      vec.emplace_back(move(s));
    } else {
      break;
    }
  }
  // for (auto &i : vec) cout << i << ' ';
  return vec.size();
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    ll L, R;
    cin >> L >> R;
    cout << solve(L, R) << '\n';
  }
  /*
  while (true) {
    int l = rnd() % 10000 + 1, r = rnd() % 10000 + 1;
    if (l > r) swap(l, r);
  */
  /*
  for (int l = 1; l <= 1; ++l)
  for (int r = 1; r <= 10000; ++r) {
    auto a1 = solve(l, r);
    auto a2 = brute(l, r);
    if (a1 != a2) {
      cout << l << ' ' << r << ' ' << a1 << ' ' << a2 << '\n';
      // return 0;
    } else {
      // cout << "ok\n";
    }
  }
  */
  return 0;
}
/*
1 110 100 99
R = [1010, 1110], [10010, 11110]
*/