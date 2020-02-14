#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;

int n;
int p[N], c[N], res[N];
vector<int> e[N];

inline bool cmp(int x, int y) { return res[x] < res[y]; }

inline void update(vector<int> &vec) {
    for (int i = 0; i < (int)vec.size(); ++i) {
        res[vec[i]] = i+1;
    }
}

vector<int> dfs(int u) {
    vector<int> vec, tmp;
    for (int v : e[u]) {
        tmp = dfs(v);
        vec.insert(vec.end(), tmp.begin(), tmp.end());
    }
    sort(vec.begin(), vec.end(), cmp);
    update(vec);
    if (c[u] > (int)vec.size()) {
        cout << "NO" << endl;
        exit(0);
    }
    vec.insert(vec.begin()+c[u], u);
    update(vec);
    return vec;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> c[i];
        e[p[i]].emplace_back(i);
    }
    c[0] = n;
    dfs(0);
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " \n"[i==n];
    }
    return 0;
}
