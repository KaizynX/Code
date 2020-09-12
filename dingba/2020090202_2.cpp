/*
 * @Author: Kaizyn
 * @Date: 2020-09-02 19:26:20
 * @LastEditTime: 2020-09-02 19:57:21
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;
const int M1 = 50331653;
const int M2 = 25165843;
const int P1 = 29;
const int P2 = 31;

int n;
long long ha1[N], ha2[N], hra1[N], hra2[N];
long long pw1[N], pw2[N];
char a[N], b[N];
unordered_map<long long, int> mp;

inline bool solve() {
  mp.clear();
  scanf("%d%s%s", &n, a, b);
  long long hv1 = 0, hv2 = 0;
  for (int i = 0, c; i < n; ++i) {
    c = b[i]-'a'+1;
    hv1 = (hv1*P1+c)%M1;
    hv2 = (hv2*P2+c)%M2;
  }
  for (int i = 0, c; i < n; ++i) {
    c = b[i]-'a'+1;
    hv1 = ((hv1*P1-c*pw1[n])%M1+c+M1)%M1;
    hv2 = ((hv2*P2-c*pw2[n])%M2+c+M2)%M2;
    mp[(hv1<<32)+hv2] = 1;
  }
  for (int i = 1, c; i <= n+1; ++i) {
    c = a[i-1]-'a'+1;
    ha1[i] = (ha1[i-1]*P1+c)%M1;
    ha2[i] = (ha2[i-1]*P2+c)%M2;
  }
  hra1[n+2] = hra2[n+2] = 0;
  for (int i = n+1, c; i; --i) {
    c = a[i-1]-'a'+1;
    hra1[i] = (hra1[i+1]+c*pw1[n+1-i])%M1;
    hra2[i] = (hra2[i+1]+c*pw2[n+1-i])%M2;
  }
  for (int i = 1; i <= n+1; ++i) {
    hv1 = (ha1[i-1]*pw1[n+1-i]+hra1[i+1])%M1;
    hv2 = (ha2[i-1]*pw2[n+1-i]+hra2[i+1])%M2;
    if (mp.count((hv1<<32)+hv2)) return true;
  }
  return false;
}

signed main() {
  pw1[0] = pw2[0] = 1;
  for (int i = 1; i < N; ++i) {
    pw1[i] = pw1[i-1]*P1%M1;
    pw2[i] = pw2[i-1]*P2%M2;
  }
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    puts(solve() ? "YES" : "NO");
  }
  return 0;
}