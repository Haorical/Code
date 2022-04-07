#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,sum=0,suma=0;
    cin>>n;
    // int a1=n/160;
    int x=n,y=0;
    // sum+=a1;
    // int a2=a1/10*3;
    // while(a2>=5){
    //     a2-=5;
    //     sum++;
    //     suma++;
    //     if(suma==10){
    //         a2+=3;
    //         suma=0;
    //     }
    // }
    int sumk=0;
    while(x>=160||y>=5||sumk>=10){
        if(sumk==10){
            y+=3;
            sumk=0;
        }
        if(y>=5){
            y-=5;
            sum+=1;
            sumk+=1;
        }
        if(x>=160){
            x-=160;
            sum+=1;
            sumk+=1;
        }
    }
    cout<<x<<" "<<y<<" "<<sumk<<endl;
    // if(a2*32+n%160>=160){
    //     sum+=1;
    // }
    cout<<sum;
    system("pause");
    return 0;
}