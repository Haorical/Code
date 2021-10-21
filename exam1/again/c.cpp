#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> a;
int cnt[12][100002];//用vector有问题，直接开数组又没问题了
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a.push_back(tmp);
    }
    for(int i=0;i<n;i++){
        ll t=a[i]%m;
        for(int j=0;j<11;j++){
            cnt[j][t]++;
            t=t*10%m;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll t=a[i]%m;
        int len=to_string(a[i]).size();
        ans+=cnt[len][(m-t)%m];
        ll r=t;
        while (len--)
        {
            r=r*10%m;
        }
        if(r==(m-t)%m) ans--;
    }
    cout<<ans;
    system("pause");
    return 0;
}