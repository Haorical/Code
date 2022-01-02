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
struct node{int ns,nr,nc;};int nR;int nC;int grids[101][101];node dp[10010];int nsp=1;int compare(const void* p1, const void* p2){node *q1=(node*) p1;node *q2=(node*) p2;if(grids[q1->nr][q1->nc]<grids[q2->nr][q2->nc])return -1;if(grids[q1->nr][q1->nc]>grids[q2->nr][q2->nc])return 1;else return 0;}int main(){cin>>nR>>nC;int k=0;for(int i=0;i<nR;i++){for(int j=0;j<nC;j++){cin>>grids[i][j];dp[k].ns=1;dp[k].nr=i;dp[k].nc=j;k++;}}qsort(dp,k,sizeof(node),compare);for(int i=1;i<k;i++){int r1=dp[i].nr;int c1=dp[i].nc;for(int j=0;j<i;j++){int r2=dp[j].nr;int c2=dp[j].nc;if(r1==r2&&c1==c2+1||r1==r2&&c1==c2-1||c1==c2&&r1==r2-1||c1==c2&&r1==r2+1){if(dp[i].ns<dp[j].ns+1){dp[i].ns=dp[j].ns+1;nsp=nsp>dp[i].ns?nsp:dp[i].ns;}}}}cout<<nsp<<endl;}