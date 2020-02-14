#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;

struct Node
{
    string name;
    int k, t;
    friend istream& operator >> (istream &is, Node &node) {
        static vector<int> tmp;
        is >> node.name >> node.k;
        tmp.resize(node.k);
        for (int i = 0; i < node.k; ++i)
            cin >> tmp[i];
        sort(tmp.begin(), tmp.end());
        node.t = unique(tmp.begin(), tmp.end())-tmp.begin();
        // erase(unique(tmp.begin(), tmp.end(), tag.tmp());
        return is;
    }
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.t == n2.t ? n1.k*n2.t < n2.k*n1.t : n1.t > n2.t;
    }
} a[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= 3; ++i) {
        if (i <= n) cout << a[i].name;
        else cout << '-';
        cout << " \n"[i==3];
    }
    return 0;
}
