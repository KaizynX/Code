/*
 * @Author: Kaizyn
 * @Date: 2021-01-16 21:16:23
 * @LastEditTime: 2021-01-16 21:28:46
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 21;

int n;
int a[N][N][2];
vector<int> vec;

void init(int n, int k) {
  vec.clear();
  int s=(1<<k)-1;
  while(s<(1<<n)){
    vec.emplace_back(s);
    int x=s&-s,y=s+x;
    s=((s&~y)/x>>1)|y; //这里有一个位反~
  }
}

void print(int b) {
  cout << __builtin_popcount(b) << endl;
  for (int k = 0; k < (int)vec.size(); ++k) if ((b>>k)&1) {
    for (int i = 0; i < n; ++i) cout << (((vec[k]>>i)&1) ? 'B' : 'A') << endl;
  }
}

inline void solve() {
  cin >> n;
  n = 1<<n;
  init(n, n/2);
  for (int b = 1; b < 1<<vec.size(); ++b) {
    memset(a, 0, sizeof a);
    for (int k = 0; k < (int)vec.size(); ++k) if ((b>>k)&1) {
      for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) {
        ++a[i][j][((vec[k]>>i)^(vec[k]>>j))&1];
      }
    }
    int v0 = a[1][2][0], v1 = a[1][2][1], flag = 1;
    for (int i = 0; i < n; ++i) for (int j = i+1; j < n; ++j) {
      flag &= (v0 == a[i][j][0]) && (v1 == a[i][j][1]);
    }
    if (flag) print(b);
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}