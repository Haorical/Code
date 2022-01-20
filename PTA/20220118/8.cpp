#include<bits/stdc++.h>
using namespace std;
int m[1000][1000],n[1000][1000],r[1000][1000];
int main(){
    int a,b,c,d;
    cin>>a>>b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin>>m[i][j];
        }
    }
    cin>>c>>d;
    if(b!=c){
        printf("Error: %d != %d",b,c);
        return 0;
    }
    for(int i=0;i<c;i++){
        for(int j=0;j<d;j++){
            cin>>n[i][j];
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<b;k++){
                r[i][j]+=m[i][k]*n[k][j];
            }
        }
    }
    cout<<a<<" "<<d<<endl;
    for(int i=0;i<a;i++){
        for(int j=0;j<d;j++){
            cout<<r[i][j];
            if(j<d-1) cout<<" ";
        }
        if(i<a-1)
        cout<<endl;
    }
    return 0;
}