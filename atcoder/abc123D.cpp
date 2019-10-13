#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int k;
int n[3];
long long a[3][N];
map<int, int> vis;

struct Node
{
    int id[3];
    long long sum;
    Node(int i0, int i1, int i2, long long s) : sum(s) {
        id[0] = i0; id[1] = i1; id[2] = i2;
    }
    bool operator < (const Node &nex) const { return sum < nex.sum; }
};

priority_queue<Node> q;

inline int my_hash(Node &x)
{
    return x.id[0]*1000000+x.id[1]*1000+x.id[2];
}

int main()
{
    for (int i = 0; i < 3; ++i) cin >> n[i];
    cin >> k;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n[i]; ++j)
            cin >> a[i][j];
        sort(a[i], a[i]+n[i]);
        reverse(a[i], a[i]+n[i]);
    }
    int cnt = 0;
    q.push(Node(0, 0, 0, a[0][0]+a[1][0]+a[2][0]));
    while (q.size() && cnt < k) {
        Node cur = q.top();
        q.pop();
        cout << cur.sum << endl;
        ++cnt;

        for (int i = 0; i < 3; ++i) {
            if (cur.id[i]+1 >= n[i]) continue;
            cur.sum -= a[i][cur.id[i]];
            ++cur.id[i];
            cur.sum += a[i][cur.id[i]];
            if (!vis.count(my_hash(cur))) {
                vis.insert({my_hash(cur), 1});
                q.push(cur);
            }
            cur.sum -= a[i][cur.id[i]];
            --cur.id[i];
            cur.sum += a[i][cur.id[i]];
        }
    }
    return 0;
}
