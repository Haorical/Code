// 考虑到系数为0的情况，不能直接用set求k
// 小数点后一位
#include<bits/stdc++.h>
using namespace std;
double a[20010];
int main(){
    memset(a,0,sizeof(a));
    int k1,k2;
    cin>>k1;
    for(int i=0;i<k1;i++){
        int e;
        double c;
        cin>>e>>c;
        a[e]+=c;
    }
    cin>>k2;
    for(int i=0;i<k2;i++){
        int e;
        double c;
        cin>>e>>c;
        a[e]+=c;
    }
    int cnt=0;
    for(int i=1000;i>=0;i--){
        if(a[i]!=0){
            cnt++;
        }
    }
    cout<<cnt;
    for(int i=1000;i>=0;i--){
        if(a[i]!=0){
            printf(" %d %.1f",i,a[i]);
        }
    }
    system("pause");
    return 0;
}

