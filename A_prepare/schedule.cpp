#include<bits/stdc++.h>
#define ll long long 
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
multiset<int>s;multiset<int>::iterator it;pair<int,int>a[100010];int main(){int T,N,K;ll ans;scanf("%d",&T);while(T--){scanf("%d",&N);K=0;ans=0;s.clear();rep(i,1,N)scanf("%d%d",&a[i].first,&a[i].second);sort(a+1,a+N+1);rep(i,1,N){if(s.empty()||(*s.begin())>a[i].first){s.insert(a[i].second);K++;ans-=a[i].first;}else{it=s.upper_bound(a[i].first);it--;s.erase(it);s.insert(a[i].second);}}for(it=s.begin();it!=s.end();it++)ans+=(*it);printf("%d %lld\n",K,ans);}}