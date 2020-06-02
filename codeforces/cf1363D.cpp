/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 22:29:59
 * @LastEditTime: 2020-06-01 00:33:13
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n, k;
int c[N], res[N], vis[N];
vector<int> s[N];

int query(const int &l, const int &r) {
  static int x;
  cout << "? " << r-l+1 << " ";
  for (int i = l; i <= r; ++i) cout << i << " ";
  cout << endl; // cout.flush();
  cin >> x;
  if (x == -1) exit(0);
  return x;
}

inline bool answer() {
  static string check;
  cout << "! ";
  for (int i = 1; i <= k; ++i) cout << res[i] << " ";
  cout << endl; // cout.flush();
  cin >> check;
  return check == "Correct";
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> c[i];
    s[i].resize(c[i]);
    for (int j = 0; j < c[i]; ++j) {
      cin >> s[i][j];
    }
  }
  int mv = query(1, n);
  int l = 1, r = n;
  while (l < r) {
    int mid = (l+r)>>1;
    if (query(l, mid) == mv) r = mid;
    else l = mid+1;
  }
  for (int i = 1, flag; i <= k; ++i) {
    flag = 0;
    for (int j = 0; j < c[i]; ++j) {
      if (s[i][j] == l) flag = 1;
    }
    if (flag) {
      memset(vis+1, 0, sizeof(int)*n);
      for (int j = 0; j < c[i]; ++j) vis[s[i][j]] = 1;
      cout << "? " << n-c[i] << " ";
      for (int j = 1; j <= n; ++j) {
        if (!vis[j]) cout << j << " ";
      }
      cout << endl; // cout.flush();
      cin >> res[i];
    } else {
      res[i] = mv;
    }
  }
  if (!answer()) exit(0);
  for (int i = 1; i <= k; ++i) {
    vector<int>().swap(s[i]);
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}