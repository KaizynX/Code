#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        map<pair<int, int>, int> mmp;
        vector<int> member[m+7], otd[m+7], idu(m+7, 0);
        for (int i = 0; i < beforeItems.size(); ++i) {
            if (group[i] != -1) member[group[i]].push_back(i);
            for (int j : beforeItems[i]) {
                int gi = group[i], gj = group[j]; 
                if (gi == -1 || gj == -1) continue;
                if (mmp.count({gj, gi})) continue;
                mmp.insert({{gj, gi}, 1});
                // ind[gi].push_back(gj);
                otd[gj].push_back(gi);
                ++idu[gi];
                // ++odu[gj];
            }
        }
        
        vector<int> m_rk, du(m+7, 0);
        queue<int> q;
        for (int i = 0; i < m; ++i) {
            if (!idu[i]) q.push(i);
        }
        while (q.size()) {
            int cur = q.front();
            q.pop();
            m_rk.push_back(cur);
            for (int i : otd[cur]) {
                if (--idu[i] == 0) q.push(i);
            }
        }
        if (m_rk.size() < m) return vector<int>{};
        
        vector<int> res, indu(n+7, 0), outdu[n+7], to_be_add;
        int add_id = 0;
        for (int i = 0; i < n; ++i) {
            for (int j : beforeItems[i]) {
                ++indu[i];
                outdu[j].push_back(i);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (indu[i] == 0 && group[i] == -1) {
                to_be_add.push_back(i);
            }
        }
        for (int gp : m_rk) {
            for (; add_id < to_be_add.size(); ++add_id) {
                int now = to_be_add[add_id];
                res.push_back(now);
                for (int i : outdu[now]) {
                    --indu[i];
                }
            }
            int add_num = 0;
            queue<int> que;
            for (int mr : member[gp]) {
                if (indu[mr] == 0) que.push(mr);
            }
            while (que.size()) {
                int cur = que.front();
                que.pop();
                res.push_back(cur);
                ++add_num;
                for (int i : outdu[cur]) {
                    if (--indu[i] == 0) {
                        if (group[i] == -1) to_be_add.push_back(i);
                        if (group[i] == gp) que.push(i);
                    }
                }
            }
            if (add_num != member[gp].size()) return vector<int>{};
        }
        return res;
    }
};

int main()
{
    return 0;
}
