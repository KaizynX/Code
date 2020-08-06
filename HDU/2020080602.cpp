/*
 * @Author: Kaizyn
 * @Date: 2020-08-06 12:31:36
 * @LastEditTime: 2020-08-06 12:47:30
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

int op;
string s, ls, rs, es;

int mmp(const char &ch) {
  if (ch >= '0' && ch <= '9') return ch-'0';
  else return ch-'A'+10;
}

long long s_to_l(const string &s, const int &R) {
  long long res = 0;
  for (const char &ch : s) {
    res = res*R+mmp(ch);
  }
  return res;
}

bool check(const int &R) {
  long long l = s_to_l(ls, R), r = s_to_l(rs, R), e = s_to_l(es, R);
  if (s[op] == '+') {
    return l+r == e;
  } else if (s[op] == '-') {
    return l-r == e;
  } else if (s[op] == '*') {
    // l*r == e
    if (l == 0 || r == 0) return e == 0;
    return e%r == 0 && e/r == l;
  } else if (s[op] == '/') {
    return l%r == 0 && l/r == e;
  }
  return false;
}

inline int solve() {
  int num = 1;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
      op = i;
      ls = s.substr(0, i);
    } else if (s[i] == '=') {
      rs = s.substr(op+1, i-op-1);
      es = s.substr(i+1);
    } else {
      num = max(num, mmp(s[i]));
    }
  }
  for (int R = num+1; R <= 16; ++R) {
    if (check(R)) return R;
  }
  return -1;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> s) cout << solve() << endl;
  return 0;
}