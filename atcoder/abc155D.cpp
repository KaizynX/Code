#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const long long INF = 1e18;
const double eps = 1e-11;
typedef pair<int, int> pii;

int n;
long long k, zero;
long long a[N];
vector<long long> pos, neg;

// return the number of product <= mid
inline long long count(const long long &mid)
{
    long long cnt = 0;
    for (int i = 1; i < n; ++i)
        cnt += upper_bound(a, a+i, mid/a[i])-a;
    return cnt;
}

inline void solve()
{
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        if (!a[i]) ++zero;
        else if (a[i] < 0) neg.emplace_back(a[i]);
        else if (a[i] > 0) pos.emplace_back(a[i]);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    // warning : could it run out of data range?
    long long num_neg = neg.size()*pos.size(),
              // num_pos = pos.size()*(pos.size()-1)/2+neg.size()*(neg.size()-1)/2,
              num_zero = zero*(zero-1)/2+zero*neg.size()+zero*pos.size();
    if (k > num_neg && k <= num_neg+num_zero) { cout << 0 << endl; return; }
    long long l, r, mid, cnt;
    if (k <= num_neg) {
        l = -INF; r = -1;
        while (l < r) {
            mid = (l+r+1)/2;
            cnt = 0;
            // the number < mid
            for (long long i : neg) {
                int p = upper_bound(pos.begin(), pos.end(), mid/i)-pos.begin();
                cnt += pos.size()-p;
            }
            if (cnt < k) l = mid;
            else r = mid-1;
        }
    } else {
        l = 1; r = INF;
        k -= num_neg+num_zero;
        while (l < r) {
            mid = (l+r)>>1;
            cnt = 0;
            // the number <= mid
            for (int i = 1; i < (int)pos.size(); ++i) {
                int p = upper_bound(pos.begin(), pos.begin()+i, mid/pos[i])-pos.begin();
                cnt += p;
            }
            for (int i = 1; i < (int)neg.size(); ++i) {
                int p = lower_bound(neg.begin(), neg.begin()+i, mid/neg[i])-neg.begin();
                cnt += i-p;
            }
            if (cnt < k) l = mid+1;
            else r = mid;
        }
    }
    cout << l << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}