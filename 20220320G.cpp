/*
 * @Author: Kaizyn
 * @Date: 2022-03-20 14:36:04
 * @LastEditTime: 2022-03-20 15:56:11
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

using mpsi = map<string, int>;
using uint = unsigned;

map<string, int> AscentionLevel[6] = {
  {{"Sliver", 1},   {"Boss Drops", 0}, {"Common", 3}, {"Specialties", 3}, {"Coins", 20000}},
  {{"Fragments", 3},{"Boss Drops", 2}, {"Common", 15},{"Specialties", 10},{"Coins", 40000}},
  {{"Fragments", 6},{"Boss Drops", 4}, {"Rare", 12},  {"Specialties", 20},{"Coins", 60000}},
  {{"Chunks", 3},   {"Boss Drops", 8}, {"Rare", 18},  {"Specialties", 30},{"Coins", 80000}},
  {{"Chunks", 6},   {"Boss Drops", 12},{"Epic", 12},  {"Specialties", 45},{"Coins", 100000}},
  {{"Gemstones", 6},{"Boss Drops", 20},{"Epic", 24},  {"Specialties", 60},{"Coins", 120000}}
};

map<string, int> TalentLevel[9] = {
  {{"Coins", 12500}, {"Common", 6},{"Teachings", 3},    {"Weekly Boss Drops", 0}, {"Crown of Insight", 0}},
  {{"Coins", 17500}, {"Rare", 3},  {"Guides", 2},       {"Weekly Boss Drops", 0}, {"Crown of Insight", 0}},
  {{"Coins", 25000}, {"Rare", 4},  {"Guides", 4},       {"Weekly Boss Drops", 0}, {"Crown of Insight", 0}},
  {{"Coins", 30000}, {"Rare", 6},  {"Guides", 6},       {"Weekly Boss Drops", 0}, {"Crown of Insight", 0}},
  {{"Coins", 37500}, {"Rare", 9},  {"Guides", 9},       {"Weekly Boss Drops", 0}, {"Crown of Insight", 0}},
  {{"Coins", 120000},{"Epic", 4},  {"Philosophies", 4}, {"Weekly Boss Drops", 1}, {"Crown of Insight", 0}},
  {{"Coins", 260000},{"Epic", 6},  {"Philosophies", 6}, {"Weekly Boss Drops", 1}, {"Crown of Insight", 0}},
  {{"Coins", 450000},{"Epic", 9},  {"Philosophies", 12},{"Weekly Boss Drops", 2}, {"Crown of Insight", 0}},
  {{"Coins", 700000},{"Epic", 12}, {"Philosophies", 16},{"Weekly Boss Drops", 2}, {"Crown of Insight", 1}}
};

vector<pair<string, int>> ExperienceMaterials = {
  {"Hero's Wit", 20000},
  {"Adventurer's Experience", 5000},
  {"Wanderer's Advice", 1000}
};

vector<int> Upgrade = {20, 40, 50, 60, 70, 80};

vector<vector<string>> print_format = {
  {"Coins", "Specialties", "Boss Drops", "Weekly Boss Drops", "Crown of Insight"},
  {"Wanderer's Advice", "Adventurer's Experience", "Hero's Wit"},
  {"Sliver", "Fragments", "Chunks", "Gemstones"},
  {"Common", "Rare", "Epic"},
  {"Teachings", "Guides", "Philosophies"}
};

void update_ans(mpsi &ans, const mpsi &mp) {
  for (const auto &pr : mp) {
    ans[pr.first] += pr.second;
  }
}

void normal_upgrade(int l0, int l, mpsi &ans) {
  int dis = PresumNormal[l - 1] - PresumNormal[l0 - 1];
  ans["Coins"] += dis / 5;
  for (auto pr : ExperienceMaterials) {
    ans[pr.first] += dis / pr.second;
    dis %= pr.second;
  }
  if (dis) ans["Wanderer's Advice"]++;
}

void print(mpsi &ans) {
  for (const auto &line : print_format) {
    int fir = 1;
    for (const string &str : line) {
      if (!fir) putchar(' ');
      fir = 0;
      printf("%d", ans[str]);
    }
    putchar('\n');
  }
}

inline void solve() {
  map<string, int> ans;
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