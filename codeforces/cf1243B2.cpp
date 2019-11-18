#include <bits/stdc++.h>

using namespace std;

const int N = 100;

int k, n;
int cnts[30], cntt[30], num[30];
vector<int> ps[30], pt[30];
vector<pair<int, int>> res;
char s[N], t[N];

int main()
{
    scanf("%d", &k);
    while (k--) {
        int flag = 1;
        scanf("%d%s%s", &n, s, t);
        // cin >> n >> s >> t;
        if (!strcmp(s, t)) { printf("Yes\n0\n"); continue; }
        res.clear();
        for (int i = 0; i < 26; ++i) {
            ps[i].clear();
            pt[i].clear();
            cnts[i] = cntt[i] = num[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            ++cnts[s[i]-'a'];
            ++cntt[t[i]-'a'];
            ps[s[i]-'a'].push_back(i);
            pt[t[i]-'a'].push_back(i);
        }
        for (int i = 0; i < 26; ++i) {
            num[i] = cnts[i]+cntt[i];
            if (num[i]&1) { flag = 0; break; }
            num[i] /= 2;
        }
        if (!flag) { cout << "No" << endl; continue; }
        for (int i = 0; i < 26; ++i) {
            while (cnts[i] > num[i]) {
                for (int j = 0; j < 26; ++j) {
                    if (cntt[j] > num[j]) {
                        --cntt[j];
                        ++cnts[j];
                        ++cntt[i];
                        --cnts[i];
                        res.push_back({ps[i].back(), pt[j].back()});
                        swap(s[ps[i].back()], t[pt[j].back()]);
                        ps[j].push_back(ps[i].back());
                        ps[i].pop_back();
                        pt[i].push_back(pt[j].back());
                        pt[j].pop_back();
                        /*
                        pt[i].push_back(ps[i].back());
                        ps[i].pop_back();
                        ps[j].push_back(pt[j].back());
                        pt[j].pop_back();
                        */
                        break;
                    }
                }
            }
        }
        int nex, cur, pos, sta = 0;
        while (true) {
            pos = sta;
            while (pos < n && s[pos] == t[pos]) ++pos;
            if (pos >= n) break;
            res.push_back({pos, pos});
            swap(s[pos], t[pos]);
            sta = pos;
            while (true) {
                cur = s[pos]-'a';
                if (ps[cur].empty()) break;
                nex = ps[cur].back();
                ps[cur].pop_back();
                if (nex == sta) {
                    if (ps[cur].empty()) break;
                    nex = ps[cur].back();
                    ps[cur].pop_back();
                }
                res.push_back({pos, nex});
                swap(s[pos], t[nex]);
            }
        }
        printf("Yes\n%d\n", res.size());
        for (auto tmp : res)
            printf("%d %d\n", tmp.first+1, tmp.second+1);
    }
    return 0;
}
