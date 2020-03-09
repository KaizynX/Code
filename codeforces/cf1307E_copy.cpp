#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>

const int MOD=1e9+7;

int modexp(int base,int exp){
  int ac=1;
  for(;exp;exp>>=1){
    if(exp&1) ac=1LL*ac*base%MOD;
    base=1LL*base*base%MOD;
  }
  return ac;
}

int inverse(int x){
  return modexp(x,MOD-2);
}

int fs[100005];
int left[100005],right[100005];
std::vector<int> cows[100005];//cows[f]: hunger of cows that like flavor f 
int asleep[100005];
int ways[100005];
int total_asleep=0,total_ways=1;

void calc_ways(int f){
  int a=std::upper_bound(cows[f].begin(),cows[f].end(),left[f])-cows[f].begin();
  int b=std::upper_bound(cows[f].begin(),cows[f].end(),right[f])-cows[f].begin();
  if(a>b) std::swap(a,b);
  long long cnt2=1LL*a*b-a;
  int cnt1=a+b;
  cnt2%=MOD;
  if(cnt2>0){
    asleep[f]=2;
    ways[f]=cnt2;
  }else if(cnt1>0){
    asleep[f]=1;
    ways[f]=cnt1;
  }else{
    asleep[f]=0;
    ways[f]=1;
  }
}

//fixed left cow, with hunger left[i]
//precondition: such cow exists
void calc_ways_stuck(int f){
  int b=std::upper_bound(cows[f].begin(),cows[f].end(),right[f])-cows[f].begin();
  if(right[f]>=left[f])
    b--;
  int cnt2=b;
  if(cnt2>0){
    asleep[f]=2;
    ways[f]=cnt2;
  }else{
    asleep[f]=1;
    ways[f]=1;
  }
}

int ans_asleep=0,ans_ways=0;

void add_to_ans(int asleep,int ways){
  if(asleep>ans_asleep){
    ans_asleep=asleep;
    ans_ways=0;
  }
  if(asleep==ans_asleep)
    ans_ways=(ans_ways+ways)%MOD;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=1;i<=N;i++){
    scanf("%d",&fs[i]);
    right[fs[i]]++;
  }
  for(int i=0;i<M;i++){
    int F,H;
    scanf("%d %d",&F,&H);
    cows[F].push_back(H);
  }
  for(int f=1;f<=N;f++)
    std::sort(cows[f].begin(),cows[f].end());
  for(int f=1;f<=N;f++){
    calc_ways(f);
    total_asleep+=asleep[f];
    total_ways=1LL*total_ways*ways[f]%MOD;
  }
  add_to_ans(total_asleep,total_ways);
  for(int i=1;i<=N;i++){
    total_asleep-=asleep[fs[i]];
    total_ways=1LL*total_ways*inverse(ways[fs[i]])%MOD;
    right[fs[i]]--;
    left[fs[i]]++;
    if(std::binary_search(cows[fs[i]].begin(),cows[fs[i]].end(),left[fs[i]])){
      calc_ways_stuck(fs[i]);
      int here_asleep=total_asleep+asleep[fs[i]];
      int here_ways=1LL*total_ways*ways[fs[i]]%MOD;
      add_to_ans(here_asleep,here_ways);
    }
    calc_ways(fs[i]);
    total_asleep+=asleep[fs[i]];
    total_ways=1LL*total_ways*ways[fs[i]]%MOD;
  }
  printf("%d %d\n",ans_asleep,ans_ways);
}
