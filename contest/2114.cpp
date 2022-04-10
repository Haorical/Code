// #include<bits/stdc++.h>
// using namespace std;
// const int MAXN=110;
// int mp[MAXN][MAXN],dp[MAXN][MAXN];
// int x[]={-1,1,0,0};
// int y[]={0,0,-1,1};
// int main(){
//     int r,c;
//     cin>>r>>c;
//     for(int i=1;i<=r;i++){
//         for(int j=1;j<=c;j++){
//             cin>>mp[i][j];
//             dp[i][j]=1;
//         }
//     }
//     int ans=-1,u=-1,v=-1;
//     for(int i=1;i<=r;i++){
//         for(int j=1;j<=c;j++){
//             for(int k=0;k<4;k++){
//                 int xx=i+x[k],yy=j+y[k];
//                 if(xx>=1&&xx<=r&&yy>=1&&yy<=r){
//                     if(mp[i][j]>mp[xx][yy]&&dp[i][j]<dp[xx][yy]+1){
//                         dp[i][j]=dp[xx][yy]+1;
//                         if(dp[i][j]>ans){
//                             ans=dp[i][j];
//                             u=i;
//                             v=j;
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     cout<<u<<" "<<v;
//     system("pause");
//     return 0;
// }

/*
#include<bits/stdc++.h>
using namespace std;
struct node{
    int ns;
    int nr;
    int nc;
};
int nR;
int nC;
int grids[101][101];
node dp[10010];
int nsp=1;
int compare(const void* p1, const void* p2){
    node *q1=(node*) p1;
    node *q2=(node*) p2;
    if(grids[q1->nr][q1->nc]<grids[q2->nr][q2->nc]) return -1;
    if(grids[q1->nr][q1->nc]>grids[q2->nr][q2->nc]) return 1;
    else return 0; 
}
int main(){
    cin>>nR>>nC;
    int k=0;
    for(int i=0;i<nR;i++){
        for(int j=0;j<nC;j++){
            cin>>grids[i][j];
            dp[k].ns=1;
            dp[k].nr=i;
            dp[k].nc=j;
            k++;
        }
    }
    qsort(dp,k,sizeof(node),compare);
    for(int i=1;i<k;i++){
        int r1=dp[i].nr;
        int c1=dp[i].nc;
        for(int j=0;j<i;j++){
            int r2=dp[j].nr;
            int c2=dp[j].nc;
            if(r1==r2&&c1==c2+1||r1==r2&&c1==c2-1||c1==c2&&r1==r2-1||c1==c2&&r1==r2+1){
                if(dp[i].ns<dp[j].ns+1){
                    dp[i].ns=dp[j].ns+1;
                    nsp=nsp>dp[i].ns?nsp:dp[i].ns;
                }
            }
        }
    }
    cout<<nsp<<endl;
    system("pause");
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
struct node{int ns,nr,nc;};int nR;int nC;int grids[101][101];node dp[10010];int nsp=1;int compare(const void* p1, const void* p2){node *q1=(node*) p1;node *q2=(node*) p2;if(grids[q1->nr][q1->nc]<grids[q2->nr][q2->nc])return -1;if(grids[q1->nr][q1->nc]>grids[q2->nr][q2->nc])return 1;else return 0;}int main(){cin>>nR>>nC;int k=0;for(int i=0;i<nR;i++){for(int j=0;j<nC;j++){cin>>grids[i][j];dp[k].ns=1;dp[k].nr=i;dp[k].nc=j;k++;}}qsort(dp,k,sizeof(node),compare);for(int i=1;i<k;i++){int r1=dp[i].nr;int c1=dp[i].nc;for(int j=0;j<i;j++){int r2=dp[j].nr;int c2=dp[j].nc;if(r1==r2&&c1==c2+1||r1==r2&&c1==c2-1||c1==c2&&r1==r2-1||c1==c2&&r1==r2+1){if(dp[i].ns<dp[j].ns+1){dp[i].ns=dp[j].ns+1;nsp=nsp>dp[i].ns?nsp:dp[i].ns;}}}}cout<<nsp<<endl;system("pause");}