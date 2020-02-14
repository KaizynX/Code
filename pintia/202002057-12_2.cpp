#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const double esp = 1e-12;

int n, m;
int sex[N];
double f[N][N], maxf[N];
vector<int> vec[N];

inline bool equal(const double &x, const double &y) { return abs(x-y) < esp; }

inline int read()
{
    static string s;
    static stringstream ss;
    int res;
    ss.clear();
    cin >> s;
    if (s[0] == '-') {
        ss << s.substr(1);
        ss >> res;
        sex[res] = -1;
    } else {
        ss << s;
        ss >> res;
        sex[res] = 1;
    }
    return res;
}

inline void write(int x)
{
    if (sex[x] == -1) cout << '-';
    cout << x;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0, k; i < m; ++i) {
        cin >> k;
        vec[i].resize(k);
        for (int j = 0; j < k; ++j)
            vec[i][j] = read();
    }
    int x, y;
    x = read(); y = read();
    for (int i = 0, xx, yy; i < m; ++i) {
        xx = yy = 0;
        for (int j : vec[i]) {
            if (j == x) xx = 1;
            if (j == y) yy = 1;
        }
        if (xx) for (int j : vec[i])
            f[x][j] += 1.0/vec[i].size();
        if (yy) for (int j : vec[i])
            f[y][j] += 1.0/vec[i].size();
    }
    for (int i = 0; i < n; ++i) {
        if (i == x || sex[i] == sex[x]) continue;
        maxf[x] = max(maxf[x], f[x][i]);
    }
    for (int i = 0; i < n; ++i) {
        if (i == y || sex[i] == sex[y]) continue;
        maxf[y] = max(maxf[y], f[y][i]);
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i)
        cout << f[x][i] << " \n"[i==n-1];
    for (int i = 0; i < n; ++i)
        cout << f[y][i] << " \n"[i==n-1];
    cout << maxf[x] << " " << maxf[y] << endl;
#endif
    if (equal(f[x][y], maxf[x]) && equal(f[y][x], maxf[y])) {
        cout << sex[x]*x << " " << sex[y]*y << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            if (sex[x] == sex[i]) continue;
            if (equal(f[x][i], maxf[x])) {
                write(x); cout << " "; write(i); cout << endl;
            }
            // cout << sex[x]*x << " " << sex[i]*i << endl;
        }
        for (int i = 0; i < n; ++i) {
            if (sex[y] == sex[i]) continue;
            if (equal(f[y][i], maxf[y])) {
                write(y); cout << " "; write(i); cout << endl;
            }
            // cout << sex[y]*y << " " << sex[i]*i << endl;
        }
    }
    return 0;
}
