#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 12;
const int T = 10;
const int INF = 1e3;

int res, l, r, mid;
int n[N], v[N], a[N];
vector<int> tmp;
vector<vector<int>> c;

void build(int s, int last)
{
    int flag = 1;
    for (int i = last; i < N; ++i) {
        if (s&(1<<i)) {
            flag = 0;
            tmp.push_back(i);
            build(s&a[i], i+1);
            tmp.pop_back();
        }
    }
    if (flag && tmp.size() >= 4) {
        c.push_back(tmp);
    }
}

inline void init()
{
    for (int i = 0; i < N; ++i) {
        a[i] = (1<<N)-1;
        a[i] ^= 1<<i;
        if (i%3 == 2) {
            a[i] ^= 1<<((i+3)%N);
            a[i] ^= 1<<((i+3-1)%N);
            a[i] ^= 1<<((i+6-1)%N);
            a[i] ^= 1<<((i+6-2)%N);
            a[i] ^= 1<<((i+9)%N);
            a[i] ^= 1<<((i+9-1)%N);
        } else if (i%3 == 0) {
            a[i] ^= 1<<((i+9+1)%N);
            a[i] ^= 1<<((i+6+2)%N);
        } else if (i%3 == 1) {
            a[i] ^= 1<<((i+3)%N);
            a[i] ^= 1<<((i+3-1)%N);
            a[i] ^= 1<<((i+3+1)%N);
            a[i] ^= 1<<((i+6+1)%N);
            a[i] ^= 1<<((i+9)%N);
            a[i] ^= 1<<((i+9+1)%N);
        }
    }
    build((1<<N)-1, 0);
}

inline void update()
{
    int tmp = 0;
    for (int i = 0; i < N; ++i)
        tmp = max(tmp, n[i]);
    res = min(res, tmp);
}

void brute(int t, int last)
{
    if (t >= T) {
        update();
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (n[i]-v[i]*(T-t) > min(res, mid)) return;
    }

    for (int i = last; i < (int)c.size(); ++i) {
        for (int j : c[i]) n[j] -= v[j];
        brute(t+1, i);
        for (int j : c[i]) n[j] += v[j];
    }
}

void greedy(int t, int last)
{

    if (t >= T) {
        update();
        return;
    }
    int maxi = 0;
    for (int i = 1; i <= N; ++i) {
        if (n[i] > n[maxi]) maxi = i;
        if (n[i]-v[i]*(T-t) > min(res, mid)) return;
    }
    if (n[maxi] <= 0) {
        cout << 0 << endl;
        exit(0);
    }

    for (int i = last; i < (int)c.size(); ++i) {
        int flag = 0;
        for (int j : c[i]) if (j == maxi) flag = 1;
        if (!flag) continue;

#ifdef DEBUG
        for (int j : c[i]) cout << i << " ";
        cout << endl;
#endif
        for (int j : c[i]) n[j] -= v[j];
        greedy(t+1, i);
        for (int j : c[i]) n[j] += v[j];
    }
}

int main()
{
    init();
    for (int i = 0; i < N; ++i) cin >> n[i], r = max(r, n[i]);
    for (int i = 0; i < N; ++i) cin >> v[i];
    while (l < r) {
        mid = (l+r)>>1;
        res = INF;
        brute(0, 0);
        // greedy(0, 0)
        if (res > mid) l = mid+1;
        else break;
    }
    cout << res << endl;
    return 0;
}
