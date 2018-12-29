#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e5+7;
const int Maxa = 1e9+7;

int n;
int a[Maxn];

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l+r)>>1, flag = 0;
        vector<pair<int, int> > v;
        for(int i = 1; i < n; ++i)
            if(a[i] <= a[i-1])
            {
                if(mid <= 1) { flag = 1; break; }
                while(v.size() && v.back().first >= a[i])
                    v.pop_back();
                int cur = a[i]-1;
                while(cur >= 0 && v.size() && v.back().first == cur && v.back().second == mid-1)
                    v.pop_back(), cur--;
                if(cur < 0) { flag = 1; break; }
                if(v.empty() || v.back().first < cur)
                    v.push_back(make_pair(cur, 1));
                else v.back().second++;
            }

        if(flag) l = mid+1;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}
