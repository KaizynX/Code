#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e5+7;

int n;
long long B, ans;

struct Cho
{
    long long p, c;
    bool operator < (const Cho &b) const
    {
        return p < b.p;
    }
} a[Maxn];

int main()
{
    cin >> n >> B;
    for(int i = 0; i < n; ++i)
        cin >> a[i].p >> a[i].c;
    sort(a, a+n);
    long long tmp;
    for(int i = 0; i < n; ++i)
    {
        if(B < a[i].p) break;
        tmp = min(a[i].c, B/a[i].p);
        ans += tmp;
        B -= tmp*a[i].p;
    }
    cout << ans << endl;
    return 0;
}
