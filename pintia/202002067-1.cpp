#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int y, n;

inline int count(const int &x)
{
    static map<int, int> mp;
    mp.clear();
    mp[x/1000] = 1;
    mp[x/100%10] = 1;
    mp[x/10%10] = 1;
    mp[x%10] = 1;
    return mp.size();
}

int main()
{
    int cnt = 0;
    scanf("%d%d", &y, &n);
    while (count(y) != n) ++y, ++cnt;
    printf("%d %04d\n", cnt, y);
    return 0;
}
