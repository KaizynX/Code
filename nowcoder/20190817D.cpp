#include <bits/stdc++.h>

using namespace std;

int p_check[100007], prime[100007], p_has[100007], p_p_cnt;

inline void init()
{
    p_check[1] = true;
    for (int i = 2; i <= 100000; ++i) {
        if (!p_check[i]) prime[++p_cnt] = i;
        for (int j = 1; j <= p_cnt && i*prime[j] <= n; ++j) {
            p_check[ i*prime[j] ] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

inline bool check(int arr[], int lena)
{
    for (int i = 1; i <= lena; ++i) {
        int p = lower_bound(prime+1, prime+p_cnt+1, int(sqrt(arr[i])+0.5))-prime;
    }
}

int main()
{
    init();
    check();
    return 0;
}
