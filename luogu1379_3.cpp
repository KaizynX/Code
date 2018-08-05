#include <iostream>
#include <cstdlib>
#include <map>
#define DEBUG

using namespace std;
/* 1 2 3 *
 * 4 5 6 *
 * 7 8 9 */
const int res = 123804765;
const int Maxq = 1e6;

struct Node
{
    int v, pos, step, flag;
    Node(int v = 0, int pos = 0, int step = 0, int flag = 0) : v(v), pos(pos), step(step), flag(flag) {}
} _sta, _end(123804765, 5, 0, 2);

int head, tail;
Node q[Maxq];
map<int, pair<int,int> > mmp;

inline Node change(Node form, int goal)
{
    int tmp[10];
    for(int i = 9; i; --i)
    {
        tmp[i] = form.v % 10;
        form.v /= 10;
    }
    swap(tmp[form.pos], tmp[goal]);
    form.pos = goal;
    form.step++;
    for(int i = 1; i <= 9; ++i)
        form.v = form.v*10 + tmp[i];
    return form;
}

inline void add(const Node &cur, int d)
{
    q[++tail % Maxq] = change(cur, cur.pos+d);
    int v = q[tail%Maxq].v;
    Node tmp = q[tail%Maxq];
    if(mmp.count(v))
    {
        if(mmp[v].first == tmp.flag) --tail;
        else
        {
            cout << tmp.step + mmp[v].second << endl;
            exit(0);
        }
    }
    else 
        mmp.insert(make_pair(v, make_pair(tmp.flag, tmp.step)));
}

inline int get_pos(int num)
{
    for(int tmp = num, cnt = 9, now; cnt; --cnt)
    {
        now = tmp % 10;
        if(!now)
            return cnt;
        tmp /= 10;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> _sta.v;
    if(_sta.v == _end.v)
    {
        cout << 0 << endl;
        return 0;
    }
    _sta.pos = get_pos(_sta.v);
    _sta.flag = 1;
    // bfs
    Node cur;
    q[++tail] = _sta;
    q[++tail] = _end;
    mmp.insert(make_pair(_sta.v, make_pair(1, 0)));
    mmp.insert(make_pair(_end.v, make_pair(2, 0)));
    while(head < tail)
    {
        cur = q[++head % Maxq];
#ifdef DEBUG
        cout << cur.v << " " << cur.flag << endl;
#endif
        if(cur.pos > 3) // up
            add(cur, -3);
        if(cur.pos < 7) // down
            add(cur, +3);
        if(cur.pos%3 != 1) // left
            add(cur, -1);
        if(cur.pos%3 != 0) // right
            add(cur, +1);
    }
    return 0;
}

