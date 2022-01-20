#include<bits/stdc++.h>
using namespace std;
set<int> s;
int check(int x,int y){
    int t1=x%10;
    int t2=(x/10)%10;
    int t3=(x/100)%10;
    int t4=(x/1000)%10;
    s.clear();
    s.insert(t1);
    s.insert(t2);
    s.insert(t3);
    s.insert(t4);
    if(y<1000){
        if(s.count(0)!=0){
            return s.size()-1;
        }
    }
    return s.size();
}
int main(){
    int y,n;
    cin>>y>>n;
    if(y<1000){
        n--;
        for(int i=y;i<=3000;i++){
            if(check(i,y)==n){
                printf("%d %04d",i-y,i);
                break;
            }
        }
    }else{
        for(int i=y;i<=3000;i++){
            if(check(i,y)==n){
                cout<<i-y<<" "<<i;
                break;
            }
        }
    }
    system("pause");
    return 0;
}