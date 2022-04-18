//基础并查集
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int f[N],n=0;
bool vis[N]={false};
int findf(int x){
    if(x==f[x]) return x;
    f[x]=findf(f[x]);
    return f[x];
}
void unionf(int a,int b){
    a=findf(a);
    b=findf(b);
    if(a!=b) f[a]=b;
}

void init(){
    for(int i=1;i<N;i++){
        f[i]=i;
    }
}

int cnt(){
    int count=0;
    for(int i=1;i<=n;i++){
        if(f[i]==i&&vis[i]) count++;
    }
    return count;
}
int main(){
    int k,t1,t2,t3;
    init();
    cin>>k;
    while(k--){
        cin>>t1>>t2;
        vis[t2]=true;
        t1--;
        n=max(n,t2);
        while(t1--){
            cin>>t3;
            n=max(n,t3); //忘了写1 4测试点没过
            vis[t3]=true;
            unionf(t2,t3);
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) sum++; 
    }
    cout<<sum<<' '<<cnt()<<endl;
    cin>>t1;
    while(t1--){{
        cin>>t2>>t3;
        if(findf(t2)==findf(t3)) cout<<'Y';
        else cout<<'N';
        if(t1>0) cout<<'\n';
    }}
    system("pause");
    return 0;
}