#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n;
char a[N][N];
vector<int> v[2];

int main()
{
    while (scanf("%d", &n) && n) {
        int res = 1;
        for (int i = 0; i < n; ++i)
            scanf("%s", a[i]);
        // for (int s = 1, len; s < n*2-2; ++s) {
        for (int s = n-1, len, add = 1; s > 0 && s < 2*n-2;
             s += add, add = -add/abs(add)*(abs(add)+1)) {
            if (min(s, 2*n-2-s)+1 <= res) break;
            v[1].clear();
            for (int i = max(0, s-n+1); i < n && i <= s; ++i)
                v[1].emplace_back(i);
            for (len = 1; v[len&1].size(); ++len) {
                v[len&1^1].clear();
                for (int i = 1, x, y; i < (int)v[len&1].size(); ++i) {
                    x = v[len&1][i];
                    y = s-x;
                    if (v[len&1][i-1]+1 == v[len&1][i] &&
                        a[x-len][y] == a[x][y+len]) {
                        v[len&1^1].emplace_back(i);
                    }
                }
            }
            res = max(res, len-1);
        }
        cout << res << endl;
    }
    return 0;
}
