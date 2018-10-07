#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const string OK = "SUCCESS";
const string NO = "UNSUCCESS";

struct Node
{
	long long v;
	Node *pre, *nex;
	Node() { v = 0; pre = nullptr; nex = nullptr; }
} arr[Maxn];

int head[2], tail[2], sz[2];
queue<*Node> memory_pool;

inline void init_memory();
inline Node* new_memory();
inline void del_memory(Node*);
inline void PUSH(int, long long);
inline void POP(int);
inline void ADD(int);
inline void SUB(int);
inline void DEL(int);
inline void MOVE(int, int);

int main()
{
	int state = 0, x, y;
	long long num;
	string ope;
	while(cin >> ope && ope != "END")
	{
		scanf("%d", &x);
		if(ope == "PUSH")
		{
			scanf("%lld", &num);
			PUSH(x^state, num);
		}
		else if(ope == "POP") POP(x^state);
		else if(ope == "ADD") ADD(x^state);
		else if(ope == "SUB") SUB(x^state);
		else if(ope == "DEL") DEL(x^state);
		else if(ope == "MOVE")
		{
			scanf("%d", &y);
			MOVE(x^state, y^state);
		}
		else if(ope == SWAP)
		{
			id ^= 1;
			cout << OK << endl;
		}
	}
	return 0;
}


inline void PUSH(int, long long);
inline void POP(int);
inline void ADD(int);
inline void SUB(int);
inline void DEL(int);
inline void MOVE(int, int);

inline void init_memory()
{
	for(int i = 0; i < Maxn; ++i) memory_pool.push(&arr[i]);
}

inline Node* new_memory()
{
	Node *ptr = memory_pool.front();
	memory_pool.pop();
	ptr->v = 0; ptr->l = nullptr; ptr->r = nullptr;
	return ptr;
}

inline void del_memory(Node *ptr)
{
	memory_pool.push(ptr);
}
