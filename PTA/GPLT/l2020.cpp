// 并查集变形？
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int s[N];
int height[N];
int finds(int x){
    if(x==0) return 0;
    if(height[x]==0) height[x]=finds(s[x])+1; //记忆化搜索，没有的话，最后一个点会超时
    return height[x];
}
int main(){
    int n;
    double z,r;
    cin>>n>>z>>r;
    int k,t;
    double ans=0;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k==0){
            cin>>t;
            int sh=finds(i);
            double d=z*pow(1-r/100,sh)*t;
            ans+=d;
        } 
        else{
            for(int j=0;j<k;j++){
                cin>>t;
                s[t]=i;
            }
        }
    }
    cout<<int(ans);
    system("pause");
    return 0;
}