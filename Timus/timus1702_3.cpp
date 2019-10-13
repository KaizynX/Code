#include <bits/stdc++.h>

using namespace std;

const int N = 12;
const int T = 10;

int n[N], v[N], a[N];

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
}

void greedy(int s)
{
    int maxi = -1;
    for (int i = 0; i < N; ++i) {
        if (s&(1<<i) && (maxi == -1 || n[i] > n[maxi]))
            maxi = i;
    }
    if (maxi == -1 || !n[maxi]) return;
    n[maxi] = max(n[maxi]-v[maxi], 0);
    greedy(s&a[maxi]);
}

int main()
{
    init();
    for (int i = 0; i < N; ++i) cin >> n[i];
    for (int i = 0; i < N; ++i) cin >> v[i];
    for (int t = 0; t < T; ++t) {
        greedy((1<<N)-1);
    }
    int res = 0;
    for (int i = 0; i < N; ++i)
        res = max(res, n[i]);
    cout << res << endl;
    return 0;
}
