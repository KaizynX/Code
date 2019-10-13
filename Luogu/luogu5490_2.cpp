#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+7;

int n, num_x, num_y;
long long res;
int disx[MAXN<<1], disy[MAXN<<1];
vector<int> add[MAXN<<1], del[MAXN<<1];
set<pair<int, int> > cur;

struct Rec
{
    int x1, x2, y1, y2;
} a[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        disx[i*2-1] = a[i].x1;
        disx[i*2] = a[i].x2;
        disy[i*2-1] = a[i].y1;
        disy[i*2] = a[i].y2;
    }
    // discrete
    sort(disx+1, disx+n*2+1);
    sort(disy+1, disy+n*2+1);
    num_x = unique(disx+1, disx+n*2+1)-disx-1;
    num_y = unique(disy+1, disy+n*2+1)-disy-1;
    for (int i = 1; i <= n; ++i) {
        a[i].x1 = lower_bound(disx+1, disx+num_x+1, a[i].x1)-disx;
        a[i].x2 = lower_bound(disx+1, disx+num_x+1, a[i].x2)-disx;
        a[i].y1 = lower_bound(disy+1, disy+num_x+1, a[i].y1)-disy;
        a[i].y2 = lower_bound(disy+1, disy+num_x+1, a[i].y2)-disy;
        add[a[i].x1].push_back(i);
        del[a[i].y1].push_back(i);
    }

    for (int i = 1, now = 0; i <= num_x; ++i) {
        for (int p : add[i]) {
            pair<int, int> tmp = {a[p].y1, a[p].y2};
            if (!cur.size() || a[p].y2 < cur.begin().first || a[p].y1 > cur.rbegin().second) {
                cur.push(tmp);
                now += disy[a[p].y2]-disx[a[p].y1];
            } else {
                // auto pre = cur.lower_bound(tmp), nex = cur.upperbound(tmp);
                int l = 0, r = cur.size()-1;
                while (l < r) {
                    int mid = (l+r)>>1;
                    if ((cur.begin()+mid)->first > );
                }
            }
        }
    }
    printf("%lld\n", res);
    return 0;
}
