//dijkatra单源最短路径算法，复习了下数据结构，有点忘了

/*
伪代码
s:已经求出的最短路径终点
v:顶点集
1 初始化 v0->s
  dist[j]<-weight[0][j],j=1,2,...,n-1
2 求最短路径 dist[k]<-min{dis[i]},s<-s+=k
3 修改 dist[i]<-min{dist[i],dist[k][i]},对于每一个i属于v-s
4 判断 s==k,算法结束，否则转2

*/
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3fffffff;
const int MAXV=1000;
int n,m,c1,c2;
int w[MAXV]; //s到u的最大物资
int num[MAXV]; //s到u的最短路径条数
int weight[MAXV]; //点v拥有的物资
int d[MAXV];
bool vis[MAXV]={false}; //S数组表示
int G[MAXV][MAXV];

int dj(int s){
    fill(d,d+MAXV,INF); //将dist数组初始化
    memset(w,0,sizeof(w)); //s到u的物资置为0
    memset(num,0,sizeof(num));//s到u的最短路径条数置为0
    d[s]=0; //起点距离为0
    num[s]=1;
    w[s]=weight[s];
    for(int i=0;i<n;i++){ 
        int u=-1,MIN=INF; //找到最小d的一条边，MIN存储最小值
        for(int j=0;j<n;j++){
            if(vis[j]==false&&d[j]<MIN){ //未访问过的最小d
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return -1;
        vis[u]=true; //加入S中
        for(int v=0;v<n;v++){
            if(vis[v]==false&&G[u][v]!=INF){ //优化d[v]
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }else if(d[u]+G[u][v]==d[v]){
                    if(w[u]+weight[v]>w[v])
                        w[v]=w[u]+weight[v]; //w[v]继承自w[u]
                    num[v]+=num[u]; //找到一条长度相等的路径,与点权无关
                } 
            }
        }
    }
    return d[c2];
}
int main(){
    fill(G[0],G[0]+MAXV*MAXV,INF);// 一定要初始化G
    cin>>n>>m>>c1>>c2;
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    for(int i=0;i<m;i++){
        int t1,t2,t3;
        cin>>t1>>t2>>t3;
        G[t1][t2]=G[t2][t1]=t3;
    }
    dj(c1);
    cout<<num[c2]<<' '<<w[c2];
    system("pause");
    return 0;
}

/*
n m c1 c2
1 2 ... n
c1 c2 l

*/                                                            