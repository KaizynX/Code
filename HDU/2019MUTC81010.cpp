#include <bits/stdc++.h>

using namespace std;

const int kN = 1e5+7;

int T, n, d;

struct Team
{
    char s[20];
    int p, t;
    bool operator < (const Team &nex) const
    {
        return p == nex.p ? t < nex.t : p > nex.p;
    }
} a[kN];

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &d);
        for (int i = 1; i <= n; ++i)
            scanf("%s%d%d", a[i].s, &a[i].p, &a[i].t);
        if (n*d%10 != 5) {
            printf("Quailty is very great\n");
        } else {
            // sort(a+1, a+n+1);
            int id = n*d/10+1;
            nth_element(a+1, a+id, a+n+1);
            printf("%s\n", a[id].s);
        }
    }
    return 0;
}
