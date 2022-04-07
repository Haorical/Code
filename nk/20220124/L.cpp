#include<bits/stdc++.h>
using namespace std;
double dis(int x,int y){
    return sqrt(x*x+y*y);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        double mx=0.0;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='U'){
                y++;
            }else if(c=='D'){
                y--;
            }else if(c=='L'){
                x--;
            }else if(c=='R'){
                x++;
            }
            mx = max(dis(x,y),mx);
        }
        cout<<mx<<endl;
    }
    system("pause");
}