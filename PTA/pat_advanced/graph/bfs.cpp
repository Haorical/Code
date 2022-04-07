/*
bfs(u){
    queue q;
    将u入队
    inq[u]=true;
    while(!q.empty()){
        取出队首元素；
        for(与u相邻节点){
            if(inq[v]==false){
                inq[v]=true;
            }
        }
    }
}
*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
const int INF=0x3fffffff;
int n,G[MAXN][MAXN];
bool inq[MAXN]={false};
//邻接矩阵
void bfs(int u){
    queue<int> q;
    q.push(u);
    inq[u]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<n;v++){
            if(inq[v]==false&&G[u][v]!=INF){
                q.push(v);
                inq[v]=true;//易忘
            }
        }
    }
}
void bfstravel(){
    for(int u=0;u<n;u++){
        if(inq[u]==false){
            bfs(u);
        }
    }
}

//邻接表版
vector<int> g[MAXN];
void bfs2(int u){
    queue<int> q;
    inq[u]=true;
    q.push(u);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<g[u].size();i++){
            int v=g[u][i];
            if(inq[v]==false){
                q.push(v);
                inq[v]=true;
            }
        }
    }
}