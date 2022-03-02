#include<bits/stdc++.h>
using namespace std;
const int MAXN=510;
const int INF=0x3fffffff;

int n,m,st,ed;
int G[MAXN][MAXN];
int weight[MAXN][MAXN];
int d[MAXN];
bool vis[MAXN]={false};
vector<int> pre[MAXN];
void dj(int s){
    fill(d,d+MAXN,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1;
        int MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u]+G[u][v]==d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
int maxValue=INF;
vector<int> path,tmpPath;

void dfs(int v){
    if(v==st){
        tmpPath.push_back(v);
        int value=0;
        for(int i=0;i<tmpPath.size()-1;i++){
            value+=weight[tmpPath[i]][tmpPath[i+1]];
        }
        if(value<maxValue){
            maxValue=value;
            path=tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        dfs(pre[v][i]);
    }
    tmpPath.pop_back();
}

int main(){
    cin>>n>>m>>st>>ed;
    fill(G[0],G[0]+MAXN*MAXN,INF);
    int t1,t2,t3,t4;
    for(int i=0;i<m;i++){
        cin>>t1>>t2>>t3>>t4;
        G[t1][t2]=G[t2][t1]=t3;
        weight[t1][t2]=weight[t2][t1]=t4;
    }
    dj(st);
    dfs(ed);
    for(int i=path.size()-1;i>=0;i--){
        cout<<path[i]<<" ";
    }
    cout<<d[ed]<<" "<<maxValue;
    system("pause");
    return 0;
}