#include<bits/stdc++.h>
using namespace std;
const int N=110;
int a[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int m=0,end=0,ans=0;
    for(int i=0;i<n-1;i++){
        if(m>=i){ 
            m=max(m,a[i]+i); // m 从第i个位置出发能走到最远距离
            if(i==end){ 
                end=m; //end 存储m
                ans++;
            }
        }
    }
    cout<<ans;
    system("pause");
    return 0;
}