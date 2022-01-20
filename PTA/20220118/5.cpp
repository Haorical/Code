#include<bits/stdc++.h>
using namespace std;
long long check(long long a){
    int cnt=0;
    while(a){
        int t=a%10;
        if(t==1) cnt++;
        else return 0;
        a/=10;
    }
    return cnt;
}
int main(){
    int x;
    cin>>x;
    long long i;
    for(i=0;;i++){
        int tmp=check(i*x);
        if(tmp){
            cout<<i<<" "<<tmp;
            break;
        }
    }
    system("pause");
    return 0;
}