/*
 * @Author: Kaizyn
 * @Date: 2020-04-09 10:34:16
 * @LastEditTime: 2020-04-09 10:56:58
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int a[N*N];
int val[N][N], vis[N][N];

struct Node
{
    int x, y;
    Node(){}
    Node(int _x, int _y) : x(_x), y(_y) {}
    friend bool operator < (const Node &lhs, const Node &rhs) {
        return val[lhs.x][lhs.y] < val[rhs.x][rhs.y];
    }
};

// inline void mp(const int &x, const int &y) { return (x-1)*n+y-1; }

Node get_minv()
{
    Node mv(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vis[i][j]) continue;
            mv = min(mv, Node(i, j));
        }
    }
    return mv;
}

int rook_walk()
{
    memset(vis, 0, sizeof vis);
    int vun = 0;
    Node cur = get_minv(), mv;
    vis[cur.x][cur.y] = 1;
    for (int t = 1; t < n*n; ++t) {
        mv = Node(n, n);
        for (int i = 0; i < n; ++i) {
            if (!vis[cur.x][i]) mv = min(mv, Node(cur.x, i));
            if (!vis[i][cur.y]) mv = min(mv, Node(i, cur.y));
        }
        if (mv.x >= n) {
            mv = get_minv();
            ++vun;
        }
        vis[mv.x][mv.y] = 1;
        cur = mv;
    }
    return vun;
}

int queen_walk()
{
    memset(vis, 0, sizeof vis);
    int vun = 0;
    Node cur = get_minv(), mv;
    vis[cur.x][cur.y] = 1;
    for (int t = 1; t < n*n; ++t) {
        mv = Node(n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j]) continue;
                if (i == cur.x || j == cur.y ||
                    i+j == cur.x+cur.y || i-j == cur.x-cur.y) {
                    mv = min(mv, Node(i, j));
                }
            }
        }
        if (mv.x >= n) {
            mv = get_minv();
            ++vun;
        }
        vis[mv.x][mv.y] = 1;
        cur = mv;
    }
    return vun;
}

void print()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << val[i][j] << " \n"[j==n-1];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n*n; ++i) a[i] = i+1;
    val[n][n] = INF;
    do {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                val[i][j] = a[i*n+j];
            }
        }
        if (rook_walk() < queen_walk()) {
            print();
            break;
        }
    } while (next_permutation(a, a+n*n));
    return 0;
}