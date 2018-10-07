#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int Maxm = 2e3+7;

int t;

struct Tree
{
    int v, dis, num, f[Maxm];
    Tree *l, *r;

    Tree() : v(0), dis(0), num(0), l(nullptr), r(nullptr) { memset(f, 0x3f, sizeof(f)); }
};

int build_tree(Tree *cur)
{
    cin >> cur->dis >> cur->v;
    if(!cur->v)
    {
        cur->l = new(Tree);
        cur->num += build_tree(cur->l);
        cur->r = new(Tree);
        cur->num += build_tree(cur->r);
    }
    return cur->num += cur->v;
}

int dp(Tree *cur, int p)
{
    if(!p) return 0;
    if(cur->f[p] != 0x3f3f3f3f) return cur->f[p];
    if(cur->num == cur->v) return cur->dis;
    for(int i = 0; i <= p; ++i)
    {
        if(i > cur->l->num) break;
        if(p-i > cur->r->num) continue;
        cur->f[p] = min(cur->f[p], dp(cur->l, i)+dp(cur->r, p-i));
    }
    return cur->f[p] += cur->dis;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Tree *root = new(Tree);
    cin >> t;
    --t; // as soon as police arrive, theif should die...
    root->num = build_tree(root);
    int l = 0, r = min(t/5, root->num);
    while(l < r)
    {
        int mid = (l+r+1) >> 1;
        if(dp(root, mid)*2+5*mid <= t) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
