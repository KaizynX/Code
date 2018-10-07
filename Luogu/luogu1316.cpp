#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e5+7;
const int INF = 0x7fffffff;

int n, k, a[Maxn];

inline bool check(int mid)
{
    int last = a[1], cnt = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(a[i] - last >= mid)
        {
            last = a[i];
            if(++cnt >= k) return true;
        }
    }
    return cnt >= k;
}

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a+1, a+n+1);
    int l = 0, r = a[n]-a[1], mid;
    while(l < r)
    {
        mid = (l+r+1) >> 1;
        if(check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l << endl;
    return 0;
}
