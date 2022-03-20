/*
 * @Author: Kaizyn
 * @Date: 2022-03-20 15:38:43
 * @LastEditTime: 2022-03-20 16:04:31
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
// const int N = ;

vector<int> NormalLevels = {
0,
1000,
1325,
1700,
2150,
2625,
3150,
3725,
4350,
5000,
5700,
6450,
7225,
8050,
8925,
9825,
10750,
11725,
12725,
13775,
14875,
16800,
18000,
19250,
20550,
21875,
23250,
24650,
26100,
27575,
29100,
30650,
32250,
33875,
35550,
37250,
38975,
40750,
42575,
44425,
46300,
50625,
52700,
54775,
56900,
59075,
61275,
63525,
65800,
68125,
70475,
76500,
79050,
81650,
84275,
86950,
89650,
92400,
95175,
98000,
100875,
108950,
112050,
115175,
118325,
121525,
124775,
128075,
131400,
134775,
138175,
148700,
152375,
156075,
159825,
163600,
167425,
171300,
175225,
179175,
183175,
216225,
243025,
273100,
306800,
344600,
386950,
434425,
487625,
547200
};

vector<int> PresumNormal;

using uint = unsigned;

vector<pii> AscentionLevel[6] = {
  {{8, 1},{2, 0},{12, 3},{1, 3},{0, 20000}},
  {{9, 3},{2, 2},{12, 15},{1, 10},{0, 40000}},
  {{9, 6},{2, 4},{13, 12},{1, 20},{0, 60000}},
  {{10, 3},{2, 8},{13, 18},{1, 30},{0, 80000}},
  {{10, 6},{2, 12},{14, 12},{1, 45},{0, 100000}},
  {{11, 6},{2, 20},{14, 24},{1, 60},{0, 120000}}
};

vector<pii> TalentLevel[9] = {
  {{0, 12500}, {12, 6},{15, 3},{3, 0}, {4, 0}},
  {{0, 17500}, {13, 3},{16, 2},{3, 0}, {4, 0}},
  {{0, 25000}, {13, 4},{16, 4},{3, 0}, {4, 0}},
  {{0, 30000}, {13, 6},{16, 6},{3, 0}, {4, 0}},
  {{0, 37500}, {13, 9},{16, 9},{3, 0}, {4, 0}},
  {{0, 120000},{14, 4},{17, 4},{3, 1}, {4, 0}},
  {{0, 260000},{14, 6},{17, 6},{3, 1}, {4, 0}},
  {{0, 450000},{14, 9},{17, 12},{3, 2}, {4, 0}},
  {{0, 700000},{14, 12},{17, 16},{3, 2}, {4, 1}}
};

vector<pii> ExperienceMaterials = {
  {7, 20000},
  {6, 5000},
  {5, 1000}
};

vector<int> Upgrade = {20, 40, 50, 60, 70, 80};

vector<vector<int>> print_format = {
  {0, 1, 2, 3, 4},
  {5, 6, 7},
  {8, 9, 10, 11},
  {12, 13, 14},
  {15, 16, 17}
};

void update_ans(vector<int> &ans, const vector<pii> &mp) {
  for (const auto &pr : mp) {
    ans[pr.first] += pr.second;
  }
}

void normal_upgrade(int l0, int l, vector<int> &ans) {
  int dis = PresumNormal[l - 1] - PresumNormal[l0 - 1];
  ans[0] += dis / 5;
  for (auto pr : ExperienceMaterials) {
    ans[pr.first] += dis / pr.second;
    dis %= pr.second;
    if (pr.second - dis < 1000) {
      ans[pr.first] ++;
      break;
    }
  }
}

void print(const vector<int> &ans) {
  for (const auto &line : print_format) {
    int fir = 1;
    for (const auto &str : line) {
      if (!fir) putchar(' ');
      fir = 0;
      printf("%d", ans[str]);
    }
    putchar('\n');
  }
}

inline void solve() {
  vector<int> ans(18, 0);
  int a0, l0, t0[3], a, l, t[3];
  scanf("%d%d", &a0, &l0);
  for (int i : {0, 1, 2}) scanf("%d", t0 + i);
  scanf("%d%d", &a, &l);
  for (int i : {0, 1, 2}) scanf("%d", t + i);
  // Talent
  for (int _ : {0, 1, 2}) {
    for (int i = t0[_] - 1; i < t[_] - 1; ++i) {
      update_ans(ans, TalentLevel[i]);
    }
  }
  // Ascend
  for (int _ = a0; _ < a; ++_) {
    normal_upgrade(l0, Upgrade[_], ans);
    l0 = Upgrade[_];
    update_ans(ans, AscentionLevel[_]);
  }
  // Normal
  normal_upgrade(l0, l, ans);
  print(ans);
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  PresumNormal = NormalLevels;
  for (uint i = 1; i < PresumNormal.size(); ++i) {
    PresumNormal[i] += PresumNormal[i - 1];
  }
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}