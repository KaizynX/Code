#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main()
{
    int n,b;
    cin>>n;
    if(n==0)cout<<"0"<<endl;
    for(int i=0;i<n;i++){
        cin>>b;
        s.insert(b);
    }
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();++it){
        cout<<*it<<" ";
    }
    return 0;
}
