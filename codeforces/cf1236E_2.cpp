#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m;
long long res;
int buf[N<<1], bufm[N<<1];
int a[N], sl[N<<1], *sr = buf+N, ml[N<<1], *mr = bufm+N;

int GetL(int i, int j)
{
    if (sl[i+j] <= i) return max(1, j-(m+1-i));
    if (ml[i+j]) return ml[i+j];
    return ml[i+j] = GetL(sl[i+j], a[sl[i+j]]+1);
}

int GetR(int i, int j)
{
    if (sr[i-j] <= i) return min(n, j+(m+1-i));
    if (mr[i-j]) return mr[i-j];
    return mr[i-j] = GetR(sr[i-j], a[sr[i-j]]-1);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        if (!sl[i+a[i]]) sl[i+a[i]] = i;
        if (!sr[i-a[i]]) sr[i-a[i]] = i;
    }
    // i- first place
    for (int i = 1; i <= n; ++i) {
        res += GetR(0, i)-GetL(0, i)+1;
    }
    cout << res << endl;
    return 0;
}
