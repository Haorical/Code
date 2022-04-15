#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int INF=0x3fffffff;
int n,m,st,ed;
int G[N][N];
int d[N],w[N];
bool vis[N]={false};
vector<int> pre[N];
void dj(int s){
    fill(d,d+N,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                MIN=d[j];
                u=j;
            }
        }
        if(u==-1) return;
        vis[u]=true; //又忘了
        for(int v=0;v<n;v++){
            if(vis[v]==false){
                if(d[u]+G[u][v]==d[v]){
                    pre[v].push_back(u);
                }else if(d[u]+G[u][v]<d[v]){
                    pre[v].clear();
                    pre[v].push_back(u);
                    d[v]=d[u]+G[u][v];
                }
            }
        }
    }
}
vector<int> path,tmp;
int mv=0,cnt=0;
void dfs(int u){
    if(u==st){
        cnt++;
        tmp.push_back(u);
        int ans=0;
        for(int i=0;i<tmp.size();i++){
            ans+=w[tmp[i]];
        }
        if(ans>mv){
            mv=ans;
            path=tmp;
        }
        tmp.pop_back();
        return;
    }
    tmp.push_back(u);
    for(int i=0;i<pre[u].size();i++){
        dfs(pre[u][i]);
    }
    tmp.pop_back();
}

int main(){
    fill(G[0],G[0]+N*N,INF);
    cin>>n>>m>>st>>ed;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    int t1,t2,t3;
    for(int i=0;i<m;i++){
        cin>>t1>>t2>>t3;
        G[t1][t2]=G[t2][t1]=t3;
    }
    dj(st);
    dfs(ed);
    cout<<cnt<<" "<<mv<<endl;
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i];
        if(i>0) cout<<" ";
    }
    system("pause");
    return 0;
}