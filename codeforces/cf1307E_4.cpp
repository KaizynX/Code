#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;
const int MOD = 1e9+7;

template <int _MOD> struct Mint
{
    int v = 0;
    Mint() {}
    Mint(int _v) : v((_v%_MOD+_MOD)%_MOD) {}
    Mint(long long _v) : v(static_cast<int>((_v%_MOD+_MOD)%_MOD)) {}
    Mint operator = (const int _v) { this->v = _v; return *this; }
    Mint operator = (const long long _v) { this->v = static_cast<int>(_v%_MOD); return *this; }
    bool operator < (const Mint &b) const { return v < b.v; }
    bool operator > (const Mint &b) const { return v > b.v; }
    bool operator == (const Mint &b) const { return v == b.v; }
    bool operator != (const Mint &b) const { return v != b.v; }
    bool operator <= (const Mint &b) const { return v < b.v || v == b.v; }
    bool operator >= (const Mint &b) const { return v > b.v || v == b.v; }
    Mint operator + (const Mint &b) { return Mint(v+b.v); }
    Mint operator - (const Mint &b) { return Mint(v-b.v); }
    Mint operator * (const Mint &b) { return Mint(1ll*v*b.v); }
    Mint operator / (const Mint &b) { return Mint(b.inv()*v); }
    Mint operator += (const Mint &b) { return *this = *this+b; }
    Mint operator -= (const Mint &b) { return *this = *this-b; }
    Mint operator *= (const Mint &b) { return *this = *this*b; }
    Mint operator /= (const Mint &b) { return *this = *this/b; }
    Mint operator - () { return Mint(-v); }
    Mint &operator ++ () { return *this += 1; }
    Mint &operator -- () { return *this -= 1; }
    Mint operator ++ (int) { Mint tmp = *this; *this += 1; return tmp; }
    Mint operator -- (int) { Mint tmp = *this; *this -= 1; return tmp; }
    Mint pow(int p) const {
        Mint res(1), x(*this);
        while (p) {
            if (p&1) res = res*x;
            x *= x;
            p >>= 1;
        }
        return res;
    }
    Mint inv() const { return pow(_MOD-2); }
    friend istream& operator >> (istream &is, Mint &mt) { return is >> mt.v; }
    friend ostream& operator << (ostream &os, const Mint &mt) { return os << mt.v; }
};
using mint = Mint<MOD>;

int n, m;
int a[N], lef[N], rig[N], num[N];
mint way[N];
int res_num;
mint res_way;
vector<int> cow[N];

inline void update_ans(const int &cur_num, const mint &cur_way)
{
    if (cur_num > res_num) {
        res_num = cur_num;
        res_way = cur_way;
    } else if (cur_num == res_num) {
        res_way += cur_way;
    }
}

inline void calc_ways(const int &i)
{
    int pl = upper_bound(cow[i].begin(), cow[i].end(), lef[i])-cow[i].begin(),
        pr = upper_bound(cow[i].begin(), cow[i].end(), rig[i])-cow[i].begin();
    if (pl > pr) swap(pl, pr);
    int cnt2 = pl*(pr-1), cnt1 = pl+pr;
    if (cnt2 > 0) num[i] = 2, way[i] = cnt2;
    else if (cnt1 > 0) num[i] = 1, way[i] = cnt1;
    else num[i] = 0, way[i] = 1;
}

inline void calc_ways2(const int &i)
{
    int p = upper_bound(cow[i].begin(), cow[i].end(), rig[i])-cow[i].begin();
    if (rig[i] >= lef[i]) --p;
    if (p <= 0) num[i] = 1, way[i] = 1;
    else num[i] = 2, way[i] = p;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++rig[a[i]];
    }
    for (int i = 1, f, h; i <= m; ++i) {
        cin >> f >> h;
        cow[f].emplace_back(h);
    }
    int cur_num = 0;
    mint cur_way = 1;
    for (int i = 1; i <= n; ++i) {
        sort(cow[i].begin(), cow[i].end());
        calc_ways(i);
        cur_num += num[i];
        cur_way *= way[i];
    }
    update_ans(cur_num, cur_way);
    for (int i = 1; i <= n; ++i) {
        cur_num -= num[a[i]];
        cur_way /= way[a[i]];
        ++lef[a[i]];
        --rig[a[i]];
        if (binary_search(cow[a[i]].begin(), cow[a[i]].end(), lef[a[i]])) {
            calc_ways2(a[i]);
            update_ans(cur_num+num[a[i]], cur_way*way[a[i]]);
        }
        calc_ways(a[i]);
        cur_num += num[a[i]];
        cur_way *= way[a[i]];
    }
    cout << res_num << " " << res_way << endl;
    return 0;
}
