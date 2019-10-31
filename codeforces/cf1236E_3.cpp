#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;

int n, m;
int a[N];
long long res;
vector<int> buf[N<<1], bufm[N<<1];
vector<int> sl[N<<1], *sr = buf+N, ml[N<<1], *mr = bufm+N;

inline int Get(vector<int> &v, int i)
{
    int p = upper_bound(v.begin(), v.end(), i)-v.begin();
    return p == (int)v.size() ? -1 : p;
}

int GetL(int i, int j)
{
    int p = Get(sl[i+j], i);
    if (p == -1) return max(1, j-(m+1-i));
    if (ml[i+j][p]) return ml[i+j][p];
    return ml[i+j][p] = GetL(sl[i+j][p], a[sl[i+j][p]]+1);
}

int GetR(int i, int j)
{
    int p = Get(sr[i-j], i);
    if (p == -1) return min(n, j+(m+1-i));
    if (mr[i-j][p]) return mr[i-j][p];
    return mr[i-j][p] = GetR(sr[i-j][p], a[sr[i-j][p]]-1);
}

int main()
{
    cin >> n >> m;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
        sl[i+a[i]].push_back(i);
        ml[i+a[i]].push_back(0);
        sr[i-a[i]].push_back(i);
        mr[i-a[i]].push_back(0);
    }
    // i- first place
    for (int i = 1; i <= n; ++i) {
        res += GetR(0, i)-GetL(0, i)+1;
    }
    cout << res << endl;
    return 0;
}
