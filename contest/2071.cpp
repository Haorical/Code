#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int G[N][N];
int n,k,m;
int cnt=0;
int color[N];
bool ok(int x){
    for(int i=1;i<x;i++){
        if(G[x][i]&&color[i]==color[x]) return false;
    }
    return true;
}
void dfs(int s){
    if(s==n+1){
        cnt++;
        return;
    }
    for(int i=1;i<=m;i++){
        color[s]=i;
        if(ok(s)) dfs(s+1);
        color[s]=0;
    }
    // for(int j=0;j<G[s].size();j++){
    //     for(int i=1;i<=m;i++)
    //         if(color[G[s][j]]!=i){
    //             color[s]=i;
    //             dfs(G[s][j]);
    //         }
    //     }
    // }
}
int main(){
    int t1,t2;
    cin>>n>>k>>m;
    for(int i=0;i<k;i++){
        cin>>t1>>t2;
        G[t1][t2]=G[t2][t1]=1;
    }
    dfs(1);
    cout<<cnt;
    system("pause");
    return 0;
}