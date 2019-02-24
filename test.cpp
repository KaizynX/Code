#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int v;
    // 在里面定义
    bool operator < (const Node &a) const
    {
        return v < a.v;
    }
};

// 在外面定义
bool operator > (const Node &a, const Node &b)
{
    return a.v < b.v;
}

// emmm定义
bool cmp (const Node &a, const Node &b)
{
    return a.v < b.v;
}

int main()
{
    return 0;
}
