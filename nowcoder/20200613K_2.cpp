/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 14:17:49
 * @LastEditTime: 2020-06-13 15:13:41
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 16;

struct Point {
  typedef long long T;
  T x, y;
  Point(){}
  Point(const T &_x, const T &_y) : x(_x), y(_y) {}
  friend T operator *(const Point &p1, const Point &p2) {
    return p1.x*p2.y-p1.y*p2.x;
  }
};

int n;
int x[N], y[N], check[1<<N], sg[1<<N];

inline void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }
  // check[0] = 0;
  vector<int> vec;
  for (int i = 1; i < 1<<n; ++i) {
    vec.clear();
    for (int j = 0; j < n; ++j) if ((i>>j)&1) {
      vec.emplace_back(j);
    }
    check[i] = 1;
    if (vec.size() <= 2) continue;
    Point v1 = Point(x[vec[0]]-x[vec[1]], y[vec[0]]-y[vec[1]]), v2;
    for (int j = 2; j < (int)vec.size(); ++j) {
      v2 = Point(x[vec[0]]-x[vec[j]], y[vec[0]]-y[vec[j]]);
      if (v1*v2 != 0) check[i] = 0;
    }
  }
  sg[0] = 0;
  for (int i = 1; i < 1<<n; ++i) {
    if (check[i]) sg[i] = 1;
    for (int j = i; j; j = (j-1)&i) if (check[i^j]) {
      sg[i] |= sg[j]^1;
    }
  }
  cout << (sg[(1<<n)-1] ? "zyh" : "fzj") << endl;
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