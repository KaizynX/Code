#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

map<pair<int, int>, int> mem;

int dfs(int x, int y)
{
    if (x < 0 || y < 0) return 0;
    if (mem.count({x, y})) return mem[{x, y}];
    return mem[{x, y}] = (dfs(x-1, y-2)+dfs(x-2, y-1))%MOD;
}

int main()
{
    int x, y;
    cin >> x >> y;
    mem[{0, 0}] = 1;
    cout << dfs(x, y) << endl;
    return 0;
}

