#include <bits/stdc++.h>

using namespace std;

int a[4], op[3], rk[3], tmp[4];

inline int getpoke()
{
    char c;
    cin >> c;
    if(isalpha(c))
    {
        if(c == 'A') return 1;
        else return c-'J'+11;
    }
    else
    {
        if(c == '1')
        {
            c = getchar();
            if(c == '0') return 10;
            else return 1;
        }
        else return c-'0';
    }
}

bool dfs(int cur)
{
    if(cur == 1) return a[0] == 24;
    for(int i = 0; i < cur; ++i)
    {
        for(int j = i+1; j < cur; ++j)
        {
            int x = a[i], y = a[j];
            a[j] = a[cur-1];
            a[i] = x+y;
            if(dfs(cur-1)) return true;
            a[i] = x-y;
            if(dfs(cur-1)) return true;
            a[i] = x*y;
            if(dfs(cur-1)) return true;
            a[i] = y-x;
            if(dfs(cur-1)) return true;
            if(y && x%y == 0)
            {
                a[i] = x/y;
                if(dfs(cur-1)) return true;
            }
            if(x && y%x == 0)
            {
                a[i] = y/x;
                if(dfs(cur-1)) return true;
            }
            a[i] = x; a[j] = y;
        }
    }
    return false;
}

int main()
{
    while((a[0] = getpoke()) > 0 && a[0] < 14)
    {
        for(int i = 1; i < 4; ++i) a[i] = getpoke();
        cout << (dfs(4) ? "Yes" : "No") << endl;
    }
    return 0;
}