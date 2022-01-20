#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        char s;
        cin>>s;
        double t,tmp;
        if(s=='F'){
            cin>>tmp;
            t=1.0*1.09*tmp;
            printf("%.2f",t);
        }else{
            cin>>tmp;
            t=1.0*tmp/1.09;
            printf("%.2f",t);
        }
        if(n>=1)
            cout<<endl;
    }
    system("pause");
    return 0;
}