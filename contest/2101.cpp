#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fastpow(ll n,ll m){
    ll ans=1%100000007;
    while(m)
    {
        if (m&1)
            ans=ans*n%100000007;
        n=n*n%100000007;
        m>>=1;
    }
    return (ans%100000007);
}
int main(){
	int m;
	while(cin>>m){
		ll res=1;
		for(int i=1;i<=m;i++){
			ll t = fastpow(i,i)%100000007;
			res=(res+t)%100000007;
		}
		cout<<res%100000007<<endl;
	}
}