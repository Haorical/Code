//思维题
#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int a[N],b[N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(a,a+n);
    int t,cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        t=a[i]-b[i];
        //cout<<t<<endl;
        if(t<0) cnt1++;
        else if(t>0) cnt2++;
    }
    t=max(cnt1,cnt2);
    cout<<t;
    system("pause");
    return 0;
}