/*
 * @Author: Kaizyn
 * @Date: 2020-10-10 23:57:47
 * @LastEditTime: 2020-10-11 01:12:45
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 55;

int n, p1, pi, rev;
int a[N], b[N];
vector<int> vec[N];

void print(int t) {
  cout << t-1 << endl;
  for (int i = 1; i < t; ++i) {
    vector<int> &r = vec[i];
    cout << r.size()-1;
    for (int i = 1; i < (int)r.size(); ++i) cout << " " << r[i]-r[i-1];
    cout << endl;
  }
}

void magic(int t) {
  vector<int> &r = vec[t];
  int i = 1;
  r.emplace_back(n+1);
  for (int j = (int)r.size()-2; j >= 0; --j) {
    for (int k = r[j]; k < r[j+1]; ++k) {
      b[i++] = a[k];
    }
  }
  memcpy(a+1, b+1, sizeof(int)*n);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] == 1) p1 = i;
  }
  for (int i = 2; i <= n; ++i) {
    vector<int> &r = vec[i-1];
    r.clear();
    r.emplace_back(1);
    p1 = n;
    for (int j = 1; j <= n; ++j) {
      if (a[j] == i) pi = j;
      if (a[j] < i) p1 = min(p1, j);
    }
    if (pi < p1 && !rev) {
      if (pi > 1) r.emplace_back(pi);
      r.emplace_back(p1);
      if (p1+i-1 <= n) r.emplace_back(p1+i-1);
    } else if (pi > p1 && !rev) {
      if (p1 > 1) r.emplace_back(p1);
      for (int j = 1; j < i; ++j) {
        if (p1+j > 1) r.emplace_back(p1+j);
      }
      if (pi < n) r.emplace_back(pi+1);
      rev = 1;
    } else if (pi < p1 && rev) {
      if (pi > 1) r.emplace_back(pi);
      for (int j = 0; j <= i-2; ++j) {
        r.emplace_back(p1+j);
      }
      if (p1+i-1 <= n) r.emplace_back(p1+i-1);
      rev = 0;
    } else if (pi > p1 && rev) {
      if (p1 > 1) r.emplace_back(p1);
      r.emplace_back(p1+i-1);
      if (pi < n) r.emplace_back(pi+1);
    }
    magic(i-1);
    #ifdef DEBUG
    cout << "r:";
    for (int &i : r) cout << i << " ";
    cout << endl << "a:";
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << endl;
    #endif
  }
  int q = n-1;
  if (a[1] != 1) {
    for (int i = 1; i <= n; ++i) vec[n].emplace_back(i);
    magic(n);
    ++q;
  }
  print(q+1);
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