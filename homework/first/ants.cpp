#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int l,n,min,tmp,tmp0,max;
        cin>>l>>n>>min;
        max=(min<l-min)?(l-min):min;
        min=(min>l-min)?(l-min):min;
        for(int i =1;i<n;i++){
            cin>>tmp;
            tmp0=(tmp<l-tmp)?(l-tmp):tmp;
            if(tmp0>max) max=tmp0;
            tmp=(tmp>l-tmp)?(l-tmp):tmp;
            if(tmp>min) min=tmp;
        }
        cout<<min<<" "<<max<<endl;
    }
    system("pause");
    return 0;
}