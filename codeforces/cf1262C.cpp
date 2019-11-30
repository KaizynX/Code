#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;

int n, k, T;
char s[N], ss[N];

inline void f(int i, int j)
{
    while (i < j) {
        swap(s[i], s[j]);
        ++i;
        --j;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        int m = 0;
        vector<pair<int, int>> res;
        scanf("%d%d%s", &n, &k, s+1);
        for (int i = 1; i < k; ++i) {
            ss[i*2-1] = '(';
            ss[i*2] = ')';
        }
        ss[k*2-1] = '(';
        ss[n] = ')';
        for (int i = k*2; i < n; ++i) {
            ss[i] = (i&1 ? ')' : '(');
        }
        for (int i = 1; i <= n; ++i) {
            if (s[i] == ss[i]) continue;
            for (int j = i+1; j <= n; ++j) {
                if (s[j] == ss[i]) {
                    ++m;
                    res.emplace_back(i, j);
                    f(i, j);
                    break;
                }
            }
        }
        printf("%d\n", m);
        for (auto p : res) printf("%d %d\n", p.first, p.second);
    }
    return 0;
}
