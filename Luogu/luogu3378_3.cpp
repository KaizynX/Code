#include <bits/stdc++.h>

using namespace std;

struct Heap
{
    static const int Maxn = 1e6+7;
    int sz, a[Maxn];
    Heap() { sz = 0; memset(a, 0, sizeof a); }
    inline bool cmp(int x, int y) { return x < y; } // Ð¡¸ù¶Ñ
    inline int size() { return sz; }
    inline bool empty() { return sz == 0; }
    inline int top() { return a[1]; }
    inline void push(int x) { a[++sz] = x; swift_up(sz); }
    inline void pop() { swap(a[1], a[sz--]); swift_down(1); }
    inline void swift_up(int p)
    {
        while(p > 1 && cmp(a[p], a[p>>1])) // a[p] < a[p<<1]
            swap(a[p], a[p>>1]), p >>= 1;
    }
    inline void swift_down(int p)
    {
        int l, r, s;
        while(true)
        {
            l = p<<1; r = p<<1|1;
            if(l > sz) break;
            if(r > sz || cmp(a[l], a[r])) s = l; // a[l] < a[r]
            else s = r;
            if(cmp(a[s], a[p])) // a[s] < a[p]
                swap(a[p], a[s]), p = s;
            else break;
        }
    }
}h;

int main()
{
    int n, op, x;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &op);
        if(op == 1)
        {
            scanf("%d", &x);
            h.push(x);
        }
        else if(op == 2) printf("%d\n", h.top());
        else h.pop();
    }
    return 0;
}
