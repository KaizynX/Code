#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int Maxn = 300;

struct Tree
{
	int v;
	Tree *l, *r;
	Tree(){ v = -1; l = nullptr; r = nullptr; } // v == -1 ==> no value

} tr[Maxn];

queue <Tree*> memory_pool;
queue <int> ans;

inline void init_memory();      // init memory_pool
inline void free_memory(Tree*); // refree the memory_pool
inline bool judge_tree(Tree*);  // judge if the tree is complete and get the answer
inline void print_tree();       // print the anser form queue<int> ans
inline Tree* new_tree();        // return a new memory for a new Tree
inline void clear(queue<int>&); // clear a queue<int>

int main()
{
	init_memory();
	string str;
	bool flag = true;
	int v;
	unsigned pos;
	Tree *cur,*root = new_tree();

	while(cin >> str)
	{
		if(str == "()")
		{
			if(flag && judge_tree(root)) print_tree();
			else
			{
				puts("not complete");
				clear(ans); // while print_tree, ans is cleared
			}
			free_memory(root);
			root = new_tree();
			flag = true;
			continue;
		}
		if(!flag) continue;

		cur = root;
		v = 0;
		// str[0] == '(' start from str[1]
		for(pos = 1; pos < str.length(); ++pos)
		{
			if(str[pos] < '0' || str[pos] > '9') break;
			v = v * 10 + str[pos] - '0';
		}
		// str[pos] == ',' start from str[++pos]
		// str.back() == ')' end with pos < str.lengh()-1
		for(++pos; pos < str.length()-1; ++pos)
		{
			if(str[pos] == 'L')
			{
				if(cur->l == nullptr) cur->l = new_tree();
				cur = cur->l;
			}
			else if(str[pos] == 'R')
			{
				if(cur->r == nullptr) cur->r = new_tree();
				cur = cur->r;
			}
		}
		// if nothing between ',' and ')' , cur == root
		// if v != -1 , the input is wrong
		if(cur->v != -1) flag = false;
		else cur->v = v;
	}
	return 0;
}

inline bool judge_tree(Tree *root)
{
	queue <Tree*> q;
	Tree *cur;

	q.push(root);
	while(!q.empty())
	{
		cur = q.front(); q.pop();
		// cause we had built the tree perfectly, any -1 means failure
		if(cur->v == -1) return false;
		// if( (cur->v == -1) && ( (cur->l != nullptr) || (cur->r != nullptr) ) ) return false;
		// if( cur == root && cur->v == -1) return false;
		ans.push(cur->v);
		if(cur->l) q.push(cur->l);
		if(cur->r) q.push(cur->r);
	}
	return true;
}

inline void clear(queue<int> &q)
{
	queue<int> tmp;
	swap(tmp,q);
}

inline void init_memory()
{
	for(int i = 0; i < Maxn; ++i) memory_pool.push(&tr[i]);
}

inline Tree* new_tree()
{
	Tree* t = memory_pool.front();
	memory_pool.pop();
	t->v = -1; t->l = nullptr; t->r = nullptr; // init
	return t; // return ptr, it's ok
}

inline void free_memory(Tree *cur)
{
	if(cur->l) free_memory(cur->l);
	if(cur->r) free_memory(cur->r);
	memory_pool.push(cur);
	return;
}

inline void print_tree()
{
	while(ans.size() > 1)
	{
		printf("%d ",ans.front());
		ans.pop();
	}
	printf("%d\n",ans.front());
	ans.pop();
}
