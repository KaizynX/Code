#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;

int n, c, r;
int f[N][N];

struct Name
{
    map<string, int> mp;
    int sz;
    void init() { mp.clear(); sz = 0; }
    int id(const string &str) {
        return mp.find(str) == mp.end() ? mp[str] = ++sz : mp[str];
    }
} name;

inline void update(int &x, const int y) { if (x == -1 || x > y) x = y; }

inline void floyd()
{
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (f[i][k] != -1 && f[k][j] != -1)
                    update(f[i][j], f[i][k]+f[k][j]);
}

inline int solve()
{
    static int s;
    static vector<int> t;
    static string str;
    name.init();
    t.clear();
    memset(f, -1, sizeof f);

    cin >> str; s = name.id(str);
    for (int i = 1; i <= c; ++i) {
        cin >> str;
        t.emplace_back(name.id(str));
    }
    for (int i = 1, j, u, v, w; i <= r; ++i) {
        cin >> str; u = name.id(str);
        cin >> str;
        string path = str;
        cin >> str; v = name.id(str);
        w = j = 0;
        while (j < (int)path.length() && !isdigit(path[j])) ++j;
        while (j < (int)path.length() && isdigit(path[j])) w = w*10+path[j++]-'0';
        if (path.front() == '<') update(f[v][u], w);
        if (path.back() == '>') update(f[u][v], w);
    }
    floyd();
    int res = 0;
    for (int i : t) res += f[s][i]+f[i][s];
    return res;
}

int main()
{
    int T = 0;
    while (cin >> n >> c >> r && n|c|r) {
        cout << ++T << ". " << solve() << endl;
    }
    return 0;
}
