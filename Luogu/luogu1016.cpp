#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 10;

double D1, C, D2, ans;
int n;
struct Node
{
    double d, p;
    bool operator < (const Node &b) const
    {
        return d < b.d;
    }
} a[Maxn];

int main()
{
    cin >> D1 >> C >> D2 >> a[0].p >> n;
    a[n+1].d = D1;
    for(int i = 1; i <= n; ++i)
        cin >> a[i].d >> a[i].p;
    sort(a+1, a+n+1);
    for(int i = 1; i <= n+1; ++i)
    {
        if(a[i].d-a[i-1].d > C*D2)
        {
            cout << "No Solution" << endl;
            return 0;
        }
    }
    double lastd, lastp = 555;
    for(int i = 0; i <= n; ++i)
    {
        if(a[i].p <= lastp)
        {
            lastp = a[i].p;
            lastd = a[i].d + C*D2;
            // drive to next d
            ans += (a[i+1].d-a[i].d)/D2*a[i].p;
        }
        else if(lastd >= a[i+1].d)
        {
            ans += (a[i+1].d-a[i].d)/D2*lastp;
        }
        else
        {
            ans += (lastd-a[i].d)/D2*lastp;
            ans += (a[i+1].d-lastd)/D2*a[i].p;
            lastp = a[i].p;
            lastd = a[i].d + C*D2;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
