#include<bits/stdc++.h>
using namespace std;
bool u[10000001];
int su[5000000],num=0;
void prepare(){
    int i,j;
    memset(u,1,sizeof(u));
    for(i=2;i<=9999999;i++){
        if(u[i]) su[++num]=i;
        for(j=1;j<=num;j++){
            if(i*su[j]>10000000) break;
            u[i*su[j]]=0;
            if(i%su[j]==0) break;
        }
    }
}
int main(){
    prepare();
    int n,i,j,k;
    while(~scanf("%d",&n)){
        if(n==8){puts("2 2 2 2");continue;}
        if(n==9){puts("2 2 2 3");continue;}
        if(n==10){puts("2 2 3 3");continue;}
        if(n==11){puts("2 3 3 3");continue;}
        if(n==12){puts("3 3 3 3");continue;}
        if(n%2==0){
            printf("2 2 ");n-=4;
        }else{printf("2 3 ");n-=5;}
        for(i=1;i<=num;i++){
            if(su[i]*2>n) break;
            if(u[n-su[i]]){
                printf("%d %d\n",su[i],n-su[i]);
                break;
            }
        }
    }
    system("pause");
    return 0;
}