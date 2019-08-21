#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

int T, n;
int f[MAXN<<1], used[MAXN][4], c[MAXN][2];
pair<int, int> mem[MAXN<<1];

struct Node
{
    int i, v, s;
    Node() {}
    Node(int _i, int _v, int _s) : i(_i), v(_v), s(_s) {}
    bool operator < (const Node &nex) const
    { 
        return v == nex.v ? s < nex.s : v < nex.v;
    }
};

int main()
{
    scanf("%d", &T);
    while (T--) {
        priority_queue<Node> q1, q2;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &c[i][0], &c[i][1]);
            q1.push(Node(i, c[i][0], 0));
            if (c[i][0] < c[i][1]) q2.push(Node(i, c[i][0]+c[i][1], 2));
            used[i][0] = used[i][1] = 0;
        }
        for (int i = 1; i <= 2*n; ++i) 
            mem[i] = {0, 0};
        Node p1, p2;
        p1 = q1.top();
        q1.pop();
        f[1] = p1.v;
        mem[1] = { p1.i, 0};
        used[p1.i][p1.s] = 1;
        q1.push(Node(p1.i, c[p1.i][1], 1));
        for (int i = 2; i <= n*2; ++i) {
            int flag1 = q1.size(), flag2 = q2.size();
            if (flag1) {
                p1 = q1.top();
                while (used[p1.i][p1.s] || (p1.s == 1 && !used[p1.i][0])) {
                    q1.pop();
                    if (!q1.size()) {
                        flag1 = 0;
                        break;
                    }
                    p1 = q1.top();
                }
            }
            if (flag2) {
                p2 = q2.top();
                while (used[p2.i][1]) {
                    q2.pop();
                    if (!q2.size()) {
                        flag2 = 0;
                        break;
                    }
                    p2 = q2.top();
                }
            }
            if (!flag1 || (flag2 && c[mem[i-1].first][mem[i-1].second]+p1.v < p2.v)) {
                used[mem[i-1].first][mem[i-1].second] = 0;
                q1.push(Node(mem[i-1].first, c[mem[i-1].first][mem[i-1].second], mem[i-1].second));
                f[i] = f[i-2]+p2.v;
                used[p2.i][0] = used[p2.i][1] = 1;
                mem[i-1] = { p2.i, 0 };
                mem[i] = { p2.i, 1 };
                q2.pop();
            } else {
                used[p1.i][p1.s] = 1;
                mem[i] = { p1.i, p1.s };
                if (!p1.s) q1.push(Node(p1.i, c[p1.i][1], 1));
                f[i] = f[i-1]+p1.v;
                q1.pop();
                if (c[p1.i][0] < c[p1.i][1]) {
                    ++i;
                    used[p1.i][1] = 1;
                    mem[i] = { p1.i, 1 };
                    f[i] = f[i-1]+c[p1.i][1];
                }
            }
        }
        for (int i = 1; i <= 2*n; ++i) {
            printf("%d%c", f[i], (i == 2*n ? '\n': ' '));
        }
    }
    return 0;
}
