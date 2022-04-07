#include<bits/stdc++.h>
using namespace std;
int main(){
    double x,y,a;
    cin>>x>>y;
    a=x/(y*y);
    printf("%.1f\n",a);
    if(a>25.0){
        cout<<"PANG"<<endl;
    }else{
        cout<<"Hai Xing";
    }
    system("pause");
    return 0;
}