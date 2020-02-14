#include <bits/stdc++.h>

using namespace std;

const int N = 40;

struct TreeNode
{
    int v;
    TreeNode *l, *r;
    TreeNode(int _v) : v(_v) {}
} *root;

int n;
int bac[N], mid[N];

TreeNode* build_tree(int bl, int br, int ml, int mr)
{
    if (bl > br) return nullptr;
    TreeNode *cur = new TreeNode(bac[br]);
    int p = 0;
    for (int i = ml; i <= mr; ++i)
        if (mid[i] == bac[br]) {
            p = i;
            break;
        }
    cur->l = build_tree(bl, bl+p-1-ml, ml, p-1);
    cur->r = build_tree(bl+p-ml, br-1, p+1, mr);
    return cur;
}

void print()
{
    queue<TreeNode*> q;
    q.push(root);
    cout << root->v;
    while (q.size()) {
        TreeNode *cur = q.front();
        q.pop();
        if (cur->l) {
            cout << " " << cur->l->v;
            q.push(cur->l);
        }
        if (cur->r) {
            cout << " " << cur->r->v;
            q.push(cur->r);
        }
    }
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> bac[i];
    for (int i = 1; i <= n; ++i) cin >> mid[i];
    root = build_tree(1, n, 1, n);
    print();
    return 0;
}
