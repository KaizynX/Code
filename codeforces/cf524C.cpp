#include <bits/stdc++.h>

using namespace std;

typedef pair<long long, long long> pr;
int t, n, m, x[10], y[10];

int getcol(int nx, int ny) // 1 black 0 white
{
    return (nx+ny)&1;
}

pr getnum(int lx, int ly, int rx, int ry) // white & black
{
    int lenx = rx-lx+1, leny = ry-ly+1;
    long long sum = 1ll*lenx*leny;
    if(lenx%2 == 0 || leny%2 == 0)
        return make_pair(sum/2, sum/2);
    else
    {
        if(getcol(lx, ly)) return make_pair(sum/2, sum/2+1);
        else return make_pair(sum/2+1, sum/2);
    }
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cin >> x[1] >> y[1] >> x[2] >> y[2];
        cin >> x[3] >> y[3] >> x[4] >> y[4];
        x[5] = max(x[1], x[3]);
        y[5] = max(y[1], y[3]);
        x[6] = min(x[2], x[4]);
        y[6] = min(y[2], y[4]);
        pr res = getnum(1, 1, m, n);
        // print the second(b) to w
        pr ptw = getnum(x[1], y[1], x[2], y[2]);
        // print the first(w) to b
        pr ptb = getnum(x[3], y[3], x[4], y[4]);
        res.first += ptw.second-ptb.first;
        res.second += -ptw.second+ptb.first;
        if(x[5] <= x[6] && y[5] <= y[6])
        {
            pr ptc = getnum(x[5], y[5], x[6], y[6]);
            // reprint the first(w) to b & second(b) to w
            res.first += ptc.first-ptc.second;
            res.second += -ptc.first+ptc.second;
            // print the first(w) to b
            res.first -= ptc.first;
            res.second += ptc.first;
        }
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}
