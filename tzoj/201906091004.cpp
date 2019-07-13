#include <bits/stdc++.h>

using namespace std;

int T, m, cnt;
long long n, ans;
int a[17];

int gcd(int a, int b)
{
    return b ? gcd(b, a%b) : a;
}

void f(int cur, int num, int gccd)
{
    if(cur > cnt)
    {
        if(!num) return;
        ans += num&1 ? -n/gccd : n/gccd;
        return;
    }
    f(cur+1, num, gccd);
    f(cur+1, num+1, gcd(a[cur], gccd));
}

int main()
{
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        cnt = 0; ans = n;
        map<int, int> mmp;
        for(int i =  1, tmp; i <= m; ++i)
        {
            cin >> tmp;
            ++mmp[tmp];
        }
        for(map<int, int>::iterator it = mmp.begin(); it != mmp.end(); ++it)
            if(it->second & 1) a[++cnt] = it->first;
        f(1, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
