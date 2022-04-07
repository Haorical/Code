#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        if(n==1||n==2){
            cout<<1<<endl;
            break;
        }
        n--;
        int a=1,b=1,c;
        while(n--){
            c=a+b;
            b=a;
            a=c;
        }
        cout<<c<<endl;
    }
    system("pause");
    return 0;
}