#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;
int a[N];
vector<int> p;

void build(int i) {
  if (i > n) return;
  build(i<<1);
  build(i<<1|1);
  p.emplace_back(i);
}

void solve() {
  p.clear();
  build(1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[p[i-1]];
  }
  for (int i = 1; i <= n; ++i) {
    cout << a[i] << " \n"[i==n];
  }
}

signed main() {
  while (cin >> n) solve();
  return 0;
}