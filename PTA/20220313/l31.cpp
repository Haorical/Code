#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000;
const int INF=0x3fffffff;
int st,ed,n;
int d[MAXN];
int G[MAXN][MAXN];
bool vis[MAXN]={false};
vector<int> path;
void dj(int s){
    fill(d,d+MAXN,INF);
    d[s]=0;
    for(int i=0;i<n;i++){
        int u=-1,MIN=INF;
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){
                MIN=d[j];
                u=j;
            }
        }
        for(int v=0;v)
    }
}
int main(){
    system("pause");
    return 0;
}