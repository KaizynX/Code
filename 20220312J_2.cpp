/*
 * @Author: Kaizyn
 * @Date: 2022-03-12 15:07:04
 * @LastEditTime: 2022-03-12 15:59:16
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
// const int N = ;

using arr3 = array<int, 3>;
using uint = unsigned;

int n;
vector<arr3> a[2], b[2];
constexpr int belong[2][8] = {
  {1,2,3,4,4,5,5,0},
  {1,2,2,3,3,4,4,5}
};

bool check_intesect(int i0, int i1) {
  int y = b[0][i0][0];
  int l = b[0][i0][1];
  int r = b[0][i0][2];
  int x = b[1][i1][0];
  int d = b[1][i1][1];
  int u = b[1][i1][2];
  return d <= y && y <= u && l <= x && x <= r;
}

inline bool solve() {
  cin >> n;
  for (int i = 1, op; i <= n; ++i) {
    arr3 tmp;
    cin >> op >> tmp[1] >> tmp[2] >> tmp[0];
    a[op].emplace_back(tmp);
  }
  for (int _ : {0, 1}) {
    auto &c = a[_];
    sort(c.begin(), c.end());
    for (uint i = 0, j; i < c.size(); i = j) {
      arr3 tmp = c[i];
      for (j = i + 1; j < c.size(); ++j) {
        if (c[j][0] != tmp[0]) break;
        if (c[j][1] > tmp[2]) break;
        tmp[2] = max(tmp[2], c[j][2]);
      }
      b[_].emplace_back(tmp);
    }
    #ifdef DEBUG
    orz(_);
    for (auto x : b[_]) orzeach(x);
    #endif
  }
  if (b[0].size() != 7u || b[1].size() != 8u) return false;

  int rk[2][8];
  iota(rk[0], rk[0] + 7, 0);
  do {
    int y1 = b[0][rk[0][0]][0];
    int l1 = b[0][rk[0][0]][1];
    int r1 = b[0][rk[0][0]][2];
    int y4 = b[0][rk[0][1]][0];
    int l4 = b[0][rk[0][1]][1];
    int r4 = b[0][rk[0][1]][2];
    int y7 = b[0][rk[0][2]][0];
    int l7 = b[0][rk[0][2]][1];
    int r7 = b[0][rk[0][2]][2];
    int y10 = b[0][rk[0][3]][0];
    int l10 = b[0][rk[0][3]][1];
    int r10 = b[0][rk[0][3]][2];
    int y11 = b[0][rk[0][4]][0];
    int l11 = b[0][rk[0][4]][1];
    int r11 = b[0][rk[0][4]][2];
    int y14 = b[0][rk[0][5]][0];
    int l14 = b[0][rk[0][5]][1];
    int r14 = b[0][rk[0][5]][2];
    int y15 = b[0][rk[0][6]][0];
    int l15 = b[0][rk[0][6]][1];
    int r15 = b[0][rk[0][6]][2];
    if (y11 >= y10 || !(l10 == l11 && l11 < r10 && r10 == r11) || y15 >= y14 || !(l14 == l15 && l15 <= r14 && r14 == r15)) continue;
    // if (y11 >= y10 || l10 != l11 || l11 >= r10 || r10 != r11 || y15 >= y14 || l14 != l15 || l15 >= r14 || r14 != r15) continue;
    iota(rk[1], rk[1] + 8, 0);
    do {
      int flag = 1;
      for (int i = 0; i < 7 && flag; ++i) {
        for (int j = 0; j < 8; ++j) {
          if (belong[0][i] != belong[1][j] && check_intesect(rk[0][i], rk[1][j])) {
            flag = 0;
            break;
          }
        }
      }
      if (!flag) break;
      int x2 = b[1][rk[1][0]][0];
      int d2 = b[1][rk[1][0]][1];
      int u2 = b[1][rk[1][0]][2];
      int x3 = b[1][rk[1][1]][0];
      int d3 = b[1][rk[1][1]][1];
      int u3 = b[1][rk[1][1]][2];
      int x5 = b[1][rk[1][2]][0];
      int d5 = b[1][rk[1][2]][1];
      int u5 = b[1][rk[1][2]][2];
      int x6 = b[1][rk[1][3]][0];
      int d6 = b[1][rk[1][3]][1];
      int u6 = b[1][rk[1][3]][2];
      int x8 = b[1][rk[1][4]][0];
      int d8 = b[1][rk[1][4]][1];
      int u8 = b[1][rk[1][4]][2];
      int x9 = b[1][rk[1][5]][0];
      int d9 = b[1][rk[1][5]][1];
      int u9 = b[1][rk[1][5]][2];
      int x12 = b[1][rk[1][6]][0];
      int d12 = b[1][rk[1][6]][1];
      int u12 = b[1][rk[1][6]][2];
      int x13 = b[1][rk[1][7]][0];
      int d13 = b[1][rk[1][7]][1];
      int u13 = b[1][rk[1][7]][2];
      if (d2 < y1 && y1 == u2 && l1 < x2 && x2 < r1
      && d3 == d5 && d5 < y4 && y4 < u3 && u3 == u5 && x3 == l4 && l4 < r4 && r4 == x5
      && d6 == d8 && d8 == y7 && y7 < u6 && u6 == u8 && x6 == l7 && l7 < r7 && r7 == x8
      && d9 < y11 && y11 == d12 && d12 < u9 && u9 == y10 && y10 == u12 && x9 == l10 && l10 == l11 && l11 < r10 && r10 == r11 && r11 == x12
      && d13 == y15 && y15 < u13 && u13 == y14 && x13 == l14 && l14 == l15 && l15 < r14 && r14 == r15) 
      /*
      if (d2 < y1 && y1 == u2 && l1 < x2 && x2 < r1
      && d3 == d5 && d5 < y4 && y4 < u3 && u3 == u5 && x3 == l4 && r4 == x5
      && d6 == d8 && d8 == y7 && y7 < u6 && u6 == u8 && x6 == l7 && r7 == x8
      && d9 < y11 && y11 == d12 && d12 < u9 && u9 == y10 && y10 == u12 && x9 == l10 && r11 == x12
      && d13 == y15 && y15 < u13 && u13 == y14 && x13 == l14) 
      */
      {
        return true;
      }
    } while (next_permutation(rk[1], rk[1] + 8));
  } while (next_permutation(rk[0], rk[0] + 7));
  return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}