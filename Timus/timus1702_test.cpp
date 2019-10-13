#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 12;
const int T = 10;

int a[N];
vector<int> res;

#ifdef DEBUG
inline void print(int x)
{
    bitset<N> tmp(x);
    cout << tmp << endl;
}
#endif

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
#ifdef DEBUG
        print(a[i]);
#endif
    }
}

void build(int s, int last)
{
    int flag = 1;
    for (int i = last; i < N; ++i) {
        if (s&(1<<i)) {
            flag = 0;
            res.push_back(i+1);
            build(s&a[i], i+1);
            res.pop_back();
        }
    }
    if (flag && res.size() >= 4) {
        for (int i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void build2(int s)
{
    int flag = 1;
    for (int i = 0; i < N; ++i) {
        if (s&(1<<i)) {
            flag = 0;
            res.push_back(i+1);
            build2(s&a[i]);
            res.pop_back();
        }
    }
    if (flag) {
        for (int i : res) {
            cout << i << " ";
        }
        cout << endl;
    }
}

int main()
{
    init();
    build((1<<N)-1, 0);
    // build2((1<<N)-1);
    return 0;
}
