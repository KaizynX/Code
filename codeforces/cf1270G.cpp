#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int T, n;
int a[N], dfn[N];
vector<int> vec;

bool dfs(int cur, int dep)
{
    if (dfn[cur]) {
        cout << dep-dfn[cur] << endl;
        while (vec.back() != cur) {
            cout << vec.back() << " ";
            vec.pop_back();
        }
        cout << cur << endl;
        return true;
    }
    dfn[cur] = dep;
    vec.emplace_back(cur);
    if (dfs(cur-a[cur], dep+1)) return true;
    vec.pop_back();
    return false;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        vec.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            dfn[i] = 0;
        }
        for (int i = 1; i <= n; ++i) if (!dfn[i]) {
            if (dfs(i, 1)) break;
        }
    }
    return 0;
}
