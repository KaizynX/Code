#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int kN = 1e6+7;

int T, n;
long long ans, rest, people;

struct Node
{
    int a, b;
    bool operator < (const Node &nex) const {
        return b-a > nex.b-nex.a;
    }
} c[kN];

template <typename T1, typename T2> inline void Feed(T1 &food, T2 &person)
{
    if (food >= person) {
        food -= (T1)person;
        ans += person;
        person = 0;
    } else {
        person -= (T2)food;
        ans += food;
        food = 0;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ans = rest = people = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &c[i].a, &c[i].b);
        sort(c+1, c+n+1);
        for (int i = 1; i <= n; ++i) {
            Feed(c[i].b, people);
            Feed(rest, c[i].a);
            people += c[i].a;
            rest += c[i].b;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
