#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int Maxn = 1e4 + 7;

struct Tree
{
	int v;
	Tree *l, *r;
	Tree(): v(0),l(nullptr),r(nullptr) {}
} tr[Maxn];

queue <Tree*> memory_pool;
string str_LRD, str_LDR;
int arr_LRD[Maxn], arr_LDR[Maxn];
int pos_LDR[Maxn];

inline void init_memory();
inline Tree* new_tree();
inline void delete_tree(Tree *);
void build_tree(int,int,int,int,Tree*);
inline int bfs(Tree*);

int main()
{
	int cnt;
	Tree *root;
	init_memory();
	while(getline(cin,str_LDR) && getline(cin,str_LRD))
	{
		// memset(pos_LDR,0,sizeof pos_LDR);
		root = new_tree();
		cnt = 0;
		for(unsigned i = 0, num = 0; i < str_LRD.length(); ++i)
		{
			if(str_LRD[i] < '0' || str_LRD[i] > '9') // reset
			{
				arr_LRD[++cnt] = num;
				num = 0;
				continue;
			}
			num = num * 10 + str_LRD[i] - '0';
			if(i == str_LRD.length()-1) arr_LRD[++cnt] = num; // last one
		}
		cnt = 0;
		for(unsigned i = 0, num = 0; i < str_LDR.length(); ++i)
		{
			if(str_LDR[i] < '0' || str_LDR[i] > '9') // reset
			{
				arr_LDR[++cnt] = num;
				num = 0;
				pos_LDR[arr_LDR[cnt]] = cnt;
				continue;
			}
			num = num * 10 + str_LDR[i] - '0';
			if(i == str_LDR.length()-1)
			{
				arr_LDR[++cnt] = num;
				pos_LDR[arr_LDR[cnt]] = cnt;
			}
		}

		build_tree(1,cnt,1,cnt,root);
		printf("%d\n",bfs(root));
		delete_tree(root);
	}
	return 0;
}

inline int bfs(Tree* root)
{
	queue <Tree*> q;
	queue <int> w;
	Tree* cur;
	int weight, ans_v = Maxn, ans_w = Maxn * Maxn;
	q.push(root);
	w.push(root->v);
	while(!q.empty())
	{
		cur = q.front(); q.pop();
		weight = w.front(); w.pop();

		if(weight > ans_w) continue; // it's child must bigger
		if(cur->l == nullptr && cur->r == nullptr)
		{
			if(weight < ans_w) { ans_w = weight; ans_v = cur->v; }
			else ans_v = min(ans_v,cur->v); // weight == ans_w
		}

		if(cur->l) { q.push(cur->l); w.push(weight+cur->l->v); }
		if(cur->r) { q.push(cur->r); w.push(weight+cur->r->v); }
	}
	return ans_v;
}

void build_tree(int LDR_l,int LDR_r,int LRD_l,int LRD_r,Tree* cur)
{
#ifdef DEBUG
	printf("%d %d %d %d\n",LDR_l,LDR_r,LRD_l,LRD_r);
#endif
	// if(LDR_l > LDR_r || LRD_l > LRD_r) { delete_tree(cur); return; }
	cur->v = arr_LRD[LRD_r];
	int pos = pos_LDR[ arr_LRD[LRD_r] ];
	if(LDR_l <= pos-1 && LRD_l <= LRD_l+(pos-LDR_l)-1)
		build_tree(LDR_l,pos-1,LRD_l,LRD_l+(pos-LDR_l)-1,cur->l = new_tree());
	if(pos+1 <= LDR_r && LRD_l+(pos-LDR_l) <= LRD_r-1)
		build_tree(pos+1,LDR_r,LRD_l+(pos-LDR_l),LRD_r-1,cur->r = new_tree());
}

inline void delete_tree(Tree *cur)
{
	if(cur->l) delete_tree(cur->l);
	if(cur->r) delete_tree(cur->r);
	memory_pool.push(cur);
}

inline Tree* new_tree()
{
	Tree *t = memory_pool.front();
	memory_pool.pop();
	t->v = 0; t->l = nullptr; t->r = nullptr; // init
	return t;
}

inline void init_memory()
{
	for(int i = 0; i < Maxn; ++i) memory_pool.push(&tr[i]);
}
