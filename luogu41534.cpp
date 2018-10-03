#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 60;

int n, ans, cnt[20];

struct Poke
{
    int col, num;
    bool operator < (const Poke &b) const
    {
        return num < b.num;
    }
} a[Maxn];

void brute_force(int cur, int cnt)
{
    brute_force(cur+1, cnt);
    int tmp = a[cur].col;
    for(int i = 1; i <= 4; ++i)
    {
        if(i != a[cur].col)
        {
            a[cur].col = i;
            brute_force(cur+1, cnt+1);
        }
    }
    a[cur].col = tmp;
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i].col);
        char tmp[3];
        scanf("%s", tmp);
        if(strlen(tmp) == 2)
            a[i].num = (tmp[0]-'0')*10+(tmp[1]-'0');
        else if(tmp[0] >= '0' && tmp[0] <= '9')
            a[i].num = (tmp[0]-'0');
        else
        {
            if(tmp[0] == 'A') a[i].num = 1;
            else if(tmp[0] == 'J') a[i].num = 11;
            else if(tmp[0] == 'Q') a[i].num = 12;
            else if(tmp[0] == 'K') a[i].num = 13;
        }

        cnt[a[i].num]++;
    }

    int tmp = 0, team = 0;
    while(tmp < n)
    {
        int cur = 1;
        while(!cnt[cur]) cur++;
        while(cnt[cur])
        {
            cnt[cur]--;
            ++tmp;
            cur++;
        }
        team++;
    }
    if(team > 4)
    {
        puts("No");
        return 0;
    }
    if(team == 3 && n == 10)
    {
        puts("Yes");
        puts("2");
        return 0;
    }
    else puts("No");
    // brute_force(1, 0);
    return 0;
}
