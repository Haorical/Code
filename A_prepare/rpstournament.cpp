#include<bits/stdc++.h>
using namespace std;
#define mm(a) memset(a,0,sizeof(a))
int i,j,n,k;
string s;
int t=0;
int win[105]={0};
int loss[105]={0};
int main(){
    while(1){
        scanf("%d%d",&n,&k);
        if(n==0) break;
        mm(win),mm(loss);
        if(t++) printf("\n");
        for(i=0;i<k*n*(n-1)/2;i++){
            int p1=0,p2=0;
            char s1[10]={0},s2[10]={0};
            scanf("%d %s %d %s",&p1,s1,&p2,s2);
            if(s1[0]==s2[0]) continue;
            else if(s1[0]=='r'&&s2[0]=='s' || s1[0]=='s'&&s2[0]=='p' ||s1[0]=='p'&&s2[0]=='r'){
                win[p1]++;
                loss[p2]++;
            }else{
                win[p2]++;
                loss[p1]++;
            }
        }
        for(int i=1;i<=n;i++){
            if(win[i]+loss[i]) {
                //cout<<win[i]<<" "<<loss[i]<<endl;
                printf("%.3f\n",1.0*win[i]/(win[i]+loss[i]));
            }
            else printf("-\n");
        }
    }
    system("pause");
    return 0;
}