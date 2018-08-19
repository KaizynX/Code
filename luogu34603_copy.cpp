#include <bits/stdc++.h>

using namespace std;

#define reg register

typedef long long ll;

inline ll read() {
    ll s = 0, t = 1; char ch = getchar();
    while(ch > '9' || ch < '0') { if(ch == '-') t = -1; ch = getchar(); }
    while(ch <= '9' && ch >= '0') { s = s * 10 + ch - '0'; ch = getchar(); }
    return s * t;
}

struct Line {
    ll k;
    ll b;
    ll js;
    int id;
};

inline ll jd(Line a, Line b) { return (b.b - a.b) / (a.k - b.k) + 1; }
inline ll calc(Line a, ll x) { return a.k * x + a.b; }

struct Ask {
    int id;
    ll x;
};

struct Swap {
    int x;
    int y;
    ll p;
};

bool operator < (Ask a, Ask b) {
    return a.x < b.x;
}

bool cmp(Swap a, Swap b) {
    if(a.p != b.p) return a.p < b.p;
    return a.x < b.x;
}

const int N = 2020;
const int M = 500500;

int n;
int m;
int k;
int jsq;
Ask Q[M];
ll res[M];
int rk[N];
int num[N];
Line L[N];
Swap S[N * N];

bool cmp1(Line a, Line b) {
    return a.js < b.js;
}

int main() {
    n = read(); m = read(); k = read();
    for(reg int i = 1; i <= n; i++) {
        L[i].k = read();
        L[i].b = read();
    }
    for(reg int i = 1; i <= m; i++) {
        Q[i].x = read();
        Q[i].id = i;
    }
    sort(Q + 1, Q + 1 + m);
    for(reg int i = 1; i <= n; i++) L[i].js = calc(L[i], Q[1].x);
    sort(L + 1, L + 1 + n, cmp1);
    for(reg int i = 1; i <= n; i++) {
        L[i].id = num[i] = rk[i] = i;
        for(reg int j = i + 1; j <= n; j++)
            if(L[i].k != L[j].k && calc(L[i], Q[m].x) >= calc(L[j], Q[m].x)) {
                ll d = jd(L[i], L[j]);
                if(d >= Q[1].x) {
                    jsq++;
                    S[jsq].x = i;
                    S[jsq].y = j;
                    S[jsq].p = d;
                }
            }
    }
    sort(S + 1, S + 1 + jsq, cmp);
    for(reg int i = 1, id = 1; i <= m; i++) {
        while(id <= jsq && S[id].p <= Q[i].x) {
            rk[S[id].x]++;
            rk[S[id].y]--;
            num[rk[S[id].x]] = S[id].x;
            num[rk[S[id].y]] = S[id].y;
            id++;
        }
        res[Q[i].id] = calc(L[num[k]], Q[i].x);
    }
    for(reg int i = 1; i <= m; i++) printf("%lld\n", res[i]);
    return 0;
}
