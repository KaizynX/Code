#include <bits/stdc++.h>
//#define DEBUG

using namespace std;

const int MAXN = 1e5+7;

int T, n;
long long x[MAXN], y[MAXN];

struct Node
{
    int i;
    long long v;
    Node () {}
    Node (int _i, long long _v) : i(_i), v(_v) {}
    bool operator < (const Node &nex) const { return v < nex.v; }
};

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        priority_queue<Node> sing, cros;
        for (int i = 1; i <= n; ++i) {
            scanf("%lld%lld", x+i, y+i);
            sing.push(Node(i, x[i]));
            cros.push(Node(i, y[i]));
        }
        Node cur_s = sing.top(), cur_c = cros.top();
        sing.pop(); cros.pop();
        if (cur_s.i == cur_c.i) {
            printf("%lld\n", min(abs(cur_s.v-cros.top().v), abs(cur_c.v-sing.top().v)));
            continue;
        }
        long long res = abs(cur_s.v-cur_c.v);
        while (sing.size() && cros.size()) {
#ifdef DEBUG
            printf("sing:%d %lld cros:%d %lld\n", cur_s.i, cur_s.v, cur_c.i, cur_c.v);
#endif
            if (res == 0) break;
            if (cur_s.v > cur_c.v) {
                if (y[cur_s.i] > cur_c.v) break;
                cur_s = sing.top();
                sing.pop();
                if (cur_s.i == cur_c.i) {
                    if (!sing.size()) break;
                    cur_s = sing.top();
                    sing.pop();
                    /*
                    res = min(res, abs(cur_s.v-cur_c.v));
                    break;
                    */
                }
            }else {
                if (x[cur_c.i] > cur_s.v) break;
                cur_s = sing.top();
                cur_c = cros.top();
                cros.pop();
                if (cur_s.i == cur_c.i) {
                    if (!cros.size()) break;
                    cur_c = cros.top();
                    cros.pop();
                    /*
                    res = min(res, abs(cur_s.v-cur_c.v));
                    break;
                    */
                }
            }
            res = min(res, abs(cur_s.v-cur_c.v));
        }
        printf("%lld\n", res);
    }
    return 0;
}
