#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int INF = 2e9;

int n, m, tot;
string str;
map<int, int> mp;

struct Node
{
    int v, d, fa = INF, l = INF, r = INF, bro = INF;
} tr[N];

struct Tree
{
    struct TreeNode
    {
        int v;
        TreeNode *l, *r;
        TreeNode(int _v) : v(_v) { l = r = nullptr; }
    } *root;
    Tree(){ root = nullptr; }
    void insert(int x, TreeNode *cur)
    {
        if (!root) { root = new TreeNode(x); return; }
        if (x < cur->v) {
            if (cur->l) insert(x, cur->l);
            else cur->l = new TreeNode(x);
        } else {
            if (cur->r) insert(x, cur->r);
            else cur->r = new TreeNode(x);
        }
    }
    void init(TreeNode *cur, int d, int fa) {
        mp[cur->v] = ++tot;
        tr[tot].v = cur->v;
        tr[tot].fa = fa;
        tr[tot].d = d;
        if (cur->l) tr[tot].l = cur->l->v, init(cur->l, d+1, cur->v);
        if (cur->r) tr[tot].r = cur->r->v, init(cur->r, d+1, cur->v);
        if (cur->l && cur->r) {
            int l = mp[cur->l->v], r = mp[cur->r->v];
            tr[l].bro = cur->r->v;
            tr[r].bro = cur->l->v;
        }
    }
#ifdef DEBUG
    void print()
    {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        cout << root->v;
        while (q.size()) {
            TreeNode *u = q.front();
            q.pop();
            if (u->l) {
                cout << " " << u->l->v;
                q.push(u->l);
            }
            if (u->r) {
                cout << " " << u->r->v;
                q.push(u->r);
            }
        }
        cout << endl;
    }
#endif
} T;

int main()
{
    cin >> n;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        T.insert(a, T.root);
    }
    T.init(T.root, 0, INF);
#ifdef DEBUG
    T.print();
#endif
    cin >> m;
    cin.get();
    while (m--) {
        getline(cin, str);
        stringstream ss;
        ss << str;
        int a, b, flag;
        ss >> a >> str;
        if (!mp.count(a)) {
            cout << "No" << endl;
            continue;
        }
        if (str == "is") {
            ss >> str >> str;
            if (str == "root") {
                flag = T.root ? T.root->v == a : false;
            } else if (str == "parent") {
                ss >> str >> b;
                flag = tr[mp[b]].fa == a;
            } else if (str == "left") {
                ss >> str >> str >> b;
                flag = mp.count(b) ? tr[mp[b]].l == a : false;
            } else if (str == "right") {
                ss >> str >> str >> b;
                flag = mp.count(b) ? tr[mp[b]].r == a : false;
            }
        } else if (str == "and") {
            ss >> b >> str >> str;
            if (!mp.count(b)) {
                flag = false;
            } else if (str == "siblings") {
                flag = tr[mp[a]].bro == b;
            } else if (str == "on") {
                flag = tr[mp[a]].d == tr[mp[b]].d;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
    return 0;
}
