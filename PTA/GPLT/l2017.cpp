// 思维题 sort会用就能过
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1); //注意是否是0开始
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    int aa,diff;
    if(n&1){
        aa=n/2;
        diff=a[n]-2*a[aa];
    }else{
        aa=n/2;
        diff=a[n]-2*a[aa];
        if(a[n]-2*a[aa+1]>diff){
            diff=a[n]-2*a[aa+1];
            aa++;
        }
    }
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d",n-aa,aa,diff);
    system("pause");
    return 0;
}