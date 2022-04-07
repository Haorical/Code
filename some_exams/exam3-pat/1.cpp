#include<bits/stdc++.h>
using namespace std;
#define int long long
bool isOdd(int x){
    if(abs(x)%2==0) return true;
    return false;
}
bool isN(int x){
    if(x>=0) return true;
    return false;
}
signed main(){
    int n;
    cin>>n;
    if(abs(n)==0){
        cout<<0;
        system("pause");
        return 0;
    }
    int t=(n>0?n:-n);
    int cnt=0;
    while(t){
        if(t%10==2) cnt++;
        //cout<<cnt<<endl;
        t/=10;
    }
    int w=log10(abs(n))+1;
    double sum=0.0;
    //cout<<cnt<<" "<<w<<endl;
    sum=1.0*cnt/w;
    if(!isN(n)) sum*=1.5;
    //cout<<sum<<endl;
    if(isOdd(n)) sum*=2.0;
    //cout<<sum<<endl;
    printf("%.2f%%",sum*100);
    system("pause");
    return 0;

}