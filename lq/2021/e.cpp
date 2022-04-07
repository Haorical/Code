#include<bits/stdc++.h>
using namespace std;
// const int MAXN=100;
// const int INF=0x3fffffff;
// int n=21,G[MAXN][MAXN];
// bool vis[MAXN]={false};
// bool judge(int a[]){
//     for(int i=1;i<=21;i++){
//         if(a[i]==0) return false;
//     }
//     return true;
// }
// void init(){
//     fill(G[0],G[0]+MAXN*MAXN,INF);
//     for(int i=1;i<=21;i++){
//         for(int j=1;j<=21;j++){
//             if(__gcd(i,j)==1){
//                 G[i][j]=G[j][i]=1;
//             }
//         }
//     }
// }
// int cnt=0;
// int is1[22];
// void dfs(int u,int depth){
//     if(depth==21){
//         if(judge(is1)){
//             cnt++;
//             return;
//         }
//     }
//     vis[u]=true;
//     for(int v=1;v<=21;v++){
//         if(vis[v]==false&&G[u][v]!=INF){
//             dfs(v,depth+1);
//         }
//     }
// }
typedef long long LL;

const int N = 22, M = 1 << N;

LL f[M][N];
bool e[N][N];

int main()
{
	for (int i = 1; i <= 21; i ++)
		for (int j = 1; j <= 21; j ++)
			if(__gcd(i, j) == 1)
				e[i][j] = true;
				
	f[2][1] = 1;
	for (int i = 2; i <= M - 2; i ++) // 枚举状态
		for (int j = 1; j <= 21; j ++) // 枚举起点
			if(i >> j & 1)
				for (int k = 1; k <= 21; k ++)  // 枚举终点
					if(i - (1 << j) >> k & 1 && e[k][j])
						f[i][j] += f[i - (1 << j)][k];
	
	LL ans = 0;
	for (int i = 2; i <= 21; i ++)
		ans += f[M - 2][i];
	
	cout << ans << endl;
    system("pause");
	return 0;								
}
