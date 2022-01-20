#include<bits/stdc++.h>
using namespace std;
int a[1002];
int main(){
    int n;
    cin>>n;
    while(n--){
        int k,t;
        cin>>k;
        for(int i=0;i<k;i++){
            cin>>t;
            a[t]++;
        }
    }
    int maxi=0,maxc=0;
    for(int i=1002;i>=0;i--){
        if(a[i]>maxc){
            maxc=a[i];
            maxi=i;
        }
    }
    cout<<maxi<<" "<<maxc;
    system("pause");
    return 0;
}