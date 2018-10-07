#include <iostream>
#include <map>

using namespace std;

const int Maxn = 40;

int n, m, ans, a[Maxn];
map<int, int> ml, mr;

void dfs(int cur, int edge, int now, int choose, map<int, int> &mmp)
{
    if(cur > edge)
    {
        if(mmp.count(now)) mmp[now] = min(mmp[now], choose);
        else mmp.insert(make_pair(now, choose));
        return;
    }
    if(now > m) return;
    dfs(cur+1, edge, now+a[cur], choose+1, mmp);
    dfs(cur+1, edge, now, choose, mmp);
}

int main()
{
    cin >> n >> m;
    ans = n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    int mid = n/2;
    dfs(1, mid, 0, 0, ml);
    dfs(mid+1, n, 0, 0, mr);
    for(map<int, int>::iterator it = ml.begin(); it != ml.end(); it++)
    {
        int tmp = m - it->first;
        if(mr.count(tmp)) ans = min(ans, it->second + mr[tmp]);
    }
    cout << ans << endl;
    return 0;
}
