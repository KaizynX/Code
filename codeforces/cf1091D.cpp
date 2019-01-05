#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 998244353;

int n, ans = 1;

int main()
{
    //cin >> n;
    int INF;
    cin >> INF;
    for(int n = 1; n <= INF; ++n)
    {
    vector<int> a, p;
    ans = 1;
    for(int i = 1; i <= n; ++i) a.push_back(i);
    do
    {
        p.insert(p.end(), a.begin(), a.end());
    } while(next_permutation(a.begin(), a.end()));
    int l = 0, r = n-1, sum = (1+n)*n/2, cur = sum;
    while(r < p.size())
    {
        cur -= p[l++];
        cur += p[++r];
        if(cur == sum) ++ans;
    }
    cout << n << ":" << ans << endl;
    }
    return 0;
}
