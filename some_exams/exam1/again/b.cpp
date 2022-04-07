/*
简单的动态规划题
不会写，之前好不容易写的搜索还给超时了
*/

#include<bits/stdc++.h>
using namespace std;

int f[32][32];
int main(){
    int n,m;
    cin>>n>>m;
    memset(f,0,sizeof(f));
    f[1][1]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1) continue;// 跳过（1，1）开始的情况
            if(i%2==0&&j%2==0) f[i][j]=0; // 不可能走到偶数点，记为0
            else f[i][j]=f[i][j-1]+f[i-1][j];
        }
    }
    cout<<f[n][m]<<endl;
    system("pause");
    return 0;
}