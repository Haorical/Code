#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int cnt=0;
        while(1){
            if(n==0||m==0){
                cout<<cnt<<endl;
                break;
            }
            if(n>=m){
                cnt+=n/m;
                n=n%m;
            }
            else{
                cnt+=m/n;
                m=m%n;
            };
            //cnt++;
        }
    }
    system("pause");
    return 0;
}