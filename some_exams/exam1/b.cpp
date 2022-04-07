#include<bits/stdc++.h>
using namespace std;
int cnt=0;

char a[31][31];
int dir[2][2]={{1,0},{0,1}};
int vis[31][31];


void dfs(int x,int y,int n,int m){
    if(x==n&&y==m){
        cnt++;
        return;
    }
    for(int i=0;i<2;i++){
        int xx=x+dir[i][0];
        int yy=y+dir[i][1];
        // printf("(%d,%d)\n",xx,yy);
        if(vis[xx][yy]==0&&xx<=n&&yy<=m){
            vis[xx][yy]=1;
            dfs(xx,yy,n,m);
            vis[xx][yy]=0;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i%2==0&&j%2==0){
                vis[i][j]=1;
            }
        }
    }
    dfs(1,1,n,m);
    cout<<cnt;
    system("pause");
    return 0;
}