#include<bits/stdc++.h>
using namespace std;
int s[10002];
int find_set(int x){
    if(x==s[x]) return x;
    else{
        s[x]=find_set(x);
    }
    return s[x];
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        s[i]=i;
    }
    while(n--){
        int t,t1;
        cin>>t;
        cin>>t1;
        t--;
        while(t--){
            int tp;
            cin>>tp;
            s[tp]=t1;
        }
    }
    system("pause");
    return 0;
}