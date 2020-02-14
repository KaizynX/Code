#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;

struct Node
{
    long long a, b;
    Node(){ a = 0; b = 1; }
    void read() {
        scanf("%lld/%lld", &a, &b);
    }
    void print() {
        if (!a) puts("0");
        else if (b == 1) printf("%lld\n", a);
        else if (a < b) printf("%lld/%lld\n", a, b);
        else printf("%lld %lld/%lld\n", a/b, a%b, b);
    }
    friend Node operator + (const Node &n1, const Node &n2) {
        Node res;
        long long g = __gcd(n1.b, n2.b);
        res.b = n1.b/g*n2.b;
        res.a = n2.b/g*n1.a+n1.b/g*n2.a;
        g = __gcd(res.a, res.b);
        res.a /= g; res.b /= g;
        if (!res.a) res.b = 1;
        return res;
    }
    Node operator += (const Node &node) { return  *this = *this+node; }
};

int n;

int main()
{
    scanf("%d", &n);
    Node res, tmp;
    for (int i = 1; i <= n; ++i) {
        tmp.read();
        res += tmp;
#ifdef DEBUG
        res.print();
#endif
    }
    res.print();
    return 0;
}
