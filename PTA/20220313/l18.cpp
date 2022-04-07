#include<bits/stdc++.h>
using namespace std;
int m[1002];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int id,hh,mm,cnt1=0,cnt2=0;
        char flag;
        memset(m,-1,sizeof(m));
        while(scanf("%d %c %d:%d",&id,&flag,&hh,&mm)){
            if(id==0) break;
            if(flag=='E'&&m[id]!=-1){
                cnt1++;
                cnt2+=(hh*60+mm-m[id]);
            }else{
                m[id]=hh*60+mm;
            }
        }
        if(cnt1==0) puts("0 0");
        else{
            cout<<cnt1<<" "<<floor(1.0*cnt2/cnt1+0.51)<<endl;\
        }
    }
    system("pause");
    return 0;
}