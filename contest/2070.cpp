#include<bits/stdc++.h>
#define close ios::sync_with_stdio(false)
using namespace std;
int A,B,C,vis[30][30][30],rec[30];
void DFS(int a,int b,int c)
{
    if(vis[a][b][c]) return;
    vis[a][b][c]=1;
    if(a>0){
        (b+a<=B)?DFS(0,b+a,c):DFS(a-(B-b),B,c);
        (c+a<=C)?DFS(0,b,c+a):DFS(a-(C-c),b,C);
    } 
    if(b>0){
        (a+b<=A)?DFS(b+a,0,c):DFS(A,b-(A-a),c);
        (c+b<=C)?DFS(a,0,c+b):DFS(a,b-(C-c),C);
    }
    if(c>0){
        (a+c<=A)?DFS(a+c,b,0):DFS(A,b,c-(A-a));
        (b+c<=B)?DFS(a,b+c,0):DFS(a,B,c-(B-b));
    }
}
int main()
{
    close;
    while(cin>>A>>B>>C)
    {
        memset(vis,0,sizeof(vis));
        memset(rec,0,sizeof(rec));
        DFS(0,0,C);
        for(int i=0;i<=B;++i)
            for(int j=0;j<=C;++j)
                if(vis[0][i][j]) rec[j]=1;
        for(int i=0;i<=C;++i) if(rec[i]) cout<<i<<' ';
        cout<<endl;
    }
}
