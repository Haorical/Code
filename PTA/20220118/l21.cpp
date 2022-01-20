#include<bits/stdc++.h>
using namespace std;
struct node
{
    string name;
    int ct;
}nd[102];
bool cmp(node x,node y){
    if(x.ct<y.ct) return true;
    return false;
}
set<int> s;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        s.clear();
        cin>>nd[i].name;
        int k,t;
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>t;
            s.insert(t);
        }
        nd[i].ct=s.size();
    }
    sort(nd,nd+n,cmp);
    if(n==1){
        cout<<nd[n-1].name<<" - -";
        return 0;
    }
    for(int i=n-1;i>=n-3;i--){
        cout<<nd[i].name;
        if(i>n-3) cout<<" ";
    }
    return 0;
}