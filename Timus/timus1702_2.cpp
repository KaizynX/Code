#include <bits/stdc++.h>
// #define DEBUG1
#define DEBUG2

using namespace std;

const int N = 12;
const int T = 10;

int n[N+3], v[N+3], a[N+3];

#ifdef DEBUG2
inline void print(int x)
{
    bitset<N+1> tmp(x);
    cout << tmp;
}
#endif

inline void init()
{
    for (int i = 1; i <= N; ++i) {
        a[i] = (1<<(N+1))-1;
        a[i] ^= 1<<i;
        if (i%3 == 0) {
            a[i] ^= 1<<((i+3)%12);
            a[i] ^= 1<<((i+3-1)%12);
            a[i] ^= 1<<((i+6-1)%12);
            a[i] ^= 1<<((i+6-2)%12);
            a[i] ^= 1<<((i+9)%12);
            a[i] ^= 1<<((i+9-1)%12);
        } else if (i%3 == 1) {
            a[i] ^= 1<<((i-3+12+1)%12);
            a[i] ^= 1<<((i+6+2)%12);
        } else if (i%3 == 2) {
            a[i] ^= 1<<((i+3)%12);
            a[i] ^= 1<<((i+3-1)%12);
            a[i] ^= 1<<((i+3+1)%12);
            a[i] ^= 1<<((i+6+1)%12);
            a[i] ^= 1<<((i+9)%12);
            a[i] ^= 1<<((i+9+1)%12);
        }
    }
}

void greedy(int s)
{
    int maxi = 0;
    for (int i = 1; i <= N; ++i) {
        if (s&(1<<i) && (!maxi || n[i] > n[maxi]))
            maxi = i;
    }
    if (!maxi || !n[maxi]) return;
    n[maxi] = max(n[maxi]-v[maxi], 0);
#ifdef DEBUG1
    cout << maxi << " ";
#endif
    greedy(s&a[maxi]);
}

int main()
{
    init();
#ifdef DEBUG2
    for (int i = 1; i <= N; ++i) {
        print(a[i]);
        cout << endl;
    }
#endif
    for (int i = 1; i <= N; ++i) cin >> n[i];
    for (int i = 1; i <= N; ++i) cin >> v[i];
    for (int t = 0; t < T; ++t) {
        greedy((1<<(N+1))-1);
#ifdef DEBUG1
        cout << endl;
#endif
    }
    int res = 0;
    for (int i = 1; i <= N; ++i)
        res = max(res, n[i]);
    cout << res << endl;
    return 0;
}
