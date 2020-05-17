/*
 * @Author: Kaizyn
 * @Date: 2020-05-05 15:45:53
 * @LastEditTime: 2020-05-05 16:09:13
 */
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <functional>

// #define DEBUG

using namespace std;

const int N = 1e5+7;

struct ST
{
    int lg2[N];
    int rmq[N][20]; // rmq[i][j] ==> [i-2^j+1, i]
    ST() {
        for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    }
    void build(int a[], const int &n) {
        for (int i = 1; i <= n; ++i) {
            rmq[i][0] = a[i];
            for (int j = 1; j <= lg2[i]; ++j)
                rmq[i][j] =  min(rmq[i][j-1], rmq[i-(1<<(j-1))][j-1]);
        }
    }
    int query(const int &l, const int &r) {
        int k = lg2[r-l+1];
        return min(rmq[r][k], rmq[l+(1<<k)-1][k]);
    }
};

int n;
int lg2[N];
char s[N];
int sa[N], rk[N<<1], height[N];
ST st, st_rk;

int w;
inline bool cmp(const int &x, const int &y) {
    return rk[x] == rk[y] ? rk[x+w] < rk[y+w] : rk[x] < rk[y];
}

inline void SA(char *s, const int &n) {
    static int oldrk[N<<1];
    memset(rk, 0, sizeof rk);
    for (int i = 1; i <= n; ++i) rk[i] = s[i];
    memset(rk+n+1, 0, sizeof(int)*n);
    for (w = 1; w <= n; w <<= 1) {
        for (int i = 1; i <= n; ++i) sa[i] = i;
        sort(sa+1, sa+n+1, cmp);
        memcpy(oldrk+1, rk+1, sizeof(int)*n*2);
        for (int p = 0, i = 1; i <= n; ++i) {
            if (oldrk[sa[i]] == oldrk[sa[i-1]] &&
                oldrk[sa[i]+w] == oldrk[sa[i-1]+w]) {
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++p;
            }
        }
    }
    for (int i = 1, k = 0; i <= n; ++i) {
        if (k) --k;
        while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
        height[rk[i]] = k;
    }
}


inline int lcp(const int &l, const int &r) {
    return l < r ? st.query(l+1, r) : st.query(r+1, l);
}

int ress, rest, resl;
vector<int> ans;

inline void update(const int &s, const int &t, const int &l) {
    if (rest < t || (rest == t && s < ress)) {
        ress = s;
        rest = t;
        resl = l;
    }
}

inline void print() {
    for (int i = ress; i < ress+resl; ++i) putchar(s[i]);
    putchar('\n');
}

int main() {
    int T = 0;
    while (scanf("%s", s+1) && strcmp(s+1, "#")) {
        n = strlen(s+1);
        SA(s, n);
        st.build(height, n);
        st_rk.build(rk, n);
        ress = rest = resl = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1, k, t, l; j+i <= n; j += i) {
                k = lcp(rk[j], rk[j+i]);
                t = k/i+1;
                l = j-i+k%i;
                if (l > 0 && lcp(rk[l], rk[l+i]) > k) ++t;
                if (t > rest) {
                    rest = t;
                    ans.clear();
                    ans.push_back(i);
                } else if (t == rest) {
                    ans.push_back(i);
                }
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        #ifdef DEBUG
        for (int i = 1; i <= n; ++i) printf("%d%c", height[i], " \n"[i==n]);
        for (int i = 1; i <= n; ++i) printf("%d%c", sa[i], " \n"[i==n]);
        for (int i = 1; i <= n; ++i) printf("%d%c", rk[i], " \n"[i==n]);
        #endif
        for (int i = 1, flag = 0; i <= n; ++i) {
            if (flag) break;
            for (int j = 0; j < (int)ans.size(); ++j) {
                int tem = ans[j];
                if (lcp(i, rk[sa[i]+tem]) >= (rest-1)*tem) {
                    ress = sa[i];
                    resl = tem*rest;
                    flag = 1;
                    break;
                }
            }
        }
        printf("Case %d: ", ++T);
        print();
    }
}