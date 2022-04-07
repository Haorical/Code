#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,cnt=0,r=0,cn=0;
    cin>>n;
    int tmp=n;
    cnt=n;
    while(tmp){
        cn=0;
        if(tmp==2){
            cnt++;
            cout<<cnt<<endl;
            system("pause");
            return 0;
        }else if(tmp==1){
            cout<<cnt<<endl;
            system("pause");
            return 0;
        };
        cn=tmp/3;
        r=tmp%3;
        tmp=r+cn;
        cnt+=cn;
    }
    return 0;
}