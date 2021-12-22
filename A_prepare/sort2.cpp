#include<bits/stdc++.h>
using namespace std;
int a[1000002];
int main(){
    memset(a,0,sizeof(a));
    int n,m,tmp;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        a[500000+tmp]++;
    }
    for(int i=1000000;m>0;i--){
        while(a[i]){
            printf("%d ",i-500000);
            a[i]--;
            m--;
        }

    }
    system("pause");
    return 0;
}

//cin换成scanf