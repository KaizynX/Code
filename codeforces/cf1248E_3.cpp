#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, p;
long long res[N];

struct BinaryIndexedTree
{
    typedef int T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

struct Node
{
    long long t;
    int op, id;
    // op 0 want water, 1 finish water
    Node(){}
    Node(long long _t, int _op, int _id) : t(_t), op(_op), id(_id) {}
    friend bool operator < (const Node &x, const Node &y) {
        if (x.t != y.t) return x.t > y.t;
        if (x.op != y.op) return x.op > y.op;
        return x.id > y.id;
    }
};

priority_queue<Node> time_line;
priority_queue<int, vector<int>, greater<int> > seat;

int main()
{
    cin >> n >> p;
    for (int i = 1, t; i <= n; ++i) {
        cin >> t;
        time_line.push(Node(t, 0, i));
    }
    long long que_time = 0;
    while (time_line.size()) {
        Node cur = time_line.top();
        time_line.pop();
        if (cur.op) {
            BIT.update(cur.id, -1);
            res[cur.id] = cur.t;
        } else {
            seat.push(cur.id);
        }
        if (seat.size() && !BIT.query(seat.top())) {
            que_time = max(cur.t, que_time)+p;
            time_line.push(Node(que_time, 1, seat.top()));
            BIT.update(seat.top(), 1);
            seat.pop();
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " \n"[i==n];
    }
    return 0;
}
