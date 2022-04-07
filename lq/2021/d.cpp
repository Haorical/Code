#include<bits/stdc++.h>
using namespace std;
const int INF=0x3fffffff;
const int MAXN=2030;
int G[MAXN][MAXN];
int d[MAXN];
int n=2022;
bool vis[MAXN]={false};
int gg(int x,int y){
    if(abs(x-y)>21) return INF;
    return x*y/__gcd(x,y);
}

void dj(int s){
    fill(d,d+MAXN,INF);
    d[s]=0;
    for(int i=1;i<n;i++){
        int u=-1;
        int MIN=INF;
        for(int j=1;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        vis[u]=true;
        for(int v=1;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                }
            }
        }
    }
}

int main(){
    fill(G[0],G[0]+MAXN*MAXN,INF);

    for(int i=1;i<=2021;i++){
        for(int j=1;j<=2021;j++){
            G[i][j]=G[j][i]=gg(i,j);
        }
    }
    dj(1);
    cout<<d[2021];
    system("pause");
    return 0;
}