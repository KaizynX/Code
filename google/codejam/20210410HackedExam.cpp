/*
 * @Author: Kaizyn
 * @Date: 2021-04-10 10:19:19
 * @LastEditTime: 2021-04-10 10:35:45
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 20;

template <class T>
struct Fraction {
  T a, b;
  void normalize() {
    if (a == 0) return (void)(b = 1);
    T g = __gcd(a, b);
    a /= g; b /= g;
    if (b < 0) a = -a, b = -b;
  }
  Fraction(const T &_a = 0, const T &_b = 1) : a(_a), b(_b) { normalize(); }
  friend bool operator < (const Fraction &f1, const Fraction &f2) { return f1.a*f2.b < f2.a*f1.b; }
  friend bool operator > (const Fraction &f1, const Fraction &f2) { return f1.a*f2.b > f2.a*f1.b; }
  friend bool operator == (const Fraction &f1, const Fraction &f2) { return f1.a*f2.b == f2.a*f1.b; }
  friend bool operator != (const Fraction &f1, const Fraction &f2) { return f1.a*f2.b != f2.a*f1.b; }
  friend bool operator <= (const Fraction &f1, const Fraction &f2) { return f1 < f2 || f1 == f2; }
  friend bool operator >= (const Fraction &f1, const Fraction &f2) { return f1 > f2 || f1 == f2; }
  friend Fraction operator + (const Fraction &f1, const Fraction &f2) { return Fraction(f1.a*f2.b+f2.a*f1.b, f1.b*f2.b); }
  friend Fraction operator - (const Fraction &f1, const Fraction &f2) { return Fraction(f1.a*f2.b-f2.a*f1.b, f1.b*f2.b); }
  friend Fraction operator * (const Fraction &f1, const Fraction &f2) { return Fraction(f1.a*f2.a, f1.b*f2.b); }
  friend Fraction operator / (const Fraction &f1, const Fraction &f2) { return Fraction(f1.a*f2.b, f1.b*f2.a); }
  Fraction& operator += (const Fraction &f) { return *this = *this+f; }
  Fraction& operator -= (const Fraction &f) { return *this = *this-f; }
  Fraction& operator *= (const Fraction &f) { return *this = *this*f; }
  Fraction& operator /= (const Fraction &f) { return *this = *this/f; }
  friend istream& operator >> (istream &is, Fraction &f) {
    is >> f.a >> f.b;
    f.normalize();
    return is;
  }
  friend ostream& operator << (ostream &os, const Fraction &f) {
    // if (f.b == 1) return os << f.a;
    return os << f.a << "/" << f.b;
  }
};
using fraction = Fraction<long long>;

int n, q;
int a[N], s[N];
int cnt[N], sum;

inline void print(int x) {
  for (int i = 0; i < q; ++i) {
    cout << "FT"[(x>>i)&1];
  }
}

inline void solve(int t) {
  memset(cnt, 0, sizeof cnt);
  sum = 0;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) {
    static string str;
    cin >> str >> s[i];
    a[i] = 0;
    for (int j = 0; j < q; ++j) {
      if (str[j] == 'T') a[i] |= 1<<j;
    }
  }
  for (int i = 0; i < 1<<q; ++i) {
    int flag = 1;
    for (int j = 0; j < n; ++j) {
      flag &= __builtin_popcount(i^a[j]) == q-s[j];
    }
    if (!flag) continue;
    ++sum;
    for (int j = 0; j < q; ++j) {
      cnt[j] += (i>>j)&1;
    }
    #ifdef DEBUG
    print(i); cout << '\n';
    #endif
  }
  #ifdef DEBUG
  cout << sum << '\n';
  for (int i = 0; i < q; ++i) cout << cnt[i] << " \n"[i==q-1];
  #endif
  int res = 0;
  fraction score;
  for (int j = 0; j < q; ++j) {
    if (cnt[j] >= sum-cnt[j]) {
      res |= 1<<j;
      score += fraction(cnt[j], sum);
    } else {
      score += fraction(sum-cnt[j], sum);
    }
  }
  cout << "Case #" << t << ": ";
  print(res);
  cout << ' ' << score << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve(t);
  }
  return 0;
}