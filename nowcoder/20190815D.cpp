#include <bits/stdc++.h>

using namespace std;

const int kN = 40;

int n;
string ans;
long long s;
long long a[kN];
unordered_map<long long, string> mmp;

void dfs1(int cur, long long sum, string choose)
{
    if (cur > n/2) {
        mmp.insert({ sum, choose });
        return;
    }
    dfs1(cur+1, sum, choose+"0");
    dfs1(cur+1, sum+a[cur], choose+"1");
}

void dfs2(int cur, long long sum, string choose)
{
    if (ans.length()) return;
    if (cur > n) {
        if (mmp.find(s-sum) != mmp.end()) {
            ans = mmp[s-sum]+choose;
        }
        return;
    }
    dfs2(cur+1, sum, choose+"0");
    if (ans.length()) return;
    dfs2(cur+1, sum+a[cur], choose+"1");
    if (ans.length()) return;
}

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dfs1(1, 0, "");
    dfs2(n/2+1, 0, "");
    cout << ans << endl;
    return 0;
}
