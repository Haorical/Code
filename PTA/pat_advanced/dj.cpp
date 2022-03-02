#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
const int INF=0x3fffffff;

int d[MAXN];
bool vis[MAXN]={false};
int G[MAXN][MAXN];
int n,st;

vector<int> pre[MAXN]; // 存放节点前驱节点
vector<int> path,tempPath; // 最优路径，临时路径

void dj(int s){
    fill(d,d+MAXN,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1;
        int MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                MIN=d[j];
                u=j;
            }
        }
        if(u==-1) return;
        vis[u]=true;//易忘
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){ //是G[u][v]不是d[v]
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

int optvalue;
void dfs(int v) //当前访问节点
{
    if(v==st){
        tempPath.push_back(v);
        int value;
        //计算value;
        if(value优于optvalue){
            optvalue=value;
            path=tempPath;
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for(int i=0;i<pre[v].size();i++){
        dfs(pre[v][i]);
    }
    tempPath.pop_back();
}

int main(){

}