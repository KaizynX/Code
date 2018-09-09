#include <queue>
#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 507;

int h, w;
int a[Maxn][Maxn];

struct Node
{
    int x, y, d;
    vector<int> e;
    Node(int x, int y) { x = x; y = y; d = 0; }
};

vector<Node> p;
queue<int> q;

int main()
{
    scanf("%d%d", &h, &w);
    for(int i = 1; i <= h; ++i)
        for(int j = 1; j <= w; ++j)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j]&1) p.push_back(Node(i, j));
        }
    for(int i = 0; i < p.size(); ++i)
        for(int j = 0; j < p.size(); ++j)
        {
            if(i == j) continue;
            if(p[i].x >= p[j].x && p[i].y >= p[j].y)
            {
                p[i].e.push_back(j);
                p[j].d++;
            }
        }
    for(int i = 1; i < p.size(); ++i)
        if(!p[i].d) q.push(i);
    int cur, cnt;
    while(q.size())
    {
        cur = q.front();
        q.pop();
        cnt = 0;
        for(vector<int>::iterator it = p[cur].e.begin(); i != p[cur].e.end(); ++i)
        {
            if(--p[*it].d == 0)
            {
                if(cnt++ == 0)
                {
                    ;// print the road
                }
                else q.push(*it);
            }
        }
    }
    return 0;
}

