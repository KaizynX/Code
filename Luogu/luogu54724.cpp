#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;

int n, m, x, y, q;
char a[Maxn][Maxn];

struct Node
{
    long long HP, STR, DEF;
} hero, enemy;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> a[i][j];
    scanf("%lld%lld%lld", &enemy.HP, &enemy.STR, &enemy.DEF);
    scanf("%d%d", &x, &y);
    scanf("%lld%lld", &hero.STR, &hero.DEF);
    scanf("%d", &q);

    while(q--)
    {
        char op;
        cin >> op;
        if(op == 'Q') printf("%lld %lld %lld\n", hero.HP, hero.STR, hero.DEF);
        else if(op == 'M')
        {
            cin >> op;
            if(op == 'N') x--;
            else if(op == 'S') x++;
            else if(op == 'W') y--;
            else if(op == 'E') y++;

            if(a[x][y] == 'M')
                hero.HP += max(1ll, (long long)(ceil((double)enemy.HP/max(1ll, hero.STR-enemy.DEF))*max(1ll, enemy.STR-hero.DEF)));
            else if(a[x][y] == 'R') hero.HP = max(0ll, hero.HP-10);
            else if(a[x][y] == 'Q') hero.STR += 5;
            else if(a[x][y] == 'Y') hero.DEF += 5;
        }
    }
    return 0;
}
