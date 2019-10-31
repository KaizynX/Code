#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 1e4+7;

int n, k, cnt;
bool check[N];
int a[N], prime[M], fp[N];
long long res;
map<vector<pair<int, int>>, int> mp;

inline void init()
{
    check[1] = true;
    for(int i = 2; i < N; ++i)
    {
        if(!check[i]) {
            ++cnt;
            prime[cnt] = i;
            fp[i] = cnt;
        }
        for(int j = 1; j <= cnt && i*prime[j] < N; ++j)
        {
            check[ i*prime[j] ] = true;
            if(i % prime[j] == 0) break;
        }
    }
}

int main()
{
    cin >> n >> k;
    init();
    for (int i = 1, a, pi; i <= n; ++i) {
        cin >> a;
        // 分解质因数
        vector<pair<int, int>> my_hash, rev_hash;
        for (int j = 1; prime[j]*prime[j] <= a; ++j) {
            if (a%prime[j]) continue;
            pi = 0;
            while (a%prime[j] == 0) a /= prime[j], ++pi;
            pi %= k;
            // a[i] = sum prime[j]^pi
            if (pi) {
                my_hash.push_back({j, pi});
                rev_hash.push_back({j, k-pi});
            }
        }
        if (a > 1) {
            my_hash.push_back({fp[a], 1});
            rev_hash.push_back({fp[a], k-1});
        }
        res += mp[rev_hash];
        ++mp[my_hash];
    }
    cout << res << endl;
    return 0;
}
