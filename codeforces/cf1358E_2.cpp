/*
 * @Author: Kaizyn
 * @Date: 2020-05-27 00:04:52
 * @LastEditTime: 2020-05-27 21:17:01
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e18;
const int N = 5e5+7;

int n, x;
int a[N], b[N];
long long sum[N];
multiset<long long> st;

inline solve() {
  cin >> n;
  int m = (n+1)/2;
  for (int i = 1; i <= m; ++i) cin >> a[i];
  cin >> x;

  reverse(a+1, a+m);
  for (int i = 1; i < m; ++i) {
    b[i] = a[i]-x;
    sum[i] = sum[i-1]+b[i];
    st.insert(sum[i]);
  }
  long long cur = 1ll*x*(n/2)+a[m], base = 0;
  for (int i = 1; i < m; ++i) {
    if (cur > 0 && cur+*st.begin()+base > 0) return n/2+i;
    cur += a[i];
    base -= b[i];
    st.erase(st.find(sum[i]));
  }
  if (cur > 0) return n;
  return -1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}