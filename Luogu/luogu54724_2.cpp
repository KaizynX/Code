#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;

int n, m, x, y, q;
char a[Maxn][Maxn];

struct Node
{
    long long HP, STR, DEF;
} hero, enemy;

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void write(T x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

int main()
{
    read(n); read(m);
    for(int i = 1; i <= n; ++i)
        scanf("%s", a[i]+1);
    read(enemy.HP); read(enemy.STR); read(enemy.DEF);
    read(x); read(y);
    read(hero.STR); read(hero.DEF);
    read(q);
    char op;
    while(q--)
    {
        while((op=getchar()) != 'Q' && op != 'M');
        if(op == 'Q')
        {
            write(hero.HP); putchar(' ');
            write(hero.STR); putchar(' ');
            write(hero.DEF); putchar(' ');
            putchar('\n');
        }
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
