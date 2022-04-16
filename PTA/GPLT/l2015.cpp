// 简单模拟
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int a[N];
int n,k,m;
int main(){
    cin>>n>>k>>m;
    for(int i=0;i<n;i++){
        int t1=100,t2=0,t;
        for(int j=0;j<k;j++){
            cin>>t;
            a[i]+=t;
            t1=min(t1,t);
            t2=max(t2,t);
        }
        a[i]-=(t1+t2); //天才做法
    }
    sort(a,a+n,greater<int>());
    for(int i=m-1;i>=0;i--){
        double d=1.0*a[i]/(k-2);
        printf("%.3f",d);
        if(i>0) cout<<' ';
    }
    system("pause");
    return 0;
}