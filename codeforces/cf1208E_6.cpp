#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int MAXN = 1e6+7;
const int INF = 1e9;

int n, w;
long long res[MAXN];
multiset<int> ms[MAXN];
vector<pair<int, int> > add[MAXN], del[MAXN];

int main()
{
    scanf("%d%d", &n, &w);
    for (int i = 1, l, a; i <= n; ++i) {
        scanf("%d", &l);
        if (l < w) {
            add[1].push_back({0, i});
            del[w-l+1].push_back({0, i});
            add[l+1].push_back({0, i});
            // del[w+1].push_back({0, i});
        }
        for (int j = 1; j <= l; ++j) {
            scanf("%d", &a);
            add[j].push_back({a, i});
            del[j+w-l+1].push_back({a, i});
        }
    }
    for (int i = 1, last, now; i <= w; ++i) {
        res[i] = res[i-1];
        for (auto p : add[i]) {
            last = (ms[p.second].empty() ? 0 : *ms[p.second].rbegin());
            ms[p.second].insert(p.first);
            now = *ms[p.second].rbegin();
            res[i] += now-last;
        }
        for (auto p : del[i]) {
            last = *ms[p.second].rbegin();
            ms[p.second].erase( ms[p.second].find(p.first) );
            now = (ms[p.second].empty() ? 0 : *ms[p.second].rbegin());
            res[i] += now-last;
        }
        printf("%I64d ", res[i]);
    }
    putchar('\n');
    return 0;
}
