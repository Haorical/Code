#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[6];
    cin>>s;
    int x=0;
    for(int i=0;i<5;i++){
        if(i==2) continue;
        x=x*10+s[i]-'0';
    }
    //cout<<x;
    if(x>=0&&x<=1200){
        printf("Only %s.  Too early to Dang.",s);
        return 0;
    }
    x-=1200;
    int cnt=0;
    cnt=x/100+bool(x%100);
    for(int i=0;i<cnt;i++){
        cout<<"Dang";
    }
    system("pause");
    return 0;
}