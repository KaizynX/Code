/*
 * @Author: Kaizyn
 * @Date: 2022-03-12 11:02:47
 * @LastEditTime: 2022-03-12 15:14:50
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
const int N = 1e5 + 7;

using arr3 = array<int, 3>;
using uint = unsigned;

int n;
vector<arr3> a[2], b[2];
unordered_map<int, int> mp_log;
int used[2];

inline lowbit(int x) { return x & -x; }

int remap(int id, int bit) {
  int ans = 0;
  for (int i = 0, j = 0; i < 8; ++i, ++j) {
    if ((1<<i) > bit) break;
    while ((used[id] >> j) & 1) ++j;
    if ((bit >> j) & 1) ans |= 1 << j;
  }
  return ans;
}

bool check_intesect(int i0, int i1) {
  int y = b[0][i0][0];
  int l = b[0][i0][1];
  int r = b[0][i0][2];
  int x = b[1][i1][0];
  int d = b[1][i1][1];
  int u = b[1][i1][2];
  return d <= y && y <= u && l <= x && x <= r;
}

bool checkT(int i1, int i2) {
  int y1 = b[0][i1][0];
  int l1 = b[0][i1][1];
  int r1 = b[0][i1][2];
  int x2 = b[1][i2][0];
  int d2 = b[1][i2][1];
  int u2 = b[1][i2][2];
  return d2 < y1 && y1 == u2 && l1 < x2 && x2 < r1;
}

bool CheckT(int b0, int b1) {
  int i1 = mp_log[lowbit(b0)];
  int i2 = mp_log[lowbit(b1)];
  return checkT(i1, i2);
}

bool checkH(int i3, int i4, int i5) {
  int x3 = b[1][i3][0];
  int d3 = b[1][i3][1];
  int u3 = b[1][i3][2];
  int y4 = b[0][i4][0];
  int l4 = b[0][i4][1];
  int r4 = b[0][i4][2];
  int x5 = b[1][i5][0];
  int d5 = b[1][i5][1];
  int u5 = b[1][i5][2];
  return d3 == d5 && d5 < y4 && y4 < u3 && u3 == u5 && x3 == l4 && l4 < r4 && r4 == x5;
}

bool CheckH(int b0, int b1) {
  int i3 = mp_log[lowbit(b1)];
  b1 -= lowbit(b1);
  int i4 = mp_log[lowbit(b0)];
  int i5 = mp_log[lowbit(b1)];
  return checkH(i3, i4, i5) || checkH(i5, i4, i3);
}

bool checkU(int i6, int i7, int i8) {
  int x6 = b[1][i6][0];
  int d6 = b[1][i6][1];
  int u6 = b[1][i6][2];
  int y7 = b[0][i7][0];
  int l7 = b[0][i7][1];
  int r7 = b[0][i7][2];
  int x8 = b[1][i8][0];
  int d8 = b[1][i8][1];
  int u8 = b[1][i8][2];
  return d6 == d8 && d8 == y7 && y7 < u6 && u6 == u8 && x6 == l7 && l7 < r7 && r7 == x8;
}

bool CheckU(int b0, int b1) {
  int i3 = mp_log[lowbit(b1)];
  b1 -= lowbit(b1);
  int i4 = mp_log[lowbit(b0)];
  int i5 = mp_log[lowbit(b1)];
  return checkU(i3, i4, i5) || checkU(i5, i4, i3);
}

bool checkP(int i9, int i10, int i11, int i12) {
  int x9 = b[1][i9][0];
  int d9 = b[1][i9][1];
  int u9 = b[1][i9][2];
  int y10 = b[0][i10][0];
  int l10 = b[0][i10][1];
  int r10 = b[0][i10][2];
  int y11 = b[0][i11][0];
  int l11 = b[0][i11][1];
  int r11 = b[0][i11][2];
  int x12 = b[1][i12][0];
  int d12 = b[1][i12][1];
  int u12 = b[1][i12][2];
  return d9 < y11 && y11 == d12 && d12 < u9 && u9 == y10 && y10 == u12 && x9 == l10 && l10 == l11 && l11 < r10 && r10 == r11 && r11 == x12;
}

bool CheckP(int b0, int b1) {
  int i9 = mp_log[lowbit(b1)];
  b1 -= lowbit(b1);
  int i12 = mp_log[lowbit(b1)];
  int i10 = mp_log[lowbit(b0)];
  b0 -= lowbit(b0);
  int i11 = mp_log[lowbit(b0)];
  return checkP(i9, i10, i11, i12) || checkP(i9, i11, i10, i12)
      || checkP(i12, i10, i11, i9) || checkP(i12, i11, i10, i9);
}

bool checkC(int i13, int i14, int i15) {
  int x13 = b[1][i13][0];
  int d13 = b[1][i13][1];
  int u13 = b[1][i13][2];
  int y14 = b[0][i14][0];
  int l14 = b[0][i14][1];
  int r14 = b[0][i14][2];
  int y15 = b[0][i15][0];
  int l15 = b[0][i15][1];
  int r15 = b[0][i15][2];
  return d13 == y15 && y15 < u13 && u13 == y14 && x13 == l14 && l14 == l15 && l15 < r14 && r14 == r15;
}

bool CheckC(int b0, int b1) {
  int i13 = mp_log[lowbit(b1)];
  int i14 = mp_log[lowbit(b0)];
  b0 -= lowbit(b0);
  int i15 = mp_log[lowbit(b0)];
  return checkC(i13, i14, i15) || checkC(i13, i15, i14);
}

constexpr int need[5][2] = {
  {1, 1},
  {1, 2},
  {1, 2},
  {2, 2},
  {2, 1}
};

function<bool(int, int)> check_list[] = {
  CheckH,
  CheckT,
  CheckU,
  CheckP,
  CheckC
};

bool check(int u = 0) {
  if (u >= 5) return true;
  for(int s0 = (1 << need[u][0]) - 1; s0 < (1<<(b[0].size() - __builtin_popcount(used[0]))); ){
    int b0 = remap(0, s0);
    for(int s1 = (1 << need[u][1]) - 1; s1 < (1<<(b[1].size() - __builtin_popcount(used[1]))); ){
      int b1 = remap(1, s1);
      if (check_list[u](b0, b1)) {
        used[0] ^= b0;
        used[1] ^= b1;
        if (check(u + 1)) return true;
        used[0] ^= b0;
        used[1] ^= b1;
      }
      int x = s1 & -s1, y = s1 + x;
      s1 = ((s1&~y)/x>>1)|y; //这里有一个位反~
    }
    int x=s0&-s0,y=s0+x;
    s0=((s0&~y)/x>>1)|y; //这里有一个位反~
  }
  return false;
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
  return check();
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  for (int i = 0; i < 15; ++i) mp_log[1 << i] = i;
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}