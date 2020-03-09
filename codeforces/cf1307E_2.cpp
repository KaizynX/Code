#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e3+7;
const double err = 1e-9;
const int INF = 1e9;
const int MOD = 1e9+7;
typedef pair<int, int> pii;

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

int n, m, ans;
int a[N], vis[N], appear[N];
long long cnt[N];
// v[i] the h of all eat (f[] == i)
vector<int> v[N], t[N];
vector<pii> s;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> a[1];
    int last = a[1], num = 1;
    for (int i = 2; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == last) ++num;
        else {
            ++appear[last];
            s.emplace_back(last, num);
            last = a[i];
            num = 1;
        }
    }
    ++appear[last];
    s.emplace_back(last, num);
#ifdef DEBUG
    for (pii &p : s) cout << "(" << p.first << ", " << p.second << ") ";
    cout << endl;
#endif
    for (int i = 1, f, h; i <= m; ++i) {
        cin >> f >> h;
        v[f].emplace_back(h);
    }
    for (int i = 1; i <= n; ++i)
        sort(v[i].begin(), v[i].end());

    for (pii &p : s) {
        if (vis[p.first]) continue;
        vis[p.first] = 1;
        t[p.first].emplace_back(p.second);
    }
    memset(vis, 0, sizeof vis);
    for (int i = (int)s.size()-1; i >= 0; --i) {
        pii &p = s[i];
        if (vis[p.first]) continue;
        vis[p.first] = 1;
        t[p.first].emplace_back(p.second);
    }
    mint mul = 1, res = 0;
    num = 0;
    for (int i = 1; i <= n; ++i) {
        cnt[i] = 1;
        num += t[i].size();
        if (!t[i].size()) continue;
        else if (t[i].size() == 1) {
            int p = upper_bound(v[i].begin(), v[i].end(), t[i][0])-v[i].begin();
            if (!p) continue;
            cnt[i] = p;
        } else {
            int p1 = upper_bound(v[i].begin(), v[i].end(), t[i][0])-v[i].begin(),
                p2 = upper_bound(v[i].begin(), v[i].end(), t[i][1])-v[i].begin();
            if (p1 > p2) swap(p1, p2);
            if (p2 < 2) continue;
            if (!p1) p1 = 1;
            if (!p2) p2 = 1;
            cnt[i] = p1*(p2-1);
        }
        mul *= cnt[i];
    }
    ans = num;
    res = mul;
    for (pii &p : s) {
        if (appear[p.first] > 1) continue;
        int cur = p.first, tmp = 0;
        for (int i = 0; i < (int)v[cur].size(); ++i) {
            int nex = upper_bound(v[cur].begin(), v[cur].end(), p.second-v[cur][i])-v[cur].begin();
            if (!nex) break;
            tmp += nex-(nex >= i);
        }
        if (!tmp) continue;
        if (ans != num+1) res = 0;
        ans = num+1;
        res += mul/cnt[cur]*tmp;
    }
    cout << ans << " " << res << endl;
    return 0;
}
