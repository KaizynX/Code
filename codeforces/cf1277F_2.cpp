#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 4e5+7;

int n;
int num[N];
map<int, int> mp;
vector<pair<int, int>> v;

int main()
{
    scanf("%d", &n);
    for (int i = 1, a; i <= n; ++i) {
        scanf("%d", &a);
        ++mp[a];
    }
    for (auto p : mp) v.emplace_back(p.second, p.first);
    sort(v.begin(), v.end());
    for (int i = 1, j = 0, s = 0; i <= n; ++i) {
        while (j < (int)v.size() && v[j].first <= i) s += v[j++].first;
        num[i] = s+((int)v.size()-j)*i;
    }
#ifdef DEBUG
    for (int i = 0; i < (int)v.size(); ++i)
        printf("(%d %d) ", v[i].second, v[i].first);
    putchar('\n');
    for (int i = 1; i <= n; ++i)
        printf("%d ", num[i]);
    putchar('\n');
#endif

    int res = 0, resi, resj;
    for (int i = 1, j; i <= n; ++i) {
        j = num[i]/i;
        if (j < i) continue;
        if (i*j > res) {
            res = i*j;
            resi = i;
            resj = j;
        }
    }
    vector<vector<int>> a(resi, vector<int>(resj, 0));
    for (int i = 0, j = 0, cnt = 0, k = (int)v.size()-1; k >= 0; --k) {
        for (int t = 0; t < min(v[k].first, min(resi, resj)); ++t) {
            a[i][j] = v[k].second;
            if (++cnt == res) break;
            ++i; ++j;
            if (i == resi) i = 0, j = cnt/resi;
            if (j >= resj) j -= resj;
        }
        if (cnt == res) break;
    }
    printf("%d\n", res);
    printf("%d %d\n", resi, resj);
    for (int i = 0; i < resi; ++i) {
        for (int j = 0; j < resj; ++j) {
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

