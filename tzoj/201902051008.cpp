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

inline int ope(int x, int y, int o)
{
    if(o == 0) return x+y;
    if(o == 1) return x-y;
    if(o == 3) return x*y;
    return x%y ? 0 : x/y;
}

inline bool judge()
{
    queue<int> q;
    for(int i = 0; i < 3; ++i) rk[i] = i;
    if(ope(ope(ope(a[0], a[1], op[0]), a[1], op[1]), a[2], op[2]) == 24) return true; // 0 1 2
    if(ope(ope(a[0], a[1], op[0]), ope(a[2], a[3], op[2]), op[1]) == 24) return true; // 0 2 1
    if(ope(ope(a[0], ope(a[1], a[2], op[1]), op[0]), a[3], op[2]) == 24) return true; // 1 0 2
    if(ope(a[0], ope(ope(a[1], a[2], op[1]), a[3], op[2]), op[0]) == 24) return true; // 1 2 0
    if(ope(ope(a[0], a[1], op[0]), ope(a[2], a[3], op[2]), op[1]) == 24) return true; // 2 0 1
    if(ope(a[1], ope(a[1], ope(a[2], a[3], op[2]), op[1]), op[0]) == 24) return true; // 2 1 0
}

bool f(int cur)
{
    if(cur >= 3) return judge();
    int flag = 0;
    // 0 1 2 3
    // + - * /
    for(int i = 0; i < 4; ++i)
    {
        op[cur] = i;
        flag = f(cur+1);
        if(flag) return true;
    }
    return false;
}

int main()
{
    while(a[0] = getpoke())
    {
        int flag = 0;
        for(int i = 1; i < 4; ++i) a[i] = getpoke();
        do
        {
            flag = f(0);
            if(flag) break;
        } while (next_permutation(a, a+4));
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}