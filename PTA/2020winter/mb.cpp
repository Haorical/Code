#include<bits/stdc++.h>
using namespace std;
const int INF=0x3fffffff;
const int MAXN=1000;
bool vis[MAXN]={false};
int d[MAXN];
int n,st,ed;
vector<int> pre[MAXN];
int G[MAXN][MAXN];

void dj(int s){
    fill(d,d+n,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(d[u]+G[u][v]==d[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
vector<int> path,tmp;
int mv=0;

void dfs(int v){
    if(v==st){
        tmp.push_back(v);
        int value=11111;
        if(value>mv){
            mv=value;
            path=tmp;
        }
        tmp.pop_back();
        return;
    }
    tmp.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        dfs(pre[v][i]);
    }
    tmp.pop_back();
}

int main(){
    system("pause");
}