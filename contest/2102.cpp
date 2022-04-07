#include<bits/stdc++.h>
using namespace std;
int n,k;
int v[1000010];
int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v,v+n);
    cout<<v[k-1];
    system("pause");
    return 0;
}