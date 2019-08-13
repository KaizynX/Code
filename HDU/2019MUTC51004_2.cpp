#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int T, N, C;
vector<double> res;

struct Node
{
    int a, b;
    double zero;
    
    void init()
    {
        // ax+b = 0
        // x = -b/a
        zero = -1.0*b/a;
    }

    bool operator < (const Node &nex) const
    {
        return zero < nex.zero;
    }
}d[Maxn];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        int sa = 0, sb = 0;
        double now;
        res.clear();
        scanf("%d%d", &N, &C);
        for(int i = 0; i < N; ++i)
        {
            scanf("%d%d", &d[i].a, &d[i].b);
            d[i].init();
            sa -= d[i].a;
            sb -= d[i].b;
        }
        sort(d, d+N);
        // first
        if(sa == 0 && sb == C) // infinite
        {
            printf("-1\n");
            continue;
        }
        if(sa != 0)
        {
            now = 1.0*(C-sb)/sa;
            if(now <= d[0].zero) res.push_back(now);
        }
        for(int i = 1; i < N; ++i)
        {
            sa += d[i-1].a*2;
            sb += d[i-1].b*2;
            // sa*x+sb = C
            // x = (C-sb)/sa
            now = 1.0*(C-sb)/sa;
            if(now > d[i-1].zero && now <= d[i].zero)
                res.push_back(now);
        }
        // last
        if(sa == 0 && sb == C) // infinite
        {
            printf("-1\n");
            continue;
        }
        if(sa != 0)
        {
            sa += d[N-1].a*2;
            sb += d[N-1].b*2;
            now = 1.0*(C-sb)/sa;
            if(now > d[N-1].zero) res.push_back(now);
        }

        if(res.empty())
        {
            printf("0\n");
            continue;
        }
        printf("%d ", res.size());
        for(int i = 0; i < res.size()-1; ++i) printf("%f ", res[i]);
        printf("%f\n", res.back());
    }
    return 0;
}
