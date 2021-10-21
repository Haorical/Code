#include<iostream>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std;
int a[102];
int main(){
    memset(a,0,sizeof(a));
    set<int> s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s.insert(a[i]);
    }
    int min=0,max=0;
    for(int i=0;i<n;i++){
        max+=a[i];
    }
    for(auto i:s){
        min+=i;
    }
    cout<<max<<'\n'<<min;
    system("pause");
    return 0;
}