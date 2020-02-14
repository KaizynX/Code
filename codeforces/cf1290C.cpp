#include <bits/stdc++.h>

using namespace std;

const int N = 6e5+7;
const int INF = 1e9;

int n, k;
int fa[N], val[N];
string s;
vector<int> v[N];

int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
inline int calc(const int &x) { return min(val[get(x)], val[get(x+k)]); }
inline void merge(int x, int y) {
    int fx = get(x), fy = get(y);
    if (fx == fy) return;
    val[fx] += val[fy]; fa[fy] = fx;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> s;
    for (int i = 1, m; i <= k; ++i) {
        cin >> m;
        for (int j = 1, x; j <= m; ++j) {
            cin >> x;
            v[x].emplace_back(i);
        }
    }
    for (int i = 1; i <= k*2+1; ++i) fa[i] = i, val[i] = i > k;
    val[2*k+1] = INF;
    for (int i = 1, res = 0; i <= n; ++i) {
        if (v[i].size() == 1) {
            res -= calc(v[i][0]);
            merge(v[i][0]+(s[i-1] == '1')*k, 2*k+1);
            res += calc(v[i][0]);
        } else if (v[i].size() == 2) {
            if (s[i-1] == '1' && get(v[i][0]) != get(v[i][1])) {
                res -= calc(v[i][0])+calc(v[i][1]);
                merge(v[i][0], v[i][1]); merge(v[i][0]+k, v[i][1]+k);
                res += calc(v[i][0]);
            } else if (s[i-1] == '0' && get(v[i][0]) != get(v[i][1]+k)) {
                res -= calc(v[i][0])+calc(v[i][1]);
                merge(v[i][0], v[i][1]+k); merge(v[i][0]+k, v[i][1]);
                res += calc(v[i][0]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
