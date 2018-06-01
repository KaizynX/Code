#include <iostream>
#include <set>
using namespace std;
set<int> s1;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s1.insert(a[i]);
    }
    set<int>::iterator it;
    for(it=s1.begin();it!=s1.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}
