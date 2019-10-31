#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXL=100005;
const int INF=2147480000;

class Splay//�洢����С����ң��ظ��ڵ��¼ 
{
    #define root e[0].ch[1]   //�����ĸ��ڵ�
    private:
        class node
        {
            public:
                int v,father;//�ڵ�ֵ�������ڵ� 
                int ch[2];//����=0���Һ���=1
                int sum;//�Լ�+�Լ��¼��ж��ٽڵ㡣�ڸ��ڵ�Ϊ1��
                int recy;//��¼�Լ����ظ��˼���
        };
        node e[MAXL];//Splay������
        int n,points;//ʹ�ô洢��,Ԫ����
        void update(int x)
        {
            e[x].sum=e[e[x].ch[0]].sum+e[e[x].ch[1]].sum+e[x].recy;
        }
        int identify(int x)
        {
            return e[e[x].father].ch[0]==x?0:1;
        }
        void connect(int x,int f,int son)//���Ӻ������÷���connect(son,father,1/0)
        {
            e[x].father=f;
            e[f].ch[son]=x;
        }//���ã�ʹ��x��father=f��f��son=x.
        void rotate(int x)
        {
            int y=e[x].father;
            int mroot=e[y].father;
            int mrootson=identify(y);
            int yson=identify(x);
            int B=e[x].ch[yson^1];
            connect(B,y,yson);connect(y,x,(yson^1));connect(x,mroot,mrootson);
            update(y);update(x);
        }
        void splay(int at,int to)//��atλ�õĽڵ��ƶ���toλ��
        {
            to=e[to].father;
            while(e[at].father!=to)
            {
                int up=e[at].father;
                if(e[up].father==to) rotate(at);
                else if(identify(up)==identify(at))
                {
                    rotate(up);
                    rotate(at);
                }
                else
                {
                    rotate(at);
                    rotate(at);
                }
            }
        }
        int crepoint(int v,int father)
        {
            n++;
            e[n].v=v;
            e[n].father=father;
            e[n].sum=e[n].recy=1;
            return n;
        }
        void destroy(int x)//pop��ݻٽڵ� 
        {
            e[x].v=e[x].ch[0]=e[x].ch[1]=e[x].sum=e[x].father=e[x].recy=0;
            if(x==n) n--;//����޶��Ż�
        }
    public:
        int getroot(){return root;}
        int find(int v)//�����ⲿ��find����
        {
            int now=root;
            while(true)
            {
                if(e[now].v==v)
                {
                    splay(now,root);
                    return now;
                }
                int next=v<e[now].v?0:1;
                if(!e[now].ch[next]) return 0;
                now=e[now].ch[next];
            }
        }
        int build(int v)//�ڲ����õĲ��뺯����û��splay 
        {
            points++;
            if(n==0)//�����޵�״̬ 
            {
                root=1;
                crepoint(v,0);
            }
            else
            {
                int now=root;
                while(true)//�����ҵ�һ���սڵ� 
                {
                    e[now].sum++;//�Լ����¼��϶�������һ���ڵ� 
                    if(v==e[now].v)
                    {
                        e[now].recy++;
                        return now;
                    }
                    int next=v<e[now].v?0:1;
                    if(!e[now].ch[next])
                    {
                        crepoint(v,now);
                        e[now].ch[next]=n;
                        return n;
                    }
                    now=e[now].ch[next];
                }
            }
            return 0;
        }
        void push(int v)//����Ԫ��ʱ������ӽڵ㣬�ٽ�����չ 
        {
            int add=build(v);
            splay(add,root);
        }
        void pop(int v)//ɾ���ڵ� 
        {
            int deal=find(v);
            if(!deal) return;
            points--;
            if(e[deal].recy>1)
            {
                e[deal].recy--;
                e[deal].sum--;
                return;
            }
            if(!e[deal].ch[0])
            {
                root=e[deal].ch[1];
                e[root].father=0;
            }
            else
            {
                int lef=e[deal].ch[0];
                while(e[lef].ch[1]) lef=e[lef].ch[1];
                splay(lef,e[deal].ch[0]);
                int rig=e[deal].ch[1];
                connect(rig,lef,1);connect(lef,0,1);
                update(lef);
            }
            destroy(deal);
        }
        int rank(int v)//��ȡֵΪv��Ԫ������������ǵڼ�С 
        {
            int ans=0,now=root;
            while(true)
            {
                if(e[now].v==v) return ans+e[e[now].ch[0]].sum+1;
                if(now==0) return 0;
                if(v<e[now].v) now=e[now].ch[0];
                else
                {
                    ans=ans+e[e[now].ch[0]].sum+e[now].recy;
                    now=e[now].ch[1];
                }
            }
            if(now) splay(now,root);
            return 0;
        }
        int atrank(int x)//��ȡ��xС��Ԫ�ص�ֵ 
        {
            if(x>points) return -INF;
            int now=root;
            while(true)
            {
                int minused=e[now].sum-e[e[now].ch[1]].sum;
                if(x>e[e[now].ch[0]].sum&&x<=minused) break;
                if(x<minused) now=e[now].ch[0];
                else
                {
                    x=x-minused;
                    now=e[now].ch[1];
                }
            }
            splay(now,root);
            return e[now].v;
        }
        int upper(int v)//Ѱ�Ҹ�ֵ��Ӧ��һ��������Ͻ�ֵ 
        {
            int now=root;
            int result=INF;
            while(now)
            {
                if(e[now].v>v&&e[now].v<result) result=e[now].v;
                if(v<e[now].v) now=e[now].ch[0];
                else now=e[now].ch[1];
            }
            return result;
        }
        int lower(int v)//Ѱ�Ҹ�ֵ��Ӧ��һ��������½�ֵ 
        {
            int now=root;
            int result=-INF;
            while(now)
            {
                if(e[now].v<v&&e[now].v>result) result=e[now].v;
                if(v>e[now].v) now=e[now].ch[1];
                else now=e[now].ch[0];
            }
            return result;
        }
    #undef root
} tree;

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
    x = c-'0';
    while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void write(T x)
{
    if(x < 0) x = -x, putchar('-');
    if(x > 9) write(x/10);
    putchar(x%10+'0');
}

int n;

int main()
{
    read(n);
    for (int i = 1, opt, x; i <= n; ++i) {
        read(opt);
        read(x);
        switch (opt) {
            case 1 :
                tree.push(x);
                break;
            case 2 :
                tree.pop(x);
                break;
            case 3 :
                write(tree.rank(x));
                putchar('\n');
                break;
            case 4 :
                write(tree.atrank(x));
                putchar('\n');
                break;
            case 5 :
                write(tree.lower(x));
                putchar('\n');
                break;
            case 6 :
                write(tree.upper(x));
                putchar('\n');
                break;
        }
    }
    return 0;
}
