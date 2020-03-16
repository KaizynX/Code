/*
 * @Author: Kaizyn
 * @Date: 2020-03-16 09:20:43
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-16 09:32:09
 * @FilePath: \Code\pintia\2020031507_3.cpp
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 3e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int dirx[] = {0,0,-1,1,-1,1,-1,1},
          diry[] = {-1,1,0,0,-1,1,1,-1};

namespace std {
    template <>
    struct hash<pii>
    {
        size_t operator () (const pii &x) const {
            return hash<int>()(x.first)^hash<int>()(x.second);
        }
    };
}

int n, m, k;
int x[N], y[N];
queue<pii> q;
vector<int> dx, dy;
unordered_map<pii, int> black, white;

template <typename T>
inline void clear(T &x)
{
    T tmp;
    swap(x, tmp);
}

inline void solve()
{
    dx.reserve(M);
    dy.reserve(M);
    black.rehash(M);
    white.rehash(M);
    scanf("%d %d %d", &n, &m, &k);
    dx.emplace_back(0);
    dx.emplace_back(1);
    dx.emplace_back(n);
    dx.emplace_back(n+1);
    dy.emplace_back(0);
    dy.emplace_back(1);
    dy.emplace_back(m);
    dy.emplace_back(m+1);
    for (int i = 1; i <= k; ++i) {
        scanf("%d %d", x+i, y+i);
        dx.emplace_back(x[i]);
        dx.emplace_back(x[i]-1);
        dx.emplace_back(x[i]+1);
        dy.emplace_back(y[i]);
        dy.emplace_back(y[i]-1);
        dy.emplace_back(y[i]+1);
    }
    sort(dx.begin(), dx.end());
    sort(dy.begin(), dy.end());
    dx.erase(unique(dx.begin(), dx.end()), dx.end());
    dy.erase(unique(dy.begin(), dy.end()), dy.end());
    for (int i = 1; i <= k; ++i) {
        x[i] = lower_bound(dx.begin(), dx.end(), x[i])-dx.begin();
        y[i] = lower_bound(dy.begin(), dy.end(), y[i])-dy.begin();
        black.insert({{x[i], y[i]}, 0});
    }
    n = dx.size();
    m = dy.size();
    for (int i = 1; i < n-1; ++i) {
        black.insert({{i, 0}, 0});
        black.insert({{i, m-1}, 0});
    }
    for (int i = 1; i < m-1; ++i) {
        black.insert({{0, i}, 0});
        black.insert({{n-1, i}, 0});
    }

    int res = 0;
    for (auto &bpt : black) {
        if (bpt.second) continue;
        clear(q);
        white.clear();
        q.push(bpt.first);
        bpt.second = 1;
        while (q.size()) {
            int ux = q.front().first,
                uy = q.front().second;
            q.pop();
            for (int i = 0, vx, vy; i < 8; ++i) {
                vx = ux+dirx[i];
                vy = uy+diry[i];
                auto nex = black.find({vx, vy});
                if (nex == black.end()) {
                    white.insert({{vx, vy}, 0});
                } else if (nex->second == 0) {
                    nex->second = 1;
                    q.push(nex->first);
                }
            }
        }

        for (auto &wpt : white) {
            if (wpt.second) continue;
            ++res;
            clear(q);
            q.push(wpt.first);
            wpt.second = 1;
            while (q.size()) {
                int ux = q.front().first,
                    uy = q.front().second;
                q.pop();
                for (int i = 0, vx, vy; i < 4; ++i) {
                    vx = ux+dirx[i];
                    vy = uy+diry[i];
                    auto nex = white.find({vx, vy});
                    if (nex == white.end() || nex->second) continue;
                    nex->second = 1;
                    q.push(nex->first);
                }
            }
        }
        --res;
    }
    printf("%d\n", res);
}

signed main()
{
    solve();
    return 0;
}