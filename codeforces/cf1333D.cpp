/*
 * @Author: Kaizyn
 * @Date: 2020-04-08 22:32:17
 * @LastEditTime: 2020-04-09 10:05:10
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 3e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, k;
// string s;
char s[N];
vector<vector<int>> res;
vector<int> cur, pos[2];

inline void solve()
{
    // cin >> n >> k >> s;
    scanf("%d %d %s", &n, &k, s);
    int sum = 0, u = 0;
    for (int i = 1; i < n; ++i) {
        if (s[i-1] == 'R' && s[i] == 'L') {
            cur.emplace_back(i);
            s[i-1] = 'L';
            s[i] = 'R';
            if (i-2 >= 0 && s[i-2] == 'R') pos[u].emplace_back(i-1);
            if (i+1 < n && s[i+1] == 'L') pos[u].emplace_back(i+1);
            ++i;
        }
    }
    while (cur.size()) {
        sum += cur.size();
        res.emplace_back(cur);
        cur.clear();
        pos[u ^= 1].clear();
        for (int &i : pos[u^1]) {
            cur.emplace_back(i);
            s[i-1] = 'L';
            s[i] = 'R';
            if (i-2 >= 0 && s[i-2] == 'R') pos[u].emplace_back(i-1);
            if (i+1 < n && s[i+1] == 'L') pos[u].emplace_back(i+1);
        }
    }
    /*
    do {
        cur.clear();
        for (int i = 1; i < n; ++i) {
            if (s[i-1] == 'R' && s[i] == 'L') {
                cur.emplace_back(i);
                s[i-1] = 'L';
                s[i] = 'R';
                ++i;
            }
        }
        sum += cur.size();
        if (cur.size()) res.emplace_back(cur);
    } while (cur.size());
    */
    if ((int)res.size() > k || sum < k) return void(cout << -1 << endl);
    int now = res.size();
    for (auto &vec : res) {
        while (now < k && vec.size()) {
            // cout << 1 << " " << vec.back() << endl;
            printf("1 %d\n", vec.back());
            vec.pop_back();
            --k;
        }
        --now;
        k -= vec.size();
        if (!vec.size()) continue;
        printf("%d ", (int)vec.size());
        for (int &i : vec) printf("%d ", i);
        putchar('\n');
        // cout << vec.size() << " ";
        // for (int &i : vec) cout << i << " ";
        // cout << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}