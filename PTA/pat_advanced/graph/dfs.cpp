/*
DFS(u){ 访问顶点u
    vis[u]=true;
    for(与u相邻的顶点v){
        if vis[v]==false
            DFS(v);
    }
}
DFSTrave(G){ 遍历图
    for(G的所有顶点u){
        if vis[u]==false
            DFS(u);
    }
}
*/

# include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
const int INF=0x3fffffff;
// 邻接矩阵
int n,G[MAXN][MAXN];
bool vis[MAXN]={false};

void dfs(int u,int depth){
    vis[u]=true;
    for(int v=0;v<n;v++){
        if(vis[v]==false&&G[u][v]!=INF){
            dfs(v,depth+1);
        }
    }
}

void dfsTrave(){
    for(int u=0;u<n;u++){
        if(vis[u]==false){
            dfs(u,1);
        }
    }
}

// 邻接表
vector<int> g[MAXN];
int n;
bool vis[MAXN]={false};

void dfs2(int u,int depth){
    vis[u]=true;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]==false){
            dfs2(v,depth+1);
        }
    }
}

void dfst2(){
    for(int u=0;u<n;u++){
        if(vis[u]==false){
            dfs2(u,1);
        }
    }
}

