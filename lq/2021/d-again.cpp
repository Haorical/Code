#include<bits/stdc++.h>
using namespace std;
const int MAXN=3000;
const int INF=0x3fffffff;
int G[MAXN][MAXN];
bool vis[MAXN]={false};
int st,ed,n;
int d[MAXN];
int lcd(int x,int y){
    return x*y/__gcd(x,y);
}
vector<int> pre[MAXN];

void dj(int s){
    fill(d,d+MAXN,INF);
    d[s]=0;
    for(int i=1;i<=2021;i++){
        int u=-1,MIN=INF;
        for(int j=1;j<=2021;j++){
            if(vis[j]==false&&d[j]<MIN){
                MIN=d[j];
                u=j;
            }
        }
        //if(u==-1) return;
        vis[u]=true;
        for(int v=1;v<=2021;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    // pre[v].clear();
                    // pre[v].push_back(u);
                }
                // }else if(d[u]+G[u][v]==d[v]){
                //     pre[v].push_back(u);
                // }
            }
        }
    }
}

// vector<int> path,tmp;
// void dfs(int v){
//     if(v==st){
//         tmp.push_back(v);
//         for(int i=0)
//         return;
//     }
//     tmp.push_back(v);
//     for(int i=0;i<pre[v].size();i++){
//         dfs(pre[v][i]);
//     }
//     tmp.pop_back();
// }

void init(){
    fill(G[0],G[0]+MAXN*MAXN,INF);
    for(int i=1;i<=2021;i++){
        for(int j=1;j<=2021;j++){
            if(abs(i-j)<=21){
                G[i][j]=G[j][i]=lcd(i,j);
            }
        }
    }
}
int main(){
    init();
    dj(1);
    cout<<d[2021];
    system("pause");
    return 0;
}