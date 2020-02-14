#include <bits/stdc++.h>

using namespace std;

const int N = 40;

struct TreeNode
{
    int v;
    TreeNode *l = nullptr, *r = nullptr;
    TreeNode(){}
} *root;

int n;
int mid[N], pre[N];

void build(TreeNode *cur, int ml, int mr, int pl, int pr)
{
    printf("%d %d %d %d\n", ml, mr, pl, pr);
    cur->v = pre[pl];
    int p;
    for (int i = ml; i <= mr; ++i)
        if (mid[i] == pre[pl]) p = i;
    if (p-1 >= ml) build(cur->l = new TreeNode(), ml, p-1, pl+1, pl+p-ml);
    if (p+1 <= mr) build(cur->r = new TreeNode(), p+1, mr, pr-mr+p+1, pr);
}

void print(TreeNode *cur)
{
    queue<TreeNode*> q;
    q.push(cur);
    printf("%d", cur->v);
    while (q.size()) {
        TreeNode *u = q.front();
        q.pop();
        if (u->r) {
            printf(" %d", u->r->v);
            q.push(u->r);
        }
        if (u->l) {
            printf(" %d", u->l->v);
            q.push(u->l);
        }
    }
    putchar('\n');
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> mid[i];
    for (int i = 1; i <= n; ++i) cin >> pre[i];
    build(root = new TreeNode(), 1, n, 1, n);
    print(root);
    return 0;
}
