#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n, k;
vector<int> a[N];

inline double calc(int x, int y)
{
    static unordered_set<int> s;
    static unordered_map<int, int> mp;
    s.clear();
    mp.clear();
    for (int i : a[x]) mp[i] = 1;
    for (int i : a[y]) if (mp[i]) s.insert(i);
    int nc = s.size();
    s.clear();
    for (int i : a[x]) s.insert(i);
    for (int i : a[y]) s.insert(i);
    int nt = s.size();
    // cout << nc << " " << nt << endl;
    return 100.0*nc/nt;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0, m; i < n; ++i) {
        scanf("%d", &m);
        a[i].resize(m);
        for (int j = 0; j < m; ++j)
            scanf("%d", &a[i][j]);
    }
    scanf("%d", &k);
    for (int i = 0, x, y; i < k; ++i) {
        scanf("%d %d", &x, &y);
        printf("%.2f%%\n", calc(x-1, y-1));
    }
    return 0;
}
