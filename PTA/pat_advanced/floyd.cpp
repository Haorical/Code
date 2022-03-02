#include<bits/stdc++.h>
using namespace std;

const int MAXN=200;
const int INF=0x3fffffff;
int n,m;
int dis[MAXN][MAXN]; //dis[i][j] i到j的最短距离

void flyod(){
    for(int k=0;k<n;k++){ //枚举k,以k为中介点
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){ //枚举所有i,j
                if(dis[i][k]!=INF&&dis[k][j]!=INF&&dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
}
int main(){
    int u,v,w;
    fill(dis[0],dis[0]+MAXN*MAXN,INF);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        dis[i][i]=0; //初始化顶点到自己距离为0
    }
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        dis[u][v]=w;
    }
    flyod();
    for(int i = 0; i < n; i++) { //输出 dis 数组
        for(int j = 0; j < n; j++) { 
            printf("%d ",dis[i][j]);
        }
        printf ("\n"); 
    }
    system("pause");
    return 0;
}