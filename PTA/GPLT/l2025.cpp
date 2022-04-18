// 和13红色警戒那题差不多，求连通块，并查集，搜索都可以做
// 这里用的并查集码量少
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int f[N],n,m;
bool vis[N]={false};
struct node{
    int x,y;
}nd[N];
void init(){
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
}
int count(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&f[i]==i) cnt++;
    }
    return cnt;
}
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

int main(){
    cin>>n>>m;
    int t1,t2;
    for(int i=0;i<m;i++){
        cin>>t1>>t2;
        nd[i].x=t1;
        nd[i].y=t2;
    }
    int k;
    cin>>k;
    while(k--){
        memset(vis,0,sizeof(vis));
        init();
        int t3;
        cin>>t3;
        for(int i=0;i<t3;i++){
            cin>>t2;
            vis[t2]=true;
        }
        for(int i=0;i<m;i++){
            if(!vis[nd[i].x]&&!vis[nd[i].y]) unionf(nd[i].x,nd[i].y);
        }
        int sum1=count();
        //cout<<sum0<<" "<<t3<<" "<<sum1<<endl;
        if(t3+sum1==n) cout<<"YES"; //这里第一次判断错了
        else cout<<"NO";
        if(k>0) cout<<endl;
    }
    system("pause");
    return 0;
}