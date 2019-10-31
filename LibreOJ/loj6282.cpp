#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;

struct FenKuai
{
    typedef int T;
    int t, sz; // 每组大小
    static const int NN = static_cast<int>(sqrt(N))+7;
    T a[N];
    deque<int> q[NN];

    void init(int _n)
    {
        sz = _n;
        t = static_cast<int>(sqrt(sz*1.5)+0.5);
        for (int i = 0; i < sz; ++i) q[i/t].push_back(a[i]);
    }

    void update(int x, int k)
    {
        stack<int> tmp;
        for (int i = 0; i != x%t; ++i) {
            tmp.push(q[x/t].front());
            q[x/t].pop_front();
        }
        q[x/t].push_front(k);
        while (tmp.size()) {
            q[x/t].push_front(tmp.top());
            tmp.pop();
        }
        ++sz;
        if (sz/t == x/t) return;
        for (int i = x/t, val; i < sz/t; ++i) {
            val = q[i].back();
            q[i].pop_back();
            q[i+1].push_front(val);
        }
    }

    T query(int x)
    {
        stack<int> tmp;
        for (int i = 0; i != x%t; ++i) {
            tmp.push(q[x/t].front());
            q[x/t].pop_front();
        }
        int res = q[x/t].front();
        while (tmp.size()) {
            q[x/t].push_front(tmp.top());
            tmp.pop();
        }
        return res;
    }
} B;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &B.a[i]);
    B.init(n);
    for (int i = 0, op, l, r, c; i < n; ++i) {
        scanf("%d %d %d %d", &op, &l, &r, &c);
        if (op) {
            printf("%d\n", B.query(r-1));
        } else {
            B.update(l-1, r);
        }
    }
    return 0;
}
