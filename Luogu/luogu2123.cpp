#include <bits/stdc++.h>

using namespace std;

const int N = 2e4+7;

int T, n;

struct Node
{
    int a, b;
    friend bool operator < (const Node &n1, const Node &n2) {
        return (n1.a-n1.b) < (n2.a-n2.b);
    }
    friend istream &operator >> (istream &is, Node &node) {
        return is >> node.a >> node.b;
    }
} a[N];

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        long long c = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += a[i].a;
            c = max(sum, c)+a[i].b;
        }
        cout << c << endl;
    }
    return 0;
}
