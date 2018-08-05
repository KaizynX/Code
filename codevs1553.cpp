#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

const int Maxn = 1e5+7;

int n, p, ans, a[Maxn];
map<int, bool> mmp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a+n);
    ans = n;
    for(int i = 0; i < n; ++i)
    {
        if(mmp.count(a[i])) --ans;
        else mmp.insert(make_pair(a[i]*p, true));
    }
    cout << ans << endl;
    return 0;
}
