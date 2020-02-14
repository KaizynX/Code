#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n;

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
        if (x > cur->v) {
            if (cur->l) insert(x, cur->l);
            else cur->l = new TreeNode(x);
        } else {
            if (cur->r) insert(x, cur->r);
            else cur->r = new TreeNode(x);
        }
    }
    bool check(int x, TreeNode *cur) {
        if (x > n) return false;
        if (cur->l && !check(x<<1, cur->l)) return false;
        if (cur->r && !check(x<<1|1, cur->r)) return false;
        return true;
    }
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
} T;

int main()
{
    cin >> n;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        T.insert(a, T.root);
    }
    T.print();
    cout << (T.check(1, T.root) ? "YES" : "NO") << endl;
    return 0;
}
