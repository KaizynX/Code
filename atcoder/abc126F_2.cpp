#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 17;

int m, k;
vector<int> v, vk;

void dfs(int cur, int now)
{
    if (cur >= m) {
        v.push_back(now);
        return;
    }
    dfs(cur+1, now);
    if ((k&(1<<cur)) == 0) dfs(cur+1, now+(1<<cur));
}

void dfsk(int cur, int now)
{
    if (cur >= m) {
        vk.push_back(now);
        return;
    }
    dfsk(cur+1, now);
    if (k&(1<<cur)) dfsk(cur+1, now+(1<<cur));
}

int main()
{
    cin >> m >> k;
    if (k == 0) {
        for (int i = 0; i < (1<<m); ++i) {
            cout << i << " " << i << " ";
        }
        cout << endl;
        return 0;
    }
    if (k >= (1<<m) || (k == 1 && m == 1)) {
        cout << -1 << endl;
        return 0;
    }
    dfs(0, 0);
    dfsk(0, 0);
    sort(vk.begin(), vk.end());
    for (int i : vk) {
        if (k-i < i) break;
        for (int j : v)
            cout << i+j << " " << k-i+j << " ";
    }
    for (int i : vk) {
        if (k-i < i) break;
        for (int j : v)
            cout << k-i+j << " " << i+j << " ";
    }
    cout << endl;
    return 0;
}
