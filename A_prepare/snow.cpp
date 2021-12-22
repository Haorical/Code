#include<bits/stdc++.h>
using namespace std;
struct stDP{
    int nSteps;
    int nRow;
    int nCol;
};
int nR;
int nC;
int grids[101][101];
stDP dp[10010];
int nMaxSteps=1;
int compare(const void* p1, const void* p2){
    stDP *q1=(stDP*) p1;
    stDP *q2=(stDP*) p2;
    if(grids[q1->nRow][q1->nCol]<grids[q2->nRow][q2->nCol]) return -1;
    if(grids[q1->nRow][q1->nCol]>grids[q2->nRow][q2->nCol]) return 1;
    else return 0; 
}
int main(){
    cin>>nR>>nC;
    int k=0;
    for(int i=0;i<nR;i++){
        for(int j=0;j<nC;j++){
            cin>>grids[i][j];
            dp[k].nSteps=1;
            dp[k].nRow=i;
            dp[k].nCol=j;
            k++;
        }
    }
    qsort(dp,k,sizeof(stDP),compare);
    for(int i=1;i<k;i++){
        int r1=dp[i].nRow;
        int c1=dp[i].nCol;
        for(int j=0;j<i;j++){
            int r2=dp[j].nRow;
            int c2=dp[j].nCol;
            if(r1==r2&&c1==c2+1||r1==r2&&c1==c2-1||c1==c2&&r1==r2-1||c1==c2&&r1==r2+1){
                if(dp[i].nSteps<dp[j].nSteps+1){
                    dp[i].nSteps=dp[j].nSteps+1;
                    nMaxSteps=nMaxSteps>dp[i].nSteps?nMaxSteps:dp[i].nSteps;
                }
            }
        }
    }
    cout<<nMaxSteps<<endl;
    system("pause");
    return 0;
}