#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int l,r;
bool vis[N]={false};
bool vis2[N]={false};//设置两个vis数组
vector<int> v[N];
bool isprime(int x){
    if(x==1) return false;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0) return false;
    }
    return true;
}
int f(int x){
    int ans=0;
    while(x){
        ans+=((x%10)*(x%10));
        x/=10;
    }
    return ans;
}
int judge(int x){
    int t=x;
    set<int> s;
    int pre;
    while(1){
        pre=s.size();
        s.insert(x);
        if(s.size()==pre) return false;
        if(x==1) return true;
        x=f(x);
        v[t].push_back(x);
        vis[x]=true; //被求出来的一定是不独立的，标记
    }
}
int main(){
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        vis2[i]=judge(i); //先全判断一边
    }
    int flag=0;
    for(int i=l;i<=r;i++){
        if(!vis[i]&&vis2[i]){
            flag=1;
            int len=v[i].size();
            cout<<i<<' '<<(isprime(i)?len*2:len)<<endl;
        }
    }
    if(!flag) cout<<"SAD";
    system("pause");
    return 0;
}