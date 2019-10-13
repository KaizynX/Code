#include <bits/stdc++.h>

using namespace std;

const int N = 12;
const int T = 10;
const int INF = 1e3;

int res = INF;
int n[N], v[N], a[N];
unordered_map<int, int> lg;

inline void init()
{
    for (int i = 0; i < N; ++i) {
        lg[1<<i] = i;
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

inline int lowbit(int x) { return x&-x; }
void greedy(int);
void brute(int, int);

inline void update()
{
    int tmp = 0;
    for (int i = 0; i < N; ++i)
        tmp = max(tmp, n[i]);
    res = min(res, tmp);
}

void greedy(int t)
{
    if (t >= T) {
        update();
        return;
    }

    int maxi = 0;
    for (int i = 1; i < N; ++i) {
        if (n[i] > n[maxi])
            maxi = i;
    }
    if (n[maxi] <= 0) {
        update();
        return;
    }
    if (n[maxi] - v[maxi]*(T-t) >= res) return;
    n[maxi] -= v[maxi];
    brute(((1<<N)-1)&a[maxi], t);
    n[maxi] += v[maxi];
}

void brute(int s, int t)
{
    int flag = 1;
    /*
    for (int i = 0; i < N; ++i) {
        if ((s&(1<<i)) && n[i] > 0) {
            flag = 0;
            n[i] -= v[i];
            brute(s&a[i], t);
            n[i] += v[i];
        }
    }
    */
    ///*
    for (int x = s, i; x; x -= lowbit(x)) {
        i = lg[lowbit(x)];
        if (n[i] <= 0) {
            s ^= x;
            continue;
        }
        flag = 0;
        n[i] -= v[i];
        brute(s&a[i], t);
        n[i] += v[i];
    }
    //*/
    if (flag) greedy(t+1);
}

int main()
{
    init();
    for (int i = 0; i < N; ++i) cin >> n[i];
    for (int i = 0; i < N; ++i) cin >> v[i];
    greedy(0);
    cout << res << endl;
    return 0;
}
