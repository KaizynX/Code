#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#define DEBUG

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if(!pre.size()) return nullptr;
        TreeNode *cur = new TreeNode(pre[0]);
        if(pre.size() == 1) return cur;
        int pos;
        for(int i = 0, _size = post.size(); i < _size; ++i)
            if(post[i] == pre[1]) { pos = i; break; }
#ifdef DEBUG
        printf("%d\n", pos);
        int len = pre.size();
        for(int i = 0; i < len; ++i) printf("%d ", pre[i]);
        putchar('\n');
        for(int i = 0; i < len; ++i) printf("%d ", post[i]);
        putchar('\n');
#endif
        vector<int> tmpl_pre(pre.begin()+1, pre.begin()+pos+2), tmpl_post(post.begin(), post.begin()+pos+1);
        cur->left = constructFromPrePost(tmpl_pre, tmpl_post);
        vector<int> tmpr_pre(pre.begin()+pos+2, pre.end()), tmpr_post(post.begin()+pos+1, post.end()-1);
        cur->right = constructFromPrePost(tmpr_pre, tmpr_post);
        return cur;
    }

int main()
{
	vector<int> pre = {1,2,4,5,3,6,7}, post = {4,5,2,6,7,3,1};
	constructFromPrePost(pre, post);
	return 0;
}
