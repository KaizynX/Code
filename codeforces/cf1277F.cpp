#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 4e5+7;

int n, n1;
map<int, int> mp;
vector<pair<int, int>> v;
vector<int> s;

inline int check(int i, int mid)
{
    int p = upper_bound(v.begin(), v.end(), make_pair(min(i, mid), 0))-v.begin();
    int num = s[p]+min(i, mid)*(v.size()-p);
    return num;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, a; i <= n; ++i) {
        scanf("%d", &a);
        ++mp[a];
    }
    for (auto p : mp) {
        v.emplace_back(p.second, p.first);
        if (p.second == 1) ++n1;
    }
    sort(v.begin(), v.end());
    s.resize(v.size()+1, 0);
    for (int i = 0; i < (int)v.size(); ++i)
        s[i+1] = s[i]+v[i].first;

    int res = 0, resi, resj;
    for (int i = 1, j; i <= n; ++i) {
        int num = check(i, i);
        j = num/i;
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
            if (i == resi) i = 0, j = cnt/3;
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
