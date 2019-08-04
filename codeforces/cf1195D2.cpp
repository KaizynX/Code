#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int Mo = 998244353;

int n;
int a[Maxn], cnt[20];
unsigned long long res = 0;

int main()
{
    cin >> n;
    for(int i = 1, tmp, cc; i <= n; ++i)
    {
        cin >> a[i];
        cc = 0;
        tmp = a[i];
        while(tmp)
        {
            tmp /= 10;
            cc++;
        }
        cnt[cc]++;
    }
    for(int i = 1, tmp; i <= n; ++i)
    {
        vector<int> _slip;
        tmp = a[i];
        while(tmp)
        {
            _slip.push_back(tmp%10);
            tmp /= 10;
        }
        reverse(_slip.begin(), _slip.end());
        for(int l = 1, j; l <= 10; ++l)
        {
            unsigned long long v1 = 0, v2 = 0;
            j = 0;
            if(_slip.size() > l)
            {
                for(; j < _slip.size()-l; ++j)
                    v2 = v1 = v1*10+_slip[j];
            }
            for(; j < _slip.size(); ++j)
            {
                v1 = (v1*10+_slip[j])*10;
                v2 = v2*100+_slip[j];
            }
            res += (v1%Mo)*cnt[l]%Mo + (v2%Mo)*cnt[l]%Mo;
            res %= Mo;
        }
    }
    cout << res << endl;
    return 0;
}
