/*
 * @Author: Kaizyn
 * @Date: 2020-09-22 21:39:31
 * @LastEditTime: 2020-09-22 21:39:38
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long big;

const int MAXL = 30;
int a, b, k, w;

big F[MAXL][2][2][2][2][2];

big f(int i, int fa, int fb, int fw, int fm, int fk)
{
    if (i >= MAXL)
        return (fa && fb && fw && !fm && fk);
    else
    {
        big &ans = F[i][fa][fb][fw][fm][fk];
        if (ans == -1)
        {
            ans = 0;
            int ua = (a >> i & 1), ub = (b >> i & 1), uw = (w >> i & 1), uk = (k >> i & 1);
            for (int va = 0; va < 2; va++)
                for (int vb = 0; vb < 2; vb++)
                {
                    int vw = va ^ vb, vk = va ^ fm ^ vb;
                    ans += f(i + 1, fa ? (va <= ua) : (va < ua), fb ? (vb <= ub) : (vb < ub), fw ? (vw <= uw) : (vw < uw),
                        va - fm < vb, fk ? (vk <= uk) : (vk < uk));
                }
        }
        return ans;
    }
}

int main()
{
    int kase;
    scanf("%d", &kase);
    while (kase--)
    {
        scanf("%d%d%d%d", &a, &b, &k, &w);
        memset(F, -1, sizeof(F));
        big ans = f(0, 1, 1, 1, 0, 1);
        swap(a, b);
        memset(F, -1, sizeof(F));
        ans += f(0, 1, 1, 1, 0, 1);
        printf("%lld\n", ans - min(a, b) - 1);
    }
    return 0;
}