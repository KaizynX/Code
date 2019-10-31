#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 1e9;

struct Spaly
{
    #define root e[0].child[1]
    typedef int T;
    struct Node
    {
        T v = 0;
        int father = 0, sum = 0, cnt = 0;
        int child[2] = {0, 0};
    } e[N];
    int n = 0;
    
    void update(int x) {
        e[x].sum = e[e[x].child[0]].sum + e[e[x].child[1]].sum + e[x].cnt;
    }

    int identify(int x) {
        return x == e[e[x].father].child[1];
    }

    void connect(int x, int y, int son) {
        e[x].father = y;
        e[y].child[son] = x;
    }

    void rotate(int x) {
        int y = e[x].father,
            r = e[y].father,
            sonx = identify(x),
            sony = identify(y),
            b = e[x].child[sonx^1];
        connect(b, y, sonx);
        connect(y, x, sonx^1);
        connect(x, r, sony);
        update(y);
        update(x);
    }

    void splay(int x, int y) {
        y = e[y].father;
        int up;
        while ((up = e[x].father) != y) {
            if (e[up].father != y) 
                identify(x) == identify(up) ? rotate(up) : rotate(y);
            rotate(x);
            /*
            if (e[up].father == y) rotate(x);
            else if (identify(x) == identify(up)) {
                rotate(up);
                rotate(x);
            } else {
                rotate(x);
                rotate(x);
            }
            */
        }
    }

    int add_point(int f, T v) {
        ++n;
        e[n].v = v;
        e[n].father = f;
        e[n].sum = e[n].cnt = 1;
        return n;
    }

    void del_point(int x) {
        e[x].v = e[x].father = e[x].sum = e[x].cnt
               = e[x].child[0] = e[x].child[1] = 0;
    }

    int find(T v) {
        int now = root;
        while (true) {
            if (e[now].v == v) {
                splay(now, root);
                return now;
            }
            now = e[now].child[(v < e[now].v ? 0 : 1)];
            if (!now) return 0;
            /*
            int nex = v < e[now].v ? 0 : 1;
            if (!e[now].child[nex]) return 0;
            now = e[now].child[nex];
            */
        }
    }

    int build(T v) {
#ifndef DEBUG
        if (!n) return root = add_point(root, v);
#else
        if (!n) {
            root = add_point(root, v);
            return 0;
        }
#endif
        int now = root;
        while (true) {
            ++e[now].sum;
            if (v == e[now].v) {
                ++e[now].cnt;
                return now;
            }
            int nex = v < e[now].v ? 0 : 1;
            if (!e[now].child[nex]) {
                return e[now].child[nex] = add_point(now, v);
            }
            now = e[now].child[nex];
        }
    }

    void insert(T v) {
        splay(build(v), root);
    }

    void erase(T v) {
        int del = find(v);
        if (!del) return;
        if (e[del].cnt > 1) {
            --e[del].cnt;
            --e[del].sum;
            return;
        }
        if (!e[del].child[0]) {
            root = e[del].child[1];
            e[root].father = 0;
        } else {
            int lef = e[del].child[0];
            while (e[lef].child[1]) lef = e[lef].child[1];
            splay(lef, e[del].child[0]);
            connect(e[del].child[1], lef, 1);
            connect(lef, 0, 1);
            update(lef);
        }
        del_point(del);
    }

    int rank(T v) {
        int res = 0, now = root;
        while (true) {
            if (!now) return 0;
            if (e[now].v == v) {
                res += e[e[now].child[0]].sum+1;
                break;
            }
            if (v < e[now].v) now = e[now].child[0];
            else {
                res += e[e[now].child[0]].sum+e[now].cnt;
                now = e[now].child[1];
            }
        }
        splay(now, root);
        return res;
    }

    T atrank(int x) {
        if (x > e[root].sum) return -INF;
        int now = root;
        while (now) {
            if (x <= e[e[now].child[0]].sum) now = e[now].child[0];
            else if ((x -= e[e[now].child[0]].sum) <= e[now].cnt) break;
            else x -= e[now].cnt, now = e[now].child[1];
        }
        splay(now, root);
        return e[now].v;
    }

    T lower(T v) {
        int now = root;
        T res = -INF;
        while (now) {
            if (e[now].v < v) res = max(res, e[now].v);
            now = e[now].child[v > e[now].v ? 1 : 0];
            /*
            if (v > e[now].v) now = e[now].child[1];
            else now = e[now].child[0];
            */
        }
        return res;
    }

    T upper(T v) {
        int now = root;
        T res = INF;
        while (now) {
            if (e[now].v > v) res = min(res, e[now].v);
            now = e[now].child[v < e[now].v ? 0 : 1];
            /*
            if (v < e[now].v) now = e[now].child[0];
            else now = e[now].child[1];
            */
        }
        return res;
    }
    #undef root
} tree;

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void write(T x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

int n;

int main()
{
#ifndef DEBUG
    read(n);
#else
    cin >> n;
#endif
    for (int i = 1, opt, x; i <= n; ++i) {
#ifndef DEBUG
        read(opt);
        read(x);
#else
        cin >> opt >> x;
#endif
        switch (opt) {
            case 1 :
                tree.insert(x);
                break;
            case 2 :
                tree.erase(x);
                break;
            case 3 :
                write(tree.rank(x));
                putchar('\n');
                break;
            case 4 :
                write(tree.atrank(x));
                putchar('\n');
                break;
            case 5 :
                write(tree.lower(x));
                putchar('\n');
                break;
            case 6 :
                write(tree.upper(x));
                putchar('\n');
                break;
            // defult :
        }
    }
    return 0;
}
