#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

const int Maxn = 2e5+7;

int len, ans, cnt = 1, a[Maxn], res[Maxn] = {0, 1};
map<string, bool> mmp;

inline void read(int &x)
{
    char c;
    while((c=getchar()) < '0' || c > '9');
    x = c-'0';
    while((c=getchar()) >= '0' && c <= '9') 
        x = (x<<1)+(x<<3) + c-'0';
}

int main()
{
    read(len);
    int *vis = new(int[Maxn]);
    memset(vis, 0, sizeof(int)*Maxn);
    for(int i = 1; i <= len; ++i)
    {
        read(a[i]);
        if(!vis[a[i]]) ++ans;
        vis[a[i]] = 1;
    }
    delete[] vis;

    string cur;
    for(int k = 2, tmp; len/k >= ans; ++k)
    {
        tmp = 0;
        cur.clear();
        mmp.clear();
        for(int i = 1, edge = (len/k*k); i <= edge; ++i)
        {
            cur.push_back(a[i]);
            if(i%k == 0)
            {
                if(!mmp.count(cur))
                {
                    ++tmp;
                    mmp.insert(make_pair(cur, true));
                    reverse(cur.begin(), cur.end());
                    mmp.insert(make_pair(cur, true));
                }
                cur.clear();
            }
        }
        if(tmp > ans)
        {
            ans = tmp;
            cnt = 1;
            res[1] = k;
        }
        else if(tmp == ans)
            res[++cnt] = k;
    }
    printf("%d %d\n%d", ans, cnt, res[1]);
    for(int i = 2; i <= cnt; ++i) printf(" %d", res[i]);
    return 0;
}

