#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int Maxn = 1e5 + 7; // ???

struct Tree
{
	int lv,rv,ld,rd;
	Tree *l, *r;
	Tree():lv(0),rv(0),ld(0),rd(0),l(nullptr),r(nullptr){}
} tr[Maxn];

int n;
queue <Tree*> memory_pool;

inline void init_memory();
inline void delete_tree(Tree*);
inline Tree* new_tree();
bool build_tree(Tree*);

int main()
{
	Tree *root;
	init_memory();
	scanf("%d",&n);
	while(n--)
	{
		if(build_tree(root = new_tree())) puts("YES");
		else puts("NO");
		delete_tree(root);
		if(n) putchar('\n');
	}
	return 0;
}

bool build_tree(Tree* cur)
{
	bool ok_l = true, ok_r = true, ok_c = true;
	scanf("%d%d%d%d",&cur->lv,&cur->ld,&cur->rv,&cur->rd);
	if(! cur->lv)
	{
		ok_l = build_tree(cur->l = new_tree());
		cur->lv = cur->l->lv + cur->l->rv;
	}
	if(! cur->rv)
	{
		ok_r = build_tree(cur->r = new_tree());
		cur->rv = cur->r->lv + cur->r->rv;
	}
	ok_c = cur->lv * cur->ld == cur->rv * cur->rd;
#ifdef DEBUG
	printf("%d %d %d %d %d %d %d\n",cur->lv,cur->ld,cur->rv,cur->rv,ok_l,ok_r,ok_c);
#endif
	return ok_l && ok_r && ok_c;
}

inline Tree* new_tree()
{
	Tree* t = memory_pool.front();
	memory_pool.pop();
	t->lv = 0; t->rv = 0; t->ld = 0; t->rd = 0; t->l = nullptr; t->r = nullptr;
	return t;
}

inline void delete_tree(Tree* cur)
{
	if(cur->l) delete_tree(cur->l);
	if(cur->r) delete_tree(cur->r);
	memory_pool.push(cur);
}

inline void init_memory()
{
	for(int i = 0; i < Maxn; ++i) memory_pool.push(&tr[i]);
}
