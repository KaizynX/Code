#include <map> 
#include <set> 
#include <cmath> 
#include <stack> 
#include <queue> 
#include <cstdio> 
#include <vector> 
#include <cstring> 
#include <iostream>
#include <algorithm> 

using namespace std;

const int Maxn = 150000+7;

struct Node
{
    int v;
    Node *l, *r;
    Node(){ l = nullptr; r = nullptr; }
} a[Maxn];

int n;
int fh[Maxn], ft[Maxn];

int getf(int *f, int s)
{
    return f[s] == s ? s : f[s] = getf(f, f[s]);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        a[i].v = fh[i] = ft[i] = i;
    }
    for(int i = 1, x, y; i < n; ++i)
    {
        cin >> x >> y;
        int ftx = getf(ft, x), fhy = getf(fh, y);
        a[ftx].r = &a[fhy];
        a[fhy].l = &a[ftx];
        ft[ftx] = fhy;
        fh[fhy] = ftx;
    }
    for(int i = 1;  i <= n; ++i)
    {
        if(getf(fh, i) == i)
        {
            Node *cur = &a[i];
            while(cur)
            {
                cout << cur->v << " ";
                cur = cur->r;
            }
        }
    }
    return 0;
}