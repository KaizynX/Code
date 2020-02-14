#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m, head;
map<int, int> mp;

struct Node
{
    int add, dat, nex;
    friend istream& operator >> (istream &is, Node &node) {
        return is >> node.add >> node.dat >> node.nex;
    }
} a[N], b[N], c[N];

int main()
{
    cin >> head >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        mp[a[i].add] = i;
    }
    for (int i = 1, cur = mp[head]; cur; ++i, cur = mp[a[cur].nex]) {
        c[i] = a[cur];
        m = i;
    }
    for (int i = 1; i <= m; ++i) {
        if (i <= m/2) b[i*2] = c[i];
        else b[(m-i)*2+1] = c[i];
    }
    for (int i = 1; i <= m; ++i) {
        printf("%05d %d ", b[i].add, b[i].dat);
        if (i == m) puts("-1");
        else printf("%05d\n", b[i+1].add);
        //cout << b[i].add << " " << b[i].dat << " ";
        //cout << (i == n ? -1 : b[i+1].add) << endl;
    }
    return 0;
}
