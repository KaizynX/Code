/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 20:39:51
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-16 09:13:01
 * @FilePath: \Code\pintia\2020031507_copy.cpp
 */
#include<queue>
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb lower_bound
typedef pair<int, int> pii;
struct node{
    pii p; bool vis;
    node(pii _p=mp(0, 0), bool _v=false):p(_p), vis(_v){}
    friend bool operator < (node a, node b) {return a.p < b.p;}
    friend bool operator == (node a, node b) {return a.p == b.p;}
    
};
vector<node>b, w;
vector<int>vx, vy;
int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    vx.clear(), vx.pb(0), vx.pb(1), vx.pb(n), vx.pb(n + 1);
    vy.clear(), vy.pb(0), vy.pb(1), vy.pb(m), vy.pb(m + 1);
    for(int i=1;i<=k;i++) {
        int x, y; scanf("%d%d", &x, &y);
        b.pb(node(mp(x, y)));
        vx.pb(x - 1), vx.pb(x), vx.pb(x + 1);
        vy.pb(y - 1), vy.pb(y), vy.pb(y + 1);
    }
    sort(vx.begin(), vx.end()), vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end()), vy.erase(unique(vy.begin(), vy.end()), vy.end());
    for(int i=0;i<k;i++) {
        b[i].p.fi = lb(vx.begin(), vx.end(), b[i].p.fi) - vx.begin();
        b[i].p.se = lb(vy.begin(), vy.end(), b[i].p.se) - vy.begin();
    }
    for(int i=1;i<vx.size()-1;i++)
        b.pb(node(mp(i, 0))), b.pb(node(mp(i, vy.size()-1)));
    for(int i=1;i<vy.size()-1;i++)
        b.pb(node(mp(0, i))), b.pb(node(mp(vx.size()-1, i)));
    sort(b.begin(), b.end()), b.erase(unique(b.begin(), b.end()), b.end());
    int ans = 0;
    for(int i=0;i<b.size();i++) {
        if( b[i].vis ) continue;
        b[i].vis = true; w.clear();
        queue<pii>que; que.push(b[i].p);
        while( !que.empty() ) {
            pii f = que.front(); que.pop();
            for(int dx=-1;dx<=1;dx++)
                for(int dy=-1;dy<=1;dy++) {
                    pii p = mp(f.fi + dx, f.se + dy);
                    int x = lb(b.begin(), b.end(), node(p)) - b.begin();
                    if( x != b.size() && b[x].p == p ) {
                        if( !b[x].vis )
                            b[x].vis = true, que.push(p);
                    }
                    else w.pb(p);
                }
        }
        sort(w.begin(), w.end()), w.erase(unique(w.begin(), w.end()), w.end());
        for(int j=0;j<w.size();j++) {
            if( w[j].vis ) continue;
            ans++; w[j].vis = true; que.push(w[j].p);
            while( !que.empty() ) {
                pii f = que.front(); que.pop();
                for(int dx=-1;dx<=1;dx++)
                    for(int dy=-1;dy<=1;dy++) {
                        if( dx && dy ) continue;
                        pii p = mp(f.fi + dx, f.se + dy);
                        int x = lb(w.begin(), w.end(), node(p)) - w.begin();
                        if( x != w.size() && w[x].p == p && !w[x].vis )
                            w[x].vis = true, que.push(p);
                    }
            }
        }
        ans--;
    }
    printf("%d\n", ans);
}